#pragma once

#include "iostream"
#include "Node.hpp"
#include "syntaxTree.hpp"
#include "TAC.hpp"
#include <string>
#include <set>
#include <vector>

using namespace std;

extern vector<TAC *> ir_tac;
extern Node *root_node;

///@brief 将ExtDeflist/StmtList展开为只有ExtDef/Stmt的Vector
vector<Node *> list_to_vector(Node *List);

void translate_to_tac();

void print_tac_ir();

// 这里的返回寄存器操作需要优化
string get_vital_register();

string get_temp_register();

void translate_func_dec(Node *CompFunDec);

void translate_func_varlist(Node *VarList);

void translate_compst(Node *CompSt);

void translate_EXP(Node *Exp, const string &reg);

TAC *translate_exp_int(Node *Exp);

TAC *translate_exp_id(Node *Exp);

TAC *translate_exp_minus(Node *Exp);


std::ostream &operator<<(std::ostream &lhs, TAC_TYPE type);