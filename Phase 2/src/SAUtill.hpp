#ifndef _sautill_HPP_
#define _sautill_HPP_
#include "Node.hpp"
#include "semanticError.hpp"
#include "type.hpp"
#endif

int countParamNum(FieldList *param);

static unordered_map<string, PRIM> string_to_prim = {
    {string("int"), PRIM::INT},
    {string("float"), PRIM::FLOAT},
    {string("char"), PRIM::CHAR},
};

static unordered_map<PRIM, string> prim_to_string = {
    {PRIM::INT, string("INT")},
    {PRIM::FLOAT, string("FLOAT")},
    {PRIM::CHAR, string("CHAR")},
};

FieldList *vector_to_fieldlist(vector<FieldList *> param);

int get_expect_param_num(FieldList *param);

int get_real_param_num(Node *args);

void setBoolOperatorType(Node *expOut, Node *expLeft, Node *expRight);

void setCompareOperatorType(Node *expOut, Node *expLeft, Node *expRight);

void setAlrthOperatorType(Node *expOut, Node *expLeft, Node *expRight);

void setAlrthOperatorType(Node *expOut, Node *innerExp);

bool checkIntegerType(Node *exp);

vector<Node *> getReturnExpFromCompSt(Node *CompSt);

vector<Node *> getReturnExpFromStmt(Node *Stmt);

std::tuple<vector<int>, Type *> getArrayDemensionAndType(Type *_type);