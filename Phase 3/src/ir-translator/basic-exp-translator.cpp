# include "../../include/ir-util.hpp"


void translate_EXP(Node *Exp, const string &reg) {
    TAC *tac = nullptr;
    switch (Exp->child.size()) {
        case 1: {
            if (Exp->child[0]->name == "INT") { // int
                tac = translate_exp_int(Exp);
            } else if (Exp->child[0]->name == "ID") {   // id
                tac = translate_exp_id(Exp);
            } else {
                cerr << "unexpected value: float or char !" << endl;
            }
            break;
        }
        case 2: {
            if (Exp->child[0]->name == "MINUS") {
//                translate_exp_minus();
            }
        }
        case 3: {
            break;
        }
    }
    if (tac != nullptr) {
        ir_tac.push_back(tac);
    }
}

TAC *translate_exp_int(Node *Exp) {
    string value = Exp->content;
    return new TAC(value, "", "", TAC_TYPE::ASSIGN);
}

TAC *translate_exp_id(Node *Exp) {
    Node *ID = Exp->child[0];
    if (ID->content == "READ") { //read函数特判
        TAC *read = new TAC(get_vital_register(), "", "", TAC_TYPE::ASSIGN);
        ir_tac.push_back(read);
    } else {
        // 暂时没想好要怎么处理
    }
}

TAC *translate_exp_minus(Node *Exp) {

}