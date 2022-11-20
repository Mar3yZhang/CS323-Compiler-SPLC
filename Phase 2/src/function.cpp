#include "Function.hpp"

Function::Function(string name, vector<Type *> parameter, Type *return_type)
    : name(name), parameter(parameter), return_type(return_type) {}
