
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


TAC::TAC(string X, string Y, string Z, TAC_TYPE type)
        : X(std::move(X)), Y(std::move(Y)), Z(std::move(Z)), type(type) {}

void TAC::print() const {
    cout << "---------------------------------------" << endl;
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;
    cout << "Z: " << Z << endl;
    cout << "Type: " << type << endl;
}


void translate_to_tac() {
    Node *Program = root_node;
    Node *ExtDefList = Program->child[0];
    for (auto *ExtDef: ExtDefList_to_vector(ExtDefList)) {
        Node *CompFunDec = ExtDef->child[0];
        Node *CompSt = ExtDef->child[1];

        translate_func_dec(CompFunDec);
    }
}

void print_tac_ir() {
    for (auto *temp: ir_tac) {
        temp->print();
    }
}

vector<Node *> ExtDefList_to_vector(Node *ExtDefList) {
    vector<Node *> result;

    //TODO:需要处理特判

    if (ExtDefList->name != "ExtDefList") {
        cerr << "Error! The input Node is not ExtDefList!" << endl;
        cerr << "Error! The input Node is " << ExtDefList->name << " !" << endl;
        return result;
    }
    while (!ExtDefList->child.empty()) {
        result.push_back(ExtDefList->child[0]);
        ExtDefList = ExtDefList->child[1];
    }
    return result;
}

// 这里的返回寄存器操作需要优化
string get_vital_register() {
    auto reg = "v" + to_string(v_regs);
    v_regs++;
    return reg;
}

string get_temp_register() {
    auto reg = "t" + to_string(t_regs);
    t_regs++;
    return reg;
}


std::ostream &operator<<(std::ostream &lhs, TAC_TYPE type) {
    switch (type) {
        case TAC_TYPE::ADDITION:
            lhs << "ADDITION";
            break;
        case TAC_TYPE::LABEL:
            lhs << "LABEL";
            break;
        case TAC_TYPE::FUNCTION:
            lhs << "FUNCTION";
            break;
        case TAC_TYPE::ASSIGN:
            lhs << "ASSIGN";
            break;
        case TAC_TYPE::SUBTRACTION:
            lhs << "SUBTRACTION";
            break;
        case TAC_TYPE::MULTIPLICATION:
            lhs << "MULTIPLICATION";
            break;
        case TAC_TYPE::DIVISION:
            lhs << "DIVISION";
            break;
        case TAC_TYPE::GOTO:
            lhs << "GOTO";
            break;
        case TAC_TYPE::CONDITION:
            lhs << "CONDITION";
            break;
        case TAC_TYPE::RETURN:
            lhs << "RETURN";
            break;
        case TAC_TYPE::PARAM:
            lhs << "PARAM";
            break;
        case TAC_TYPE::ARG:
            lhs << "ARG";
            break;
        case TAC_TYPE::CALL:
            lhs << "CALL";
            break;
        case TAC_TYPE::READ:
            lhs << "READ";
            break;
        case TAC_TYPE::WRITE:
            lhs << "WRITE";
            break;
    }
    return lhs;
}


