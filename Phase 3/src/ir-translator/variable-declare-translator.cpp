# include "../../include/ir-util.hpp"


void translate_Def(Node *Def) {
    Node *DecList = Def->child[1];
    vector<Node *> dec_vector;
    while (DecList->child.size() != 1) {
        Node *Dec = DecList->child[0];
        dec_vector.push_back(Dec);
        DecList = DecList->child[2];
    }
    dec_vector.push_back(DecList->child[0]);
    for (auto *Dec: dec_vector) {
        translate_Dec(Dec);
    }
}


// 如果不涉及赋值，符号表的内容设置为INT_MIN

// TODO: 这里有BUG 使得第一个样例输出有问题
void translate_Dec(Node *Dec) {
    Node *VarDec = Dec->child[0];
    if (Dec->child.size() == 1) {   //Dec: VarDec
        if (VarDec->child.size() == 1) { // ID
//            Node *ID = VarDec->child[0];
//            assert(ID->name == "ID");
//            id_int_mapper[ID->content] = INT32_MIN;
        } else { //  VarDec LB INT RB
            // TODO: 这里如果考虑数组需要补充逻辑
        }
    } else {    //Dec: VarDec ASSIGN Exp 不考虑数组时等效 Exp ASSIGN Exp
        // TODO: 这里如果考虑数组需要补充逻辑
        assert(Dec->child[1]->name == "ASSIGN");
        translate_exp_assign_exp(Dec, get_vital_register());
//        translate_basic_exp(Exp, get_vital_register());
//        if (VarDec->child.size() == 1) { // ID
//            Node *ID = VarDec->child[0];
//            assert(ID->name == "ID");
//            id_int_mapper[ID->content] = exp_value;
//            string reg = int_reg_mapper[exp_value];
//            TAC *tac = new TAC(get_vital_register(exp_value), reg, "", TAC_TYPE::ASSIGN);
//            ir_tac.push_back(tac);
//        }
//        else{ //  VarDec LB INT RB
//            // TODO: 这里如果考虑数组需要补充逻辑
//        }
    }
}