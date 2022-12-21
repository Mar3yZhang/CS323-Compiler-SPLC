# include "../../include/ir-util.hpp"

using namespace std;

void translate_compst(Node *CompSt) {
    Node *DefList = CompSt->child[1]; //暂时用不上
    Node *StmtList = CompSt->child[2];
    for (auto *Def: list_to_vector(DefList)) {
        translate_Def(Def);
    }
    for (auto *Stmt: list_to_vector(StmtList)) {
        translate_Stmt(Stmt);
    }
}

void translate_Stmt(Node *Stmt) {
    // TODO
    if (Stmt->name != "Stmt") {
        cerr << "Error! The input Node is not Stmt!" << endl;
        cerr << "Error! The input Node is " << Stmt->name << " ! " << endl;
        return;
    }
    switch (Stmt->child.size()) {
        case 3: { // RETURN Exp SEMI
            Node *Exp = Stmt->child[1];
            string reg = get_vital_register();
            // TODO: 需要translate_exp(Exp,reg);来得知节点exp1值存在哪个reg FINISH BY ZQ
            translate_basic_exp(Exp, reg);
            ir_tac.push_back(new TAC(reg, "", "", TAC_TYPE::RETURN));
            break;
        }
        case 5: {
            if (Stmt->child[0]->name == "IF") { // IF LP Exp RP Stmt
                Node *Stmt1 = Stmt->child[4];
                string label1 = get_label();
                string label2 = get_label();
                // TODO:需要translate_cond_exp(Exp,label1,label2);
                ir_tac.push_back(new TAC(label1, "", "", TAC_TYPE::LABEL));
                translate_Stmt(Stmt1);
                ir_tac.push_back(new TAC(label2, "", "", TAC_TYPE::LABEL));
            } else { // WHILE LP Exp RP Stmt
                Node *Stmt1 = Stmt->child[4];
                string label1 = get_label();
                string label2 = get_label();
                string label3 = get_label();
                ir_tac.push_back(new TAC(label1, "", "", TAC_TYPE::LABEL));
                // TODO:需要translate_cond_exp(Exp,label2,label3);
                ir_tac.push_back(new TAC(label2, "", "", TAC_TYPE::LABEL));
                translate_Stmt(Stmt1);
                ir_tac.push_back(new TAC(label1, "", "", TAC_TYPE::GOTO));
                ir_tac.push_back(new TAC(label3, "", "", TAC_TYPE::LABEL));
            }
            break;
        }
        case 7: { //IF LP Exp RP Stmt1 ELSE Stmt2
            Node *Stmt1 = Stmt->child[4];
            Node *Stmt2 = Stmt->child[6];
            string label1 = get_label();
            string label2 = get_label();
            string label3 = get_label();
            // TODO:需要translate_cond_exp(Exp,label1,label2);
            ir_tac.push_back(new TAC(label1, "", "", TAC_TYPE::LABEL));
            translate_Stmt(Stmt1);
            ir_tac.push_back(new TAC(label3, "", "", TAC_TYPE::GOTO));
            ir_tac.push_back(new TAC(label2, "", "", TAC_TYPE::LABEL));
            translate_Stmt(Stmt2);
            ir_tac.push_back(new TAC(label3, "", "", TAC_TYPE::LABEL));
            break;
        }
    }
}