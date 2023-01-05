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
        VarList = VarList->child[2];
    }
    ParamDecVector.push_back(VarList->child[0]);
    for (auto *ParamDec: ParamDecVector) {
        ///@berief: 生成Param TAC
        Node *VarDec = ParamDec->child[1];
        Node *ID = VarDec->child[0];
        assert(ID->name == "ID");   //这里只考虑int
        string reg = get_vital_register();
        param_id_reg_mapper[ID->content] = reg;
        ir_tac.push_back(new TAC(reg, "", "", TAC_TYPE::PARAM));
    }
}