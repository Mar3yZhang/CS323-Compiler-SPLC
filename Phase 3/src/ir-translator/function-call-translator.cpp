# include "../../include/ir-util.hpp"

void translate_args(Node *Exp,vector<TAC*> argList) {
    
    Node *Exp1 = Exp->child[0];
    // TODO: 需要translate_exp(Exp,reg);来得知节点exp1值存在哪个reg
    //translate_exp(Exp,reg);
    argList.push_back(new TAC("exp_reg", "", "", TAC_TYPE::ARG));
    if (Exp->child.size() > 3) {
        translate_args(Exp1,argList);
    }
}

void translate_exp_func(Node *Exp,const string &reg) {
    if (Exp->name != "Exp") {
        cerr << "Error! The input Node is not Exp!" << endl;
        cerr << "Error! The input Node is " << Exp->name << " ! " << endl;
        return;
    }
    Node *ID = Exp->child[0];
    if (ID->content == "read") {

    } else if (ID->content == "write") {

    } else {
        Type *function = symbolTable[Exp->name];
        if (Exp->child.size() > 3) {
            vector<TAC*> argList;
            Node *Args = Exp->child[2];
            translate_args(Args,argList);
            for (int i = 1;i <= argList.size();++i) {
                ir_tac.push_back(argList[argList.size()-i]);
            }
        }
        ///@berief: 生成Function TAC
        ir_tac.push_back(new TAC(function->name, "", "", TAC_TYPE::CALL));
    }
}