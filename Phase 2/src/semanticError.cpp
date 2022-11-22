#include "semanticError.hpp"

void variableNoDefinition_1(int lineNum, const std::string &name)
{
    printf("Error type 1 at Line %d: undefined variable: %s\n", lineNum, name.c_str());
}

// error type 2
void functionNoDefinition_2(int lineNum, const std::string &name)
{
    printf("Error type 2 at Line %d: undefined function: %s\n", lineNum, name.c_str());
}

// error type 3
void variableRedefined_3(int lineNum, const std::string &name)
{
    printf("Error type 3 at Line %d: redefine variable: %s\n", lineNum, name.c_str());
}

// error type 4
void functionRedefined_4(int lineNum, const std::string &name)
{
    printf("Error type 4 at Line %d: redefine function: %s\n", lineNum, name.c_str());
}

// error type 9
void invalidArgumentNumber_9(int lineNum, const std::string &name, int expect, int actually)
{
    printf("Error type 9 at Line %d: invalid argument number for %s, expect %d, got %d\n", lineNum, name.c_str(),
           expect, actually);
}

void invokeNonFunctionVariable_11(int lineNum, const std::string &name)
{
    printf("Error type 11 at Line %d: invoking non-function variable: %s\n", lineNum, name.c_str());
}