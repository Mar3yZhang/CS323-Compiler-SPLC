#include "Type.hpp"

Type::Type(string name, CATEGORY category, PRIM primitive)
{
    this->name = name;
    this->category = category;
    this->foo.primitive = primitive;
}
Type::Type(string name, CATEGORY category, Array *array)
{
    this->name = name;
    this->category = category;
    this->foo.array = array;
}
Type::Type(string name, CATEGORY category, FieldList *structure)
{
    this->name = name;
    this->category = category;
    this->foo.structure = structure;
}
Type::Type(string name, CATEGORY category, FieldList *param, Type *returnType)
{
    this->name = name;
    this->category = category;
    this->foo.param = param;
    this->returnType = returnType;
}

Type *Type::getPrimitiveINT()
{
    return new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
}
Type *Type::getPrimitiveCHAR()
{
    return new Type("", CATEGORY::PRIMITIVE, PRIM::CHAR);
}
Type *Type::getPrimitiveFLOAT()
{
    return new Type("", CATEGORY::PRIMITIVE, PRIM::FLOAT);
}

Array::Array(int size, Type *base)
    : size(size), base(base){};

FieldList::FieldList(string name, Type *type)
    : name(name), type(type){};