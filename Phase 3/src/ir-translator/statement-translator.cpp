# include "../../include/ir-util.hpp"

void translate_compst(Node *CompSt) {
    Node *DefList = CompSt->child[1]; //暂时用不上
    Node *StmtList = CompSt->child[2];
    for (auto *Stmt: list_to_vector(StmtList)) {
//        translate_Stmt(Stmt);
    }
}

void translate_Stmt(Node *Stmt) {
    // TODO
}