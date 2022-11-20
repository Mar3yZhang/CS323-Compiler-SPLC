#ifndef _SYBTAX_H
#define _SYBTAX_H

#include <string>
#include <unordered_map>
#include "Type.hpp"
#include "Node.hpp"

using std::string;
using std::unordered_map;
extern unordered_map<string, Type *> symbolTable;

string getName(Node *node,string nodeName);

Array *getArray(Node *node, Type *type);

void checkExists_ID(Node *node);

void checkExist_FUN(Node *node);

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
void defVisit(Node *node);

void getDecList(Node *node);

void getVarDec(Node *node);

#endif
