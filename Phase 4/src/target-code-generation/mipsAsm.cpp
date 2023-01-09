#include "../../include/mipsAsm.hpp"
#include "../../include/ir-util.hpp"
#include "../../include/mipsAsmStrs.hpp"
#include <unordered_map>
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"

using namespace std;

static vector<vector<TAC *>> ircodes_vec;

inline static const string pre_build_data =

#include "preBuiltData.asm"

inline static const string pre_build_func =

#include "preBuiltFunc.asm"

inline static constexpr int32_t begin_sign = 0;

extern mipsAsm mips_asm;


void translate_to_mips32() {
    mips_asm.scan_symbolTable();
    mips_asm.outputDataAndText();
    mips_asm.output_intercodes();
}


void mipsAsm::outputDataAndText() {
    std::cout << pre_build_data << std::endl;
    for (const auto &vari_name: this->vari_names) {
        printf("_%s: .word 0\n", vari_name.c_str());
    }
    std::cout << pre_build_func << std::endl;
}

void mipsAsm::insert_vari(const std::string &str) {
    this->vari_names.insert(str);
}

void mipsAsm::scan_symbolTable() {
    for (const auto &[key, value]: symbolTable) {
        if (value->category == CATEGORY::PRIMITIVE &&
            value->foo.primitive == PRIM::INT) {
            this->insert_vari(key);
        }
    }
    const auto [temp_num, _] = new_temp_with_order();
    for (auto i = 0; i < temp_num - 1; ++i) {
        this->insert_vari(string("t").append(std::to_string(i)));
    }
}

static const unordered_map<TAC_TYPE, string> BioOpNodes = [] {
    static const unordered_map<TAC_TYPE, string> init{
            {TAC_TYPE::ADDITION,       "add"},
            {TAC_TYPE::SUBTRACTION,    "sub"},
            {TAC_TYPE::MULTIPLICATION, "mul"},
            {TAC_TYPE::DIVISION,       "div"},
    };
    return init;
}();

// 将第三阶段收集到的TAC按照函数的新式来分组，便捷下面的处理
void tac_vector_preprocess(vector<vector<TAC *>> &ircodes_vec_ref) {
    vector<TAC *> *current_tac_vec = nullptr;
    for (auto *tac: ir_tac) {
        if (tac->type == TAC_TYPE::FUNCTION) {
            if (current_tac_vec != nullptr) {
                ircodes_vec_ref.push_back(*current_tac_vec);
                //delete (current_tac_vec);
            }
            current_tac_vec = new vector<TAC *>;
            current_tac_vec->push_back(tac);
        } else {
            current_tac_vec->push_back(tac);
        }
    }
    if (current_tac_vec != nullptr) {
        ircodes_vec_ref.push_back(*current_tac_vec);
        //delete (current_tac_vec);
    }
}

