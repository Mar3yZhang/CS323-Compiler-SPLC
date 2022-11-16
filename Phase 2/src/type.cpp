#include "type.hpp"

Array::Array(int size, Type *base)
    : size(size), base(base){};

FieldList::FieldList(string name, Type *type, FieldList *next)
    : name(name), type(type), next(next){};