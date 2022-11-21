#ifndef _TYPE_H
#define _TYPE_H
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::vector;

enum class PRIM;
enum class CATEGORY;
class Array;
class FieldList;
class Type;

enum class PRIM
{
    INT,
    FLOAT,
    CHAR
};
enum class CATEGORY
{
    PRIMITIVE,
    ARRAY,
    STRUCTURE,
    FUNCTION,
};

/// @brief 用来在参数符号表中表示数据类型的结构体
class Type
{
public:
    string name;
    enum CATEGORY category;
    union
    {
        enum PRIM primitive;
        Array *array;
        FieldList *structure;
        FieldList *param;
    } foo;
    Type *returnType = nullptr;

public:
    explicit Type(string name, enum CATEGORY category, enum PRIM primitive);
    explicit Type(string name, enum CATEGORY category, Array *array);
    explicit Type(string name, enum CATEGORY category, FieldList *structure);
    explicit Type(string name, enum CATEGORY category, FieldList *param, Type *returnType);
    static Type *getPrimitiveINT();
    static Type *getPrimitiveFLOAT();
    static Type *getPrimitiveCHAR();
    ~Type() = default;
};

class Array
{
public:
    int size;
    Type *base = nullptr;

public:
    Array() = default;
    Array(int size, Type *base);
    ~Array() = default;
};

class FieldList
{
public:
    string name;
    Type *type = nullptr;
    FieldList *next = nullptr;

public:
    FieldList() = default;
    FieldList(string name, Type *type);
    ~FieldList() = default;
};
#endif