#include "syntaxTree.hpp"

string getName(Node *node, string nodeName)
{
    if (nodeName == "DecList")
    {
        Node *VarDec = node->child[0]->child[0];
        return getName(VarDec, "VarDec");
    }
    else if (nodeName == "VarDec")
    {
        while (node->name == "VarDec")
        {
            node = node->child[0];
        }
        return node->content;
    }
    else if (nodeName == "ExtDecList")
    {
        Node *VarDec = node->child[0];
        return getName(VarDec, "VarDec");
    }
    else
    {
        return "";
    }
}

Array *getArray(Node *node, Type *type)
{
    return nullptr;
}

void checkExists_ID(Node *node)
{
    if (node->name != "ID")
    {
        return;
    }
    string name = node->content;
    if (symbolTable.count(name) == 0)
    {
        variableNoDefinition_1(node->line_num, name.c_str());
    }
}

void checkExist_FUN(Node *id)
{
    string name = id->content;
    if (symbolTable.count(name) == 0)
    {
        functionNoDefinition_2(id->line_num, name.c_str());
    }
}

/// @brief 检查函数的参数列表是否满足符号表中的要求  ID LP Args RP & ID LP RP
void checkParam_FUN(Node *id, Node *args)
{
    string functionName = id->content;
    if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION)
    {
        return;
    }
    Type *function = symbolTable[functionName];

    if (function == nullptr)
    {
        return;
    }

    FieldList *param_c = function->foo.param;
    FieldList *param = (args == nullptr) ? nullptr : args->var->foo.param;

    int expect_num = countParamNum(param_c);
    int act_num = countParamNum(param_c);

    if (countParamNum(param_c) != countParamNum(param))
    {
        invalidArgumentNumber_9(id->line_num, functionName.c_str(), expect_num, act_num);
    }
}

void extDefVisit(Node *node);

void getExtDecList(Node *node);

void getSpecifier_FunDec_Recv(Node *node);
// function
void FunDecVisit(Node *node)
{
    Type *functionType = new Type("", CATEGORY::FUNCTION, PRIM::INT);
    functionType->name = node->child[0]->content;
    if (symbolTable.count(functionType->name) != 0)
    {
        printf("Error type 4 at Line %d: redefine function: %s\n", node->line_num, functionType->name.c_str());
        return;
    }
    symbolTable[functionType->name] = functionType;
}

void getVarList(Node *node);

void getParamDec(Node *node);
// compst
void getCompSt(Node *node);

void getDefList(Node *node);

void getStmtList(Node *node);

void getStmt(Node *node);

void getExp(Node *node);
// def
void defVisit(Node *def)
{
    Node *decList = def->child[1];
    string name = getName(decList, "DecList");
    // std::cout << name.c_str() << std::endl;
    if (symbolTable.count(name) != 0)
    {
        variableRedefined_3(def->line_num, name.c_str());
    }

    /// 暂时不考虑结构体的情况

    string type_name = def->child[0]->child[0]->content;

    if (type_name == "INT")
    {
        symbolTable[name] = Type::getPrimitiveINT();
    }
    else if (type_name == "FLOAT")
    {
        symbolTable[name] = Type::getPrimitiveFLOAT();
    }
    else if (type_name == "CHAR")
    {
        symbolTable[name] = Type::getPrimitiveCHAR();
    }

    

    


    // while (true) {

    // const auto &PrimitiveType = Type::getPrimitiveType(_type);
    // if {
    //     Type * type = PrimitiveType;
    // }
    // else if {
    //     Type * type = new Type(name,CATEGORY::Array,array);

    //} else {

    // Type * type = new Type(name,CATEGORY::STRUCTURE);
    // }
    //}
}

void getDecList(Node *node);

void getVarDec(Node *node);
