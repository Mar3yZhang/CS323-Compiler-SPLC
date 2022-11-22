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
    // string functionName = id->content;
    // if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION)
    // {
    //     return;
    // }
    // Type *function = symbolTable[functionName];

    // if (function == nullptr)
    // {
    //     return;
    // }

    // FieldList *param_c = function->foo.param;
    // FieldList *param = (args == nullptr) ? nullptr : args->var->foo.param;

    // int expect_num = countParamNum(param_c);
    // int act_num = countParamNum(param_c);

    // if (countParamNum(param_c) != countParamNum(param))
    // {
    //     invalidArgumentNumber_9(id->line_num, functionName.c_str(), expect_num, act_num);
    // }
}

void extDefVisit(Node *node);

void getExtDecList(Node *node);

void getSpecifier_FunDec_Recv(Node *node);
// function

/// @brief FunDec -> ID LP VarList RP | ID LP RP
/// 这里只拿到了函数的名字，没有拿到参数列表的具体内容
/// TODO: 将函数的内容填充完整
/* declarator
VarDec -> ID | VarDec LB INT RB
FunDec -> ID LP VarList RP | ID LP RP
VarList -> ParamDec COMMA VarList| ParamDec
ParamDec -> Specifier VarDec
*/
void FunDecVisit(Node *FunDec)
{
    Type *function = new Type("", CATEGORY::FUNCTION, nullptr, nullptr);

    Node *ID = FunDec->child[0];
    function->name = ID->content;

    if (symbolTable.count(function->name) != 0)
    {
        functionRedefined_4(FunDec->line_num, function->name.c_str());
        // return;
    }

    if (FunDec->child.size() == 3) /// 没有参数列表 ID LP RP
    {
        symbolTable[function->name] = function;
        return;
    }
    else /// 有参数列表 ID LP VarList RP TODO:从VarList中获取信息
    {
        vector<Node *> ParamsDecs;
        Node *cur_VarList = FunDec->child[2];
        while (cur_VarList->child.size() != 1) //还没有到最后一个ParamDec
        {
            ParamsDecs.push_back(cur_VarList->child[0]); // VarList -> ParamDec COMMA VarList| ParamDec
            cur_VarList = cur_VarList->child[2];
        }
        ParamsDecs.push_back(cur_VarList->child[0]);

        vector<FieldList *> param; //暂存函数的参数列表
        for (auto &&cur_ParamsDec : ParamsDecs)
        {
            Node *cur_Specifier = cur_ParamsDec->child[0]; // ParamDec -> Specifier VarDec
            Node *VarDec = cur_ParamsDec->child[1];
            if (VarDec->child.size() == 1) // 是普通类型
            {
                string ID = VarDec->child[0]->content;
                CATEGORY category = cur_Specifier->child[0]->name == "TYPE" ? CATEGORY::PRIMITIVE : CATEGORY::STRUCTURE;
                switch (category)
                {
                case CATEGORY::PRIMITIVE:
                {

                    Type *param_type = new Type(ID, CATEGORY::PRIMITIVE, string_to_prim[cur_Specifier->child[0]->content]);

                    //注册参数列表中的参数到符号表上
                    symbolTable[ID] = param_type;

                    param.push_back(new FieldList((string) "", param_type)); // 基础类型的名字用不上
                    break;
                }
                case CATEGORY::STRUCTURE:
                {
                    // TODO: 结构体还没有实现
                    break;
                }
                default:
                    break;
                }
            }
            else //是数组类型
            {
                // TODO: 数组还没有实现

                // vector<Node *> VarDecs;
                // while (cur_VarList->child.size() != 1) //还没有到最后的ID
                // {
                //     ParamsDecs.push_back(cur_VarList->child[0]); // VarDec -> ID | VarDec LB INT RB
                //     cur_VarList = cur_VarList->child[2];
                // }
                // ParamsDecs.push_back(cur_VarList->child[0]);
                // VarDecs.clear();
            }
        }
        // TODO: 将param拆包 封装为一个 fieldlist链表

        function->foo.param = vector_to_fieldlist(param);
        symbolTable[function->name] = function;
        ParamsDecs.clear();
    }
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
