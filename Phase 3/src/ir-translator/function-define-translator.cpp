# include "../../include/ir-util.hpp"


void translate_func_dec(Node *CompFunDec) {
    if (CompFunDec->name != "CompFunDec") {
        cerr << "Error! The input Node is not CompFunDec!" << endl;
        cerr << "Error! The input Node is " << CompFunDec->name << " ! " << endl;
        return;
    }
    Node *FunDec = CompFunDec->child[1];
    Node *ID = FunDec->child[0];

    ///@berief: 生成Function TAC
    ir_tac.push_back(new TAC(ID->content, "", "", TAC_TYPE::FUNCTION));

    if (FunDec->child.size() == 3) {  //无参
        return;
    } else {  //有参
        Node *VarList = FunDec->child[2];
        translate_func_varlist(VarList);
    }
}

void translate_func_varlist(Node *VarList) {
    vector<Node *> ParamDecVector;
    while (VarList->child.size() != 1) {
        ParamDecVector.push_back(VarList->child[0]);
    }
    ParamDecVector.push_back(VarList->child[0]);
    for (int i = 0; i < ParamDecVector.size(); ++i) {
        ///@berief: 生成Param TAC
        ir_tac.push_back(new TAC(get_vital_register(), "", "", TAC_TYPE::PARAM));
    }
}