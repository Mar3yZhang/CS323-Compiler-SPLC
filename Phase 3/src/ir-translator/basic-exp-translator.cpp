# include "../../include/ir-util.hpp"


/// @使用指定的寄存器来存储EXP的结果
void translate_basic_exp(Node *Exp, const string &reg) {
    switch (Exp->child.size()) {
        case 1: {
            if (Exp->child[0]->name == "INT") { // int
                translate_exp_int(Exp, reg);
            } else if (Exp->child[0]->name == "ID") {   // id
                translate_exp_id(Exp, reg);
            } else {
                cerr << "unexpected value: float or char !" << endl;
            }
            break;
        }
        case 2: {
            if (Exp->child[0]->name == "NOT") {
                preprocess_translate_cond_Exp(Exp, reg);
            }
            if (Exp->child[0]->name == "MINUS") {
                translate_exp_minus(Exp, reg);
            }
            break;
        }
        case 3: {
            Node *ID = Exp->child[0];
            string opt = Exp->child[1]->name;

            if (opt == "ASSIGN") {
                translate_exp_assign_exp(Exp, reg);
            }

            if (opt == "PLUS" || opt == "MINUS"
                || opt == "MUL" || opt == "DIV") {
                translate_exp_plus_sub_mul_div_exp(Exp, reg);
            }

            if (opt == "LT" || opt == "LE" || opt == "GT"
                || opt == "GE" || opt == "NE" || opt == "EQ") {
                preprocess_translate_cond_Exp(Exp, reg);
            }

            if (ID->name == "ID") {
                translate_exp_func(Exp, reg);
            }
            break;
        }
        case 4: {
            Node *ID = Exp->child[0];
            if (ID->name == "ID") {
                translate_exp_func(Exp, reg);
            }
            break;
        }
    }
}

void translate_exp_int(Node *Exp, const string &reg) {
    ir_tac.push_back(new TAC(reg, Exp->child[0]->content, "", TAC_TYPE::ASSIGN));
}

void translate_exp_id(Node *Exp, const string &reg) {
    Node *ID = Exp->child[0];
    string id = ID->content;
    if (param_id_reg_mapper.count(id) != 0) {  //是传参的寄存器对应的值，不需要额外处理
        ir_tac.push_back(new TAC(reg, param_id_reg_mapper[id], "", TAC_TYPE::ASSIGN));
    }
}

void translate_exp_minus(Node *Exp, const string &reg) {
    translate_basic_exp(Exp->child[1], get_vital_register());
    ir_tac.push_back(new TAC("0", reg, "", TAC_TYPE::SUBTRACTION));
}

void translate_exp_assign_exp(Node *Exp, const string &reg) {
    Node *Exp1 = Exp->child[0];
    assert(Exp1->child[0]->name == "ID");
    string var_reg = param_id_reg_mapper[Exp1->child[0]->content];
    Node *Exp2 = Exp->child[2];

    string new_reg = get_vital_register();

    translate_basic_exp(Exp2, new_reg);
    ir_tac.push_back(new TAC(var_reg, new_reg, "", TAC_TYPE::ASSIGN));
    ir_tac.push_back(new TAC(reg, var_reg, "", TAC_TYPE::ASSIGN));
}

void translate_exp_plus_sub_mul_div_exp(Node *Exp, const string &reg) {
    Node *Exp1 = Exp->child[0];
    Node *opt = Exp->child[1];
    Node *Exp2 = Exp->child[2];
    string reg1 = get_vital_register();
    string reg2 = get_vital_register();
    translate_basic_exp(Exp1, reg1);
    translate_basic_exp(Exp2, reg2);


    TAC *tac;
    if (opt->name == "PLUS") {
        tac = new TAC(reg, reg1, reg2, TAC_TYPE::ADDITION);
    } else if (opt->name == "MINUS") {
        tac = new TAC(reg, reg1, reg2, TAC_TYPE::SUBTRACTION);
    } else if (opt->name == "MUL") {
        tac = new TAC(reg, reg1, reg2, TAC_TYPE::MULTIPLICATION);
    } else {
        assert(opt->name == "DIV");
        tac = new TAC(reg, reg1, reg2, TAC_TYPE::DIVISION);
    }
    ir_tac.push_back(tac);
}


void preprocess_translate_cond_Exp(Node *Exp, const string &reg) {
    const string &lb1 = get_label();
    const string &lb2 = get_label();
    TAC *code0 = new TAC(reg, "0", "", TAC_TYPE::ASSIGN);
    ir_tac.push_back(code0);
    translate_cond_Exp(Exp, lb1, lb2);
    ir_tac.push_back(new TAC(lb1, "", "", TAC_TYPE::LABEL));
    ir_tac.push_back(new TAC(reg, "1", "", TAC_TYPE::ASSIGN));
    ir_tac.push_back(new TAC(lb2, "", "", TAC_TYPE::LABEL));
}