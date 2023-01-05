# include "../../include/ir-util.hpp"


void translate_cond_Exp(Node *Exp, const string &label_t, const string &label_f) {
    if (Exp->child.size() == 2) {
        assert(Exp->child[0]->name == "NOT");
        translate_cond_Exp(Exp, label_f, label_t);
    }
    if (Exp->child.size() == 3) {
        string opt = Exp->child[1]->name;
        if (opt == "AND") {
            translate_cond_Exp_AND(Exp, label_t, label_f);
        } else if (opt == "OR") {
            translate_cond_Exp_OR(Exp, label_t, label_f);
        } else {
            translate_cond_Exp_Compares(Exp, label_t, label_f);
        }
    }
}

void translate_cond_Exp_AND(Node *Exp, const string &label_t, const string &label_f) {
    Node *Exp1 = Exp->child[0];
    Node *Exp2 = Exp->child[2];
    string lb1 = get_label();
    translate_cond_Exp(Exp1, lb1, label_f);
    ir_tac.push_back(new TAC(lb1, "", "", TAC_TYPE::LABEL));
    translate_cond_Exp(Exp2, label_t, label_f);
}

void translate_cond_Exp_OR(Node *Exp, const string &label_t, const string &label_f) {
    Node *Exp1 = Exp->child[0];
    Node *Exp2 = Exp->child[2];
    string lb1 = get_label();
    translate_cond_Exp(Exp1, label_t, lb1);
    ir_tac.push_back(new TAC(lb1, "", "", TAC_TYPE::LABEL));
    translate_cond_Exp(Exp2, label_t, label_f);
}

void translate_cond_Exp_Compares(Node *Exp, const string &label_t, const string &label_f) {
    Node *Exp1 = Exp->child[0];
    string opt = Exp->child[1]->name;
    Node *Exp2 = Exp->child[2];
    string reg1 = get_vital_register();
    string reg2 = get_vital_register();
    translate_basic_exp(Exp1, reg1);
    translate_basic_exp(Exp2, reg2);

    assert(opt == "LT" || opt == "LE" || opt == "GT" || opt == "GE" || opt == "NE" || opt == "EQ");

    TAC *code0;
    if (opt == "LT") {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_LT);
    } else if (opt == "LE") {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_LE);
    } else if (opt == "GT") {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_GT);
    } else if (opt == "GE") {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_GE);
    } else if (opt == "NE") {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_NE);
    } else {
        code0 = new TAC(reg1, reg2, label_t, TAC_TYPE::CONDITION_EQ);
    }

    assert(code0 != nullptr);

    ir_tac.push_back(code0);
    ir_tac.push_back(new TAC(label_f, "", "", TAC_TYPE::GOTO));
}