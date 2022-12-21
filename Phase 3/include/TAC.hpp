#ifndef PHASE_3_TAC_H
#define PHASE_3_TAC_H
#pragma once

#include <string>

using namespace std;

/*
Basic Instructions
LABEL x :               define a label x
FUNCTION x :            define a function x
x := y                  assign value of y to x
x := y + z              arithmetic addition
x := y - z              arithmetic subtraction
x := y * z              arithmetic multiplication
x := y / z              arithmetic division
GOTO x                  unconditional jump to label x
IF x [relop] y GOTO z   if the condition (binary boolean) is true, jump to label z
RETURN x                exit the current function and return value x
PARAM x                 declare a function parameter
ARG x                   pass argument x
x := CALL f             call a function, assign the return value to x
READ x                  read x from console
WRITE x                 print the value of x to console

Array relevant Instructions:
x := &y                 assign address of y to x
x := *y                 assign value stored in address y to x
*x := y                 copy value y to address x
DEC x [size]            allocate space pointed by x, size must be a multiple of 4

 */

class TAC;

enum class TAC_TYPE;
/// @brief 暂时不考虑数组和结构体相关的三地址指令
enum class TAC_TYPE {
    LABEL,
    FUNCTION,
    ASSIGN,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    GOTO,
    CONDITION,
    RETURN,
    PARAM,
    ARG,
    CALL,
    READ,
    WRITE
};

class TAC {
public:
    string X;
    string Y;
    string Z;
    enum TAC_TYPE type;

public:
    explicit TAC(const string& X, const string& Y, const string& Z, TAC_TYPE type);

    void print() const;

    static string preprocess_operand(const string &str);

    ~TAC() = default;
};


#endif //PHASE_3_TAC_H