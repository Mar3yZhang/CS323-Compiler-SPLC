#include "../../include/type.hpp"

Type *int_ = new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
Type *float_ = new Type("", CATEGORY::PRIMITIVE, PRIM::FLOAT);
Type *char_ = new Type("", CATEGORY::PRIMITIVE, PRIM::CHAR);

Type::Type(string name, CATEGORY category, PRIM primitive) {
    this->name = name;
    this->category = category;
    this->foo.primitive = primitive;
}

Type::Type(string name, CATEGORY category, Array *array) {
    this->name = name;
    this->category = category;
    this->foo.array = array;
}

Type::Type(string name, CATEGORY category, FieldList *structure) {
    this->name = name;
    this->category = category;
    this->foo.structure = structure;
}

Type::Type(string name, CATEGORY category, FieldList *param, Type *returnType) {
    this->name = name;
    this->category = category;
    this->foo.param = param;
    this->returnType = returnType;
}

Type *Type::getPrimitiveINT() {
    return int_;
}

Type *Type::getPrimitiveCHAR() {
    return float_;
}

Type *Type::getPrimitiveFLOAT() {
    return char_;
}

Array::Array(int size, Type *base)
        : size(size), base(base) {};

FieldList::FieldList(string name, Type *type)
        : name(name), type(type) {};