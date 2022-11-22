#include <string>
#include <unordered_map>

// error type 1

void variableNoDefinition_1(int lineNum, const std::string &name);

// error type 2
void functionNoDefinition_2(int lineNum, const std::string &name);

// error type 3
void variableRedefined_3(int lineNum, const std::string &name);

// error type 4
void functionRedefined_4(int lineNum, const std::string &name);

// error type 5
void nonMatchTypeBothSide_5(int lineNum);

// error type 6
void rvalueLeftSetError_6(int lineNum);

// error type 9
void invalidArgumentNumber_9(int lineNum, const std::string &name, int expect, int actually);

// error type 11
void invokeNonFunctionVariable_11(int lineNum, const std::string &name);