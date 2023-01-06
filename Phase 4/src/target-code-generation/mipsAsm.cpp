#include "../../include/mipsAsm.hpp"
#include "../../include/TAC.hpp"
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

void mipsAsm::add_intercodes(const vector<TAC *> &ircodes) {
    ircodes_vec.push_back(ircodes);
}

static const unordered_map<TAC_TYPE, string> BioOpNodes = [] {
    static const unordered_map<TAC_TYPE, string> init{
            {TAC_TYPE::ADDITION,       "add"},
            {TAC_TYPE::SUBTRACTION,    "sub"},
            {TAC_TYPE::MULTIPLICATION, "mul"},
    };
    return init;
}();

void mipsAsm::output_intercodes() {
//    for (const auto &ircodes: ircodes_vec) {
//        unordered_map<string, int32_t> param_to_reg{};
//        const auto load_vari_to_register = [&param_to_reg](int32_t order, Operand *operand) {
//            switch (operand->operandEnum) {
//                case OperandType::VARIABLE: {
//                    if (param_to_reg.count(operand->variName) == 0) {
//                        return string("lw   $t").append(std::to_string(order)).append(",_").append(operand->variName);
//                    } else {
//                        return string("move $t").append(std::to_string(order)).append(",$a")
//                                .append(std::to_string(param_to_reg.at(operand->variName)));
//                    }
//                }
//                case OperandType::CONSTANT: {
//                    if (operand->value == 0) {
//                        return string("move $t").append(std::to_string(order)).append(",$zero");
//                    }
//                }
//                default: {
//                    return string("Error");
//                }
//            }
//        };
//        int order_of_a_regs = 0;
//        vector<string> args;
//        for (const auto &ircode: ircodes) {
//            switch (ircode->type) {
//                case TAC_TYPE::PARAM: {
//                    this->insert_vari(ircode->SingleElement->variName);
//                    if (param_to_reg.count(ircode->SingleElement->variName) == 0) {
//                        param_to_reg[ircode->SingleElement->variName] = order_of_a_regs++;
//                    }
//                    break;
//                }
//                case TAC_TYPE::LABEL: {
//                    printf("%s:\n", ircode->labelElement->jumpLabel.c_str());
//                    break;
//                }
//                case TAC_TYPE::FUNCTION: {
//                    printf("%s:\n", ircode->labelElement->jumpLabel.c_str());
//                    printf("%s\n\n", function_begin);
//                    break;
//                }
//                case TAC_TYPE::ASSIGN: {
//                    switch (ircode->assign.right->operandEnum) {
//                        case OperandType::CONSTANT : {
//                            printf("    li   $t0,%s\n", ircode->assign.right->get_asm_str().c_str());
//                            break;
//                        }
//                        case OperandType::VARIABLE: {
//                            printf("    lw   $t0,%s\n", ircode->assign.right->get_asm_str().c_str());
//                            break;
//                        }
//                        default: {
//                            break;
//                        }
//                    }
//                    printf("    sw   $t0,%s\n\n", ircode->assign.left->get_asm_str().c_str());
//                    break;
//                }
//                case TAC_TYPE::ADDITION:
//                case TAC_TYPE::MULTIPLICATION:
//                case TAC_TYPE::SUBTRACTION: {
//                    const string &bioOp_name = BioOpNodes.at(ircode->interCodeType);
//                    printf("    %s\n", load_vari_to_register(0, ircode->bioOp.op1).c_str());
//                    printf("    %s\n", load_vari_to_register(1, ircode->bioOp.op2).c_str());
//                    printf("    %s  $t2,$t0,$t1\n", bioOp_name.c_str());
//                    printf("    sw   $t2,%s\n\n", ircode->bioOp.result->get_asm_str().c_str());
//                    break;
//                }
//                case TAC_TYPE::RETURN: {
//                    printf("%s\n", function_end);
//                    printf("    %s\n", load_vari_to_register(0, ircode->SingleElement).c_str());
//                    static const string return_sentenct = R"(move $v0,$t0
//    jr $ra)";
//                    printf("    %s\n\n", return_sentenct.c_str());
//                    break;
//                }
//                case TAC_TYPE::WRITE: {
//                    printf("%s\n", write_begin);
//                    printf("    lw   $t0,%s\n", ircode->SingleElement->get_asm_str().c_str());
//                    printf("%s\n\n", write_end);
//                    break;
//                }
//                case TAC_TYPE::READ: {
//                    printf("%s\n", read_begin);
//                    printf("    sw   $t0,%s\n\n", ircode->SingleElement->get_asm_str().c_str());
//                    break;
//                }
//                case TAC_TYPE::GOTO: {
//                    printf("    j %s\n\n", ircode->labelElement->jumpLabel.c_str());
//                    break;
//                }
//                case TAC_TYPE::IF_ELSE: {
//                    printf("    %s\n", load_vari_to_register(0, ircode->ifElse.left).c_str());
//                    printf("    %s\n", load_vari_to_register(1, ircode->ifElse.right).c_str());
//                    static const unordered_map<string, string> operandtoStr{
//                            {"<",  "blt"},
//                            {"<=", "ble"},
//                            {">",  "bgt"},
//                            {">=", "bge"},
//                            {"!=", "bne"},
//                            {"==", "beq"}
//                    };
//                    printf("    %s  $t0,$t1,%s\n\n",
//                           operandtoStr.at(ircode->ifElse.operation->variName).c_str(),
//                           ircode->ifElse.if_label->variName.c_str()
//                    );
//                    break;
//                }
//                case TAC_TYPE::CALL: {
//                    const auto call_sentences = caller(this->vari_names, args, param_to_reg);
//                    printf("%s", call_sentences.first.c_str());
//                    args.clear();
//                    printf("    jal %s\n", ircode->assign.right->variName.c_str());
//                    printf("%s", call_sentences.second.c_str());
//                    printf("    sw $v0,_%s\n\n", ircode->assign.left->variName.c_str());
//                    break;
//                }
//                case TAC_TYPE::ARG: {
//                    args.push_back(ircode->SingleElement->variName);
//                    break;
//                }
//                default: {
//                    break;
//                }
//            }
//        }
//    }
}

std::pair<int, string> new_temp_with_order() {
    static int temp_value_temp = begin_sign;
    return {temp_value_temp, string("t").append(std::to_string(temp_value_temp++))};
}

static string new_temp() {
    const auto &[value, will_return] = new_temp_with_order();
    return will_return;
}

#pragma clang diagnostic pop