void mipsAsm::output_intercodes() {
    // 先将IR根据Function划分
    tac_vector_preprocess(ircodes_vec);
    for (const auto &ircodes: ircodes_vec) {
        unordered_map<string, int32_t> param_to_reg{};
        const auto load_vari_to_register = [&param_to_reg](int32_t order, const string &operand) {
            // 操作数只有可能为 v# or #
            if (isNumber(operand)) {  // 是常数
                if (atoi(operand.c_str()) == 0) {
                    return string("move $t").append(std::to_string(order)).append(",$zero");
                }else{
                    // TODO: 这里存在漏洞
                    return string("move $t").append(std::to_string(order)).append(",$zero");
                }
            } else {  // 是临时param V#
                if (param_to_reg.count(operand) == 0) {
                    return string("lw   $t").append(std::to_string(order)).append(",_").append(operand);
                } else {
                    return string("move $t").append(std::to_string(order)).append(",$a")
                            .append(std::to_string(param_to_reg.at(operand)));
                }
            }
        };

        int order_of_a_regs = 0;
        vector<string> args;
        for (const auto *tac: ircodes) {
            switch (tac->type) {
                case TAC_TYPE::PARAM: {
                    // exp: v1X
                    this->insert_vari(tac->X);
                    if (param_to_reg.count(tac->X) == 0) {
                        param_to_reg[tac->X] = order_of_a_regs++;
                    }
                    break;
                }
                case TAC_TYPE::LABEL: {
                    // exp: label1
                    cout << tac->X << ":" << endl;
                    break;
                }
                case TAC_TYPE::FUNCTION: {
                    // exp: main
                    printf("%s:",tac->X.c_str());
                    //cout << TAC->X << ":" << endl;
                    cout << function_begin << endl << endl;
                    break;
                }
                case TAC_TYPE::ASSIGN: {
                    string left_op = tac->X;
                    string right_op = tac->Y;
                    if (right_op.find('#') != string::npos && isNumber(right_op.substr(1))) {  // 是常数
                        cout << "    li   $t0," << get_asm_str(right_op) << endl;
//                        printf("    li   $t0,%s\n", get_asm_str(right_op).c_str());
                    } else {  // 是临时param V#
                        cout << "    lw   $t0," << get_asm_str(right_op) << endl;
//                        printf("    lw   $t0,%s\n", get_asm_str(right_op).c_str());
                    }
                    cout << "    sw   $t0," << get_asm_str(left_op) << endl << endl;
//                    printf("    sw   $t0,%s\n\n", get_asm_str(left_op).c_str());
                    break;
                }
                case TAC_TYPE::ADDITION:
                case TAC_TYPE::MULTIPLICATION:
                case TAC_TYPE::SUBTRACTION:
                case TAC_TYPE::DIVISION: {
                    const string &bioOp_name = BioOpNodes.at(tac->type);
                    cout << "    " << load_vari_to_register(0, tac->Y) << endl;
                    cout << "    " << load_vari_to_register(1, tac->Z) << endl;
                    cout << "    " << bioOp_name << "  " << "$t2,$t0,$t1" << endl;
                    cout << "    sw   $t2," << get_asm_str(tac->X) << endl << endl;
//                    printf("    %s\n", load_vari_to_register(0, TAC->Y).c_str());
//                    printf("    %s\n", load_vari_to_register(1, TAC->Z).c_str());
//                    printf("    %s  $t2,$t0,$t1\n", bioOp_name.c_str());
//                    printf("    sw   $t2,%s\n\n", get_asm_str(TAC->X).c_str());
                    break;
                }
                case TAC_TYPE::RETURN: {
                    printf("%s\n", function_end);
                    printf("    %s\n", load_vari_to_register(0, tac->X).c_str());
                    static const string return_sentenct = R"(move $v0,$t0
    jr $ra)";
                    printf("    %s\n\n", return_sentenct.c_str());
                    break;
                }
                case TAC_TYPE::WRITE: {
                    printf("%s\n", write_begin);
                    printf("    lw   $t0,%s\n", get_asm_str(tac->X).c_str());
                    printf("%s\n\n", write_end);
                    break;
                }
                case TAC_TYPE::READ: {
                    printf("%s\n", read_begin);
                    printf("    sw   $t0,%s\n\n", get_asm_str(tac->X).c_str());
                    break;
                }
                case TAC_TYPE::GOTO: {
                    printf("    j %s\n\n", tac->X.c_str());
                    break;
                }
                case TAC_TYPE::CONDITION_EQ:
                case TAC_TYPE::CONDITION_GE:
                case TAC_TYPE::CONDITION_GT:
                case TAC_TYPE::CONDITION_LE:
                case TAC_TYPE::CONDITION_LT:
                case TAC_TYPE::CONDITION_NE: {
                    printf("    %s\n", load_vari_to_register(0, tac->X).c_str());
                    printf("    %s\n", load_vari_to_register(1, tac->Y).c_str());
                    static const unordered_map<TAC_TYPE, string> operandtoStr{
                            {TAC_TYPE::CONDITION_EQ, "blt"},
                            {TAC_TYPE::CONDITION_GE, "ble"},
                            {TAC_TYPE::CONDITION_GT, "bgt"},
                            {TAC_TYPE::CONDITION_LE, "bge"},
                            {TAC_TYPE::CONDITION_LT, "bne"},
                            {TAC_TYPE::CONDITION_NE, "beq"}
                    };
                    printf("    %s  $t0,$t1,%s\n\n",
                           operandtoStr.at(tac->type).c_str(),
                           get_asm_str(tac->Z).c_str()
                    );
                    break;
                }
                case TAC_TYPE::CALL: {
                    const auto call_sentences = caller(this->vari_names, args, param_to_reg);
                    printf("%s", call_sentences.first.c_str());
                    args.clear();
                    printf("    jal %s\n", tac->Y.c_str());
                    printf("%s", call_sentences.second.c_str());
                    printf("    sw $v0,_%s\n\n", tac->X.c_str());
                    break;
                }
                case TAC_TYPE::ARG: {
                    args.push_back(tac->X);
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}

std::pair<int, string> new_temp_with_order() {
    static int temp_value_temp = begin_sign;
    return {temp_value_temp, string("t").append(std::to_string(temp_value_temp++))};
}


string get_asm_str(const string &str) {
    if (str.find('#') != string::npos && isNumber(str.substr(1))) {    //constant
        return str.substr(1);
    }
    if (str.find('v') != string::npos || str.find("label") != string::npos) {   //variable || label
        return string("_").append(str);
    }
    return "Error";
}

#pragma clang diagnostic pop