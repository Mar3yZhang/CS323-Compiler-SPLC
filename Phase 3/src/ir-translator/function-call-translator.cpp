# include "../../include/ir-util.hpp"

void translate_exp_func(Node *Exp, const string &reg) {
    assert(Exp->name == "Exp");
    assert(Exp->child[0]->name == "ID");
    Node *ID = Exp->child[0];

    if (ID->content == "read") {    // read LP RP
        translate_exp_func_read(reg);
    } else if (ID->content == "write") {    // write LP Exp RP
        translate_exp_func_write(Exp, reg);
    } else {    // ID LP RP & ID LP Args RP
        Type *function = symbolTable[ID->content];
        if (Exp->child.size() > 3) {
            assert(Exp->child[2]->name == "Args");
            vector<string> argList;
            Node *Args = Exp->child[2];
            translate_args(Args, argList);
            for (int i = 1; i <= argList.size(); ++i) {
                ir_tac.push_back(new TAC(argList[argList.size() - i], "", "", TAC_TYPE::ARG));
            }
        }
        ///@berief: 生成Function TAC
        ir_tac.push_back(new TAC(reg, function->name, "", TAC_TYPE::CALL));
    }
}

void translate_exp_func_read(const string &reg) {
    ir_tac.push_back(new TAC(reg, "", "", TAC_TYPE::READ));
}

void translate_exp_func_write(Node *Exp, const string &reg) {
    string tp = get_vital_register();
    Node *Args = Exp->child[2];
    Node *Exp1 = Args->child[0];
    assert(Exp1->name == "Exp");
    translate_basic_exp(Exp1, tp);
    ir_tac.push_back(new TAC(tp, "", "", TAC_TYPE::WRITE));
}


void translate_args(Node *Args, vector<string> &argList) {
    if (Args->child.size() == 1) {
        translate_args_exp(Args, argList);
    } else {
        translate_args_exp_comma_args(Args, argList);
    }
}

void translate_args_exp(Node *Args, vector<string> &argList) {
    Node *Exp = Args->child[0];
    assert(Exp->name == "Exp");
    string reg = get_vital_register();
    translate_basic_exp(Exp, reg);
    argList.push_back(reg);
}

void translate_args_exp_comma_args(Node *Args, vector<string> &argList) {
    Node *Exp = Args->child[0];
    assert(Exp->name == "Exp");
    string reg = get_vital_register();
    translate_basic_exp(Exp, reg);
    argList.push_back(reg);
    translate_args(Args, argList);
}