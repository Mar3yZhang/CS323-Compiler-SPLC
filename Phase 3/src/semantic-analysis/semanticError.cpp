#include "../../include/semanticError.hpp"

void variableNoDefinition_1(int lineNum, const std::string &name) {
//    printf("Error type 1 at Line %d: undefined variable: %s\n", lineNum, name.c_str());
}

// error type 2
void functionNoDefinition_2(int lineNum, const std::string &name) {
//    printf("Error type 2 at Line %d: undefined function: %s\n", lineNum, name.c_str());
}

// error type 3
void variableRedefined_3(int lineNum, const std::string &name) {
//    printf("Error type 3 at Line %d: redefine variable: %s\n", lineNum, name.c_str());
}

// error type 4
void functionRedefined_4(int lineNum, const std::string &name) {
//    printf("Error type 4 at Line %d: redefine function: %s\n", lineNum, name.c_str());
}

// error type 5
void nonMatchTypeBothSide_5(int lineNum) {
//    printf("Error type 5 at Line %d: unmatching types on both sides of assignment\n", lineNum);
}

// error type 6
void rvalueLeftSetError_6(int lineNum) {
//    printf("Error type 6 at Line %d: left side in assignment is rvalue\n", lineNum);
}

// error type 7
void binaryOperatorNotValid_7(int lineNum) {
//    printf("Error type 7 at Line %d: binary operation on invalid variables\n", lineNum);
}

// error type 7
void singleOperatorNotValid_7(int lineNum) {
//    printf("Error type 7 at Line %d: single operation on invalid variables\n", lineNum);
}

// error type 8
void returnTypeDisMatch_8(int lineNum) {
//    printf("Error type 8 at Line %d: incompatiable return type\n", lineNum);
}

// error type 9
void invalidArgumentNumber_9(int lineNum, const std::string &name, int expect, int actually) {
//    printf("Error type 9 at Line %d: invalid argument number for %s, expect %d, got %d\n", lineNum, name.c_str(),
//           expect, actually);
}

void indexingOnNonArray_10(int lineNum) {
//    printf("Error type 10 at Line %d: indexing on non-array variable\n", lineNum);
}

void invokeNonFunctionVariable_11(int lineNum, const std::string &name) {
//    printf("Error type 11 at Line %d: invoking non-function variable: %s\n", lineNum, name.c_str());
}

void indexingByNonInteger_12(int lineNum) {
//    printf("Error type 12 at Line %d: indexing by non-integer\n", lineNum);
}

void nonStructFVariable_13(int lineNum) {
//    printf("Error type 13 at Line %d: accessing with non-struct variable\n", lineNum);
}

void noSuchMember_14(int lineNum, const std::string &name) {
//    printf("Error type 14 at Line %d: no such member: %s\n", lineNum, name.c_str());
}

void structRedefined_15(int lineNum, const std::string &name) {
//    printf("Error type 15 at Line %d: redefine struct: %s\n", lineNum, name.c_str());
}

void structNoDefinition_16(int lineNum, const std::string &name) {
//    printf("Error type 16 at Line %d: struct %s haven't define\n", lineNum, name.c_str());
}
