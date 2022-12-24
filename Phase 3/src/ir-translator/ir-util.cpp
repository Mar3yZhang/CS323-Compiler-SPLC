
#include <utility>

#include "../../include/ir-util.hpp"

using namespace std;


// 寄存器和label的管理需要优化
//set<int> v_regs;
//set<int> t_regs;
//set<int> labels;

int v_regs = 1;
int t_regs = 1;
int labels = 1;


TAC::TAC(const string &X, const string &Y, const string &Z, TAC_TYPE type)
        : X(std::move(preprocess_operand(X))),
          Y(std::move(preprocess_operand(Y))),
          Z(std::move(preprocess_operand(Z))),
          type(type) {}

string TAC::preprocess_operand(const string &str) {
    return isNumber(str) ? ("#" + str) : str;
}


void TAC::print() const {
    cout << "---------------------------------------" << endl;
    cout << this << endl;
}

bool isNumber(const string &str) {
    for (char const &c: str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}


void translate_to_tac() {
    Node *Program = root_node;
    Node *ExtDefList = Program->child[0];
    for (auto *ExtDef: list_to_vector(ExtDefList)) {
        Node *Specifier = ExtDef->child[0];
        Node *FunDec = ExtDef->child[1];
        Node *CompSt = ExtDef->child[2];
        Node *CompFunDec = new Node(Node_Type::NOTHING, "CompFunDec", "", FunDec->line_num);
        CompFunDec->child.push_back(Specifier);
        CompFunDec->child.push_back(FunDec);
        translate_func_dec(CompFunDec);
        translate_compst(CompSt);
    }
}

void print_tac_ir() {
    cout << ir_tac.size() << " TAC in total !" << endl;
    for (auto *temp: ir_tac) {
        temp->print();
    }
}

vector<Node *> list_to_vector(Node *List) {
    vector<Node *> result;
    while (!List->child.empty()) {
        result.push_back(List->child[0]);
        List = List->child[1];
    }
    return result;
}

// 这里的返回寄存器操作需要优化
string get_vital_register() {
    string reg = "v" + to_string(v_regs);
    v_regs++;
    return reg;
}

///TODO:之后再考虑优化
//string get_vital_register(int content) {
//    if (reg_has_int(content)) { // 当前数值不存在于任何一个寄存器
//        return int_reg_mapper[content];
//    } else {
//        string reg = get_vital_register();
//        int_reg_mapper[content] = reg;
//        return reg;
//    }
//}

/// 存在存有整数int的寄存器：
//bool reg_has_int(int content) {
//    return int_reg_mapper.count(content) != 0;
//}

string get_label() {
    string reg = "label" + to_string(labels);
    labels++;
    return reg;
}


std::ostream &operator<<(std::ostream &lhs, const TAC *tac) {
    switch (tac->type) {
        case TAC_TYPE::ADDITION:
            lhs << tac->X << " := " << tac->Y << " + " << tac->Z;
            lhs << "ADDITION";
            break;
        case TAC_TYPE::LABEL:
            lhs << "LABEL " << tac->X << " :";
            break;
        case TAC_TYPE::FUNCTION:
            lhs << "FUNCTION " << tac->X << " :";
            break;
        case TAC_TYPE::ASSIGN:
            lhs << tac->X << " := " << tac->Y;
            break;
        case TAC_TYPE::SUBTRACTION:
            lhs << tac->X << " := " << tac->Y << " - " << tac->Z;
            break;
        case TAC_TYPE::MULTIPLICATION:
            lhs << tac->X << " := " << tac->Y << " * " << tac->Z;
            break;
        case TAC_TYPE::DIVISION:
            lhs << tac->X << " := " << tac->Y << " / " << tac->Z;
            break;
        case TAC_TYPE::GOTO:
            lhs << "GOTO " << tac->X;
            break;
        case TAC_TYPE::RETURN:
            lhs << "RETURN " << tac->X;
            break;
        case TAC_TYPE::PARAM:
            lhs << "PARAM " << tac->X;
            break;
        case TAC_TYPE::ARG:
            lhs << "ARG " << tac->X;
            break;
        case TAC_TYPE::CALL:
            lhs << tac->X << " := CALL " << tac->Y;
            break;
        case TAC_TYPE::READ:
            lhs << "READ " << tac->X;
            break;
        case TAC_TYPE::WRITE:
            lhs << "WRITE " << tac->X;
            break;
        case TAC_TYPE::CONDITION_LT:
            lhs << "IF " << tac->X << " < " << tac->Y << " GOTO " << tac->Z;
            break;
        case TAC_TYPE::CONDITION_LE:
            lhs << "IF " << tac->X << " <= " << tac->Y << " GOTO " << tac->Z;
            break;
        case TAC_TYPE::CONDITION_GT:
            lhs << "IF " << tac->X << " > " << tac->Y << " GOTO " << tac->Z;
            break;
        case TAC_TYPE::CONDITION_GE:
            lhs << "IF " << tac->X << " >= " << tac->Y << " GOTO " << tac->Z;
            break;
        case TAC_TYPE::CONDITION_NE:
            lhs << "IF " << tac->X << " != " << tac->Y << " GOTO " << tac->Z;
            break;
        case TAC_TYPE::CONDITION_EQ:
            lhs << "IF " << tac->X << " == " << tac->Y << " GOTO " << tac->Z;
            break;
    }
    return lhs;
}


