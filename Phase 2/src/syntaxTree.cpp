#include <iterator>
#include "syntaxTree.hpp"


string getName(Node *node,string nodeName) {
    if (nodeName == "DecList") {
        Node *VarDec = node->child[0]->child[0];
        return getName(VarDec,"VarDec");
    } else if (nodeName == "VarDec") {
        while (node->name == "VarDec") {
            node = node->child[0];
        }
        return node->content;
    } else if (nodeName == "ExtDecList") {
        Node *VarDec = node->child[0];
        return getName(VarDec,"VarDec");
    }
} 

Array *getArray(Node *node, Type *type) {

}
void extDefVisit(Node *node);

void getExtDecList(Node *node);

void getSpecifier_FunDec_Recv(Node *node);
//function
void FunDecVisit(Node *node);

void getVarList(Node *node);

void getParamDec(Node *node);
//compst
void getCompSt(Node *node);

void getDefList(Node *node);

void getStmtList(Node *node);

void getStmt(Node *node);

void getExp(Node *node);
//def
void defVisit(Node *node) {
    Node *decList = node->child[1];
    string name = getName(decList,"DecList");
    printf(name.c_str());
    if (symbolTable.count(name) != 0) { 
        printf("Error type 3 at Line %d: redefine variable: %s\n", node->line_num, name.c_str());
    }
    string type_name = node->child[0]->child[0]->content;
    if (type_name == "int") {
        symbolTable[name] = Type::getPrimitiveINT();
    } else if (type_name == "float") {
        symbolTable[name] = Type::getPrimitiveFLOAT();
    } else if (type_name == "char") {
        symbolTable[name] = Type::getPrimitiveCHAR();
    }
    //while (true) {
       
        //const auto &PrimitiveType = Type::getPrimitiveType(_type);
        //if {
        //    Type * type = PrimitiveType;
        //}
        //else if {
        //    Type * type = new Type(name,CATEGORY::Array,array);

        //} else {

        //Type * type = new Type(name,CATEGORY::STRUCTURE);
        //}
    //}
}

void getDecList(Node *node);

void getVarDec(Node *node);
