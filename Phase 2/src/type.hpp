#include <string>
#include <vector>
using std::string;
using std::vector;


class Array;
class FieldList;

/// @brief 用来在参数符号表中表示数据类型的结构体
class Type
{
public:
    string name;
    enum
    {
        PRIMITIVE,
        ARRAY,
        STRUCTURE,
    } category = PRIMITIVE;
    union
    {
        enum
        {
            INT,
            FLOAT,
            CHAR
        } primitive;
        Array *array;
        FieldList *structure;
    };

public:
    Type() = default;
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
    FieldList(string name, Type *type, FieldList *next);
    ~FieldList() = default;
};
