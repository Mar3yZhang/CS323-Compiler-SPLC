#include <string>
#include <variant>
#include <vector>
#include "node.hpp"
using std::string;
using std::vector;

class Array;
class FieldList;
class Type
{
public:
    string name;
    enum
    {
        PRIMITIVE,
        ARRAY,
        STRUCTURE
    } category;
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
    Type();
    ~Type() = default;
};

class Array
{
public:
    Type *base;
    int size;

public:
    Array();
    ~Array() = default;
};

class FieldList
{
public:
    string name;
    Type *type;
    FieldList *next;

public:
    FieldList(/* args */);
    ~FieldList() = default;
};
