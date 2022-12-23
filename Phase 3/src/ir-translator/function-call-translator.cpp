# include "../../include/ir-util.hpp"

void translate_args(Node *Exp, vector<TAC *> argList) {
    /// TODO: 这里有处理arg和exp父子关系的bug，需要修复
    Node *Exp1 = Exp->child[0];
    /// TODO: 需要translate_exp(Exp,reg);来得知节点exp1值存在哪个reg FINISH BY ZQ
    string reg = get_vital_register();
    translate_basic_exp(Exp, reg);
    argList.push_back(new TAC(reg, "", "", TAC_TYPE::ARG));
    if (Exp->child.size() > 3) {
        translate_args(Exp1, argList);
    }
}

void translate_exp_func(Node *Exp, const string &reg) {
    assert(Exp->name == "Exp");
    assert(Exp->child[0]->name == "ID");
    Node *ID = Exp->child[0];

    if (ID->content == "read") {
        translate_exp_func_read(Exp, reg);
    } else if (ID->content == "write") {
        translate_exp_func_write(Exp,reg);
    } else {
        Type *function = symbolTable[Exp->name];
        if (Exp->child.size() > 3) {
            vector<TAC *> argList;
            Node *Args = Exp->child[2];
            translate_args(Args, argList);
            for (int i = 1; i <= argList.size(); ++i) {
                ir_tac.push_back(argList[argList.size() - i]);
            }
        }
        ///@berief: 生成Function TAC
        ir_tac.push_back(new TAC(function->name, "", "", TAC_TYPE::CALL));
    }
}

void translate_exp_func_read(Node *Exp, const string &reg) {
    ir_tac.push_back(new TAC(reg, "", "", TAC_TYPE::READ));
}

void translate_exp_func_write(Node *Exp, const string &reg) {
    string tp = get_vital_register();
    translate_basic_exp(Exp,tp);
    ir_tac.push_back(new TAC(tp, "", "", TAC_TYPE::WRITE));
}