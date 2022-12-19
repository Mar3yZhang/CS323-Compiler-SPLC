#pragma once

#include "iostream"
#include "Node.hpp"
#include "syntaxTree.hpp"
#include "TAC.hpp"
#include <string>
#include <set>

using namespace std;

extern vector<TAC *> ir_tac;
extern Node *root_node;

///@brief 将ExtDeflist展开为只有ExtDef的Vector
vector<Node *> ExtDefList_to_vector(Node *ExtDeflist);

void translate_to_tac();

void print_tac_ir();

// 这里的返回寄存器操作需要优化
string get_vital_register();

string get_temp_register();


void translate_func_dec(Node *CompFunDec);

void translate_func_varlist(Node *VarList);

std::ostream &operator<<(std::ostream &lhs, TAC_TYPE type);