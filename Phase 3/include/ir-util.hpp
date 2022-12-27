#pragma once

#include "iostream"
#include "Node.hpp"
#include "syntaxTree.hpp"
#include "TAC.hpp"
#include <string>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

extern vector<TAC *> ir_tac;

extern Node *root_node;

/// @将id和存入的寄存器做映射专门用于函数传入参数
extern unordered_map<string, string> param_id_reg_mapper;

// 判断当前的程序是否有while循环，如果有，reg优化将失效
extern bool has_loop;

///@将list转换为vector
vector<Node *> list_to_vector(Node *List);

bool isNumber(const string &str);

void translate_to_tac();

void print_tac_ir();

// 这里的返回寄存器操作需要优化
string get_vital_register();

string get_label();

void translate_func_dec(Node *CompFunDec);

void translate_func_varlist(Node *VarList);

void translate_compst(Node *CompSt);

void translate_basic_exp(Node *Exp, const string &reg);

void translate_exp_int(Node *Exp, const string &reg);

void translate_exp_id(Node *Exp, const string &reg);

void translate_exp_minus(Node *Exp, const string &reg);

void translate_exp_assign_exp(Node *Exp, const string &reg);

void translate_exp_func_write(Node *Exp, const string &reg);

void translate_exp_plus_sub_mul_div_exp(Node *Exp, const string &reg);

void translate_args(Node *Args, vector<string> &argList);

void translate_args_exp(Node *Args, vector<string> &argList);

void translate_args_exp_comma_args(Node *Args, vector<string> &argList);

void translate_exp_func(Node *Exp, const string &reg);

void translate_exp_func_read(const string &reg);

void preprocess_translate_cond_Exp(Node *Exp, const string &reg);

void translate_cond_Exp_AND(Node *Exp, const string &label_t, const string &label_f);

void translate_cond_Exp_OR(Node *Exp, const string &label_t, const string &label_f);

void translate_cond_Exp_Compares(Node *Exp, const string &label_t, const string &label_f);

void translate_cond_Exp(Node *Exp, const string &label_t, const string &label_f);

void translate_Def(Node *Def);

void translate_Dec(Node *Dec);

void translate_Stmt(Node *Stmt);

std::ostream &operator<<(std::ostream &lhs, const TAC *tac);

void dump_ir_file(const char* path);

void label_optimization();

void duplicated_assign_optimization();