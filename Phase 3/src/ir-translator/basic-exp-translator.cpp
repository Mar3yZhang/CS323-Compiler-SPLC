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
            if (Exp->child[0]->name == "MINUS") {
                translate_exp_minus(Exp, reg);
            }
        }
        case 3: {
            string opt = Exp->child[1]->name;
            if (opt == "ASSIGN") {
                translate_exp_assign_exp(Exp, reg);
            } else if (opt == "PLUS" || opt == "MINUS"
                       || opt == "MUL" || opt == "DIV") {
                translate_exp_plus_sub_mul_div_exp(Exp, reg);
            }
            break;
        }
        //todo:其他二元操作的实现
    }
//    return tac;
}

void translate_exp_int(Node *Exp, const string &reg) {
//    int content = stoi(Exp->child[0]->content);
//     if (!reg_has_int(content)) {
    TAC *tac = new TAC(reg, Exp->child[0]->content, "", TAC_TYPE::ASSIGN);
    ir_tac.push_back(tac);
//    }
}

void translate_exp_id(Node *Exp, const string &reg) {
    Node *ID = Exp->child[0];
    string id = ID->content;
    if (param_id_reg_mapper.count(id) != 0) {  //是传参的寄存器对应的值，不需要额外处理
        TAC *tac = new TAC(reg, param_id_reg_mapper[id], "", TAC_TYPE::ASSIGN);
        ir_tac.push_back(tac);
    }

//    if () {
//
//    }
    // 这里不需要生成新的三地址码，只需要传回id的内部值
    // 这里的绑定会在赋值时完成
}

void translate_exp_minus(Node *Exp, const string &reg) {
    translate_basic_exp(Exp->child[1], get_vital_register());
    TAC *tac = new TAC("0", reg, "", TAC_TYPE::SUBTRACTION);
    ir_tac.push_back(tac);
}

void translate_exp_assign_exp(Node *Exp, const string &reg) {
    Node *Exp1 = Exp->child[0];
    assert(Exp1->child[0]->name == "ID");
    string var_reg = param_id_reg_mapper[Exp1->child[0]->content];
    Node *Exp2 = Exp->child[2];

    string new_reg = get_vital_register();

    translate_basic_exp(Exp2, new_reg);
    TAC *tac1 = new TAC(var_reg, new_reg, "", TAC_TYPE::ASSIGN);
    TAC *tac2 = new TAC(reg, var_reg, "", TAC_TYPE::ASSIGN);
    ir_tac.push_back(tac1);
    ir_tac.push_back(tac2);
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
