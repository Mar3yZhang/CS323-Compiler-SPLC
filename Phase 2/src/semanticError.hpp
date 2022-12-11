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

// error type 7
void binaryOperatorNotValid_7(int lineNum);

// error type 7
void singleOperatorNotValid_7(int lineNum);

// error type 8
void returnTypeDisMatch_8(int lineNum);

// error type 9
void invalidArgumentNumber_9(int lineNum, const std::string &name, int expect, int actually);

//error type 10
void indexingOnNonArray_10(int lineNum);

// error type 11
void invokeNonFunctionVariable_11(int lineNum, const std::string &name);

void indexingByNonInteger_12(int lineNum);

void nonStructFVariable_13(int lineNum);

void noSuchMember_14(int lineNum, const std::string &name);

void structRedefined_15(int lineNum, const std::string &name);

void structNoDefinition_16(int lineNum, const std::string &name);
