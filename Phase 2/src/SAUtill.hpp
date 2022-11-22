#ifndef _sautill_HPP_
#define _sautill_HPP_
#include "Node.hpp"
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