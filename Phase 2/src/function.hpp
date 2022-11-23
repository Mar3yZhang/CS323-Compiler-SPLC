#ifndef _function_HPP_
#define _function_HPP_
#include <string>
#include <vector>
#include "type.hpp"
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::vector;

/// @brief 用来判断函数参数列表和返回值是否正确的结构体
class Function
{
public:
    string name;                                // 函数名
    vector<Type *> parameter;                   // 参数列表
    Type *return_type;                          // 返回值
    unordered_map<string, Type> varSymbolTable; // scope参数符号表

public:
    Function(string name, vector<Type *> parameter, Type *return_type);
    ~Function() = default;
};

// bool hasSuchFunction(unordered_map<string, Function> &funcSymbolTable, Function func);
#endif