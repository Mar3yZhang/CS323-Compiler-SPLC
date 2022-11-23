#include "syntaxTree.hpp"

/// @brief debug 用
void print_map_keys()
{
    std::cout << "----------------------------" << std::endl;
    int counter = 0;
    for (auto &kv : symbolTable)
    {
        counter++;
        std::cout << "key" << counter << ": " << kv.first << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    return;
}

void idToExp(Node *exp, Node *id)
{
    if (exp->name != "Exp" || id->name != "ID")
    {
        return;
    }
    exp->var = symbolTable[id->content];
}

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
    else if (nodeName == "FunDec")
    {
        Node *ID = node->child[0];
        return ID->content;
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

void checkExists_ID(Node *ID)
{
    if (ID->name != "ID")
    {
        return;
    }
    string name = ID->content;
    if (symbolTable.count(name) == 0)
    {
        variableNoDefinition_1(ID->line_num, name.c_str());
    }
}

void checkExist_FUN(Node *id)
{
    string name = id->content;
    if (symbolTable.count(name) == 0)
    {
        functionNoDefinition_2(id->line_num, name.c_str());
    }
    else if (symbolTable[name]->category != CATEGORY::FUNCTION)
    {
        invokeNonFunctionVariable_11(id->line_num, name);
    }
}

/// @brief 检查函数的参数列表是否满足符号表中的要求  ID LP Args RP & ID LP RP
void checkParam_FUN(Node *id, Node *args)
{
    string functionName = id->content;

    // 符号表中没有该函数
    if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION)
    {
        return;
    }
    else
    {
        //这里先处理数字不匹配的问题
        Type *function = symbolTable[functionName];
        if (get_expect_param_num(function->foo.param) == 0 && args == nullptr) //都是不需要参数
        {
            return;
        }
        else //参数个数匹配不上 报错
        {
            int expect = get_expect_param_num(function->foo.param);
            int real = get_real_param_num(args);
            if (real != expect)
            {
                invalidArgumentNumber_9(id->line_num, functionName, expect, real);
            }
        }

        ///  TODO: 这里需要处理类型不匹配的问题 type 9.2，建议先把Args展开成vector
        ///  TODO: type 11 需要先向符号表注册非函数变量
    }
}

void extDefVisit(Node *node);
/*
ExtDef: error ExtDecList SEMI
    | Specifier ExtDecList SEMI
    | Specifier SEMI
    | Specifier FunDec CompSt
*/
/// @brief 给函数添加上返回值类型
void ExtDefVisit_SES(Node *ExtDef)
{
    Node *Specifier = ExtDef->child[0]; //表示返回值
    CATEGORY category = Specifier->child[0]->name == "TYPE" ? CATEGORY::PRIMITIVE : CATEGORY::STRUCTURE;
    switch (category)
    {
    case CATEGORY::PRIMITIVE:
    {

        Type *return_type = new Type("", CATEGORY::PRIMITIVE, string_to_prim[Specifier->child[0]->content]);
        Node *FunDec = ExtDef->child[2];
        if (symbolTable.count(getName(FunDec, "FunDec")) == 0)
        {
            printf("找不到目标函数");
        }
        else
        {
            Type *function = symbolTable[getName(FunDec, "FunDec")];
            function->returnType = return_type;
        }
    }
    case CATEGORY::STRUCTURE: //是结构体类型
    {
        ///  TODO: 将结构体返回值添加到目标函数
        break;
    }
    default:
        break;
    }
}

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

    // Node *ID = FunDec->child[0];
    // function->name = ID->content;
    function->name = getName(FunDec, "FunDec");

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
                case CATEGORY::STRUCTURE: //是结构体类型
                {
                    ///  TODO: 实现结构体在符号表和函数中的注册
                    break;
                }
                default:
                    break;
                }
            }
            else //是数组类型
            {
                ///  TODO:  实现数组在符号表和函数中的注册

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
        // 将param拆包 封装为一个 fieldlist链表

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

/*
Def
  Specifier
    TYPE
  DecList
    Dec
      VarDec
        ID: code
  SEMI
  // DO not forget VarDec can contain array
 * */

void defVisit(Node *def)
{

    // print_map_keys();

    Node *decList = def->child[1];
    string name = getName(decList, "DecList");
    if (symbolTable.count(name) != 0)
    {
        variableRedefined_3(def->line_num, name.c_str());
    }

    /// 暂时不考虑结构体和数组的情况

    string type_name = def->child[0]->child[0]->content;
    if (type_name == "int")
    {
        symbolTable[name] = Type::getPrimitiveINT();
    }
    else if (type_name == "float")
    {
        symbolTable[name] = Type::getPrimitiveFLOAT();
    }
    else if (type_name == "char")
    {
        symbolTable[name] = Type::getPrimitiveCHAR();
    }

    /// TODO: 完成结构体的访问

    /// TODO: 完成数组的访问
}

void getDecList(Node *node);

void getVarDec(Node *node);

void getReturnTypeOfFunction(Node *expOut, Node *ID)
{
    string functionName = ID->content;
    if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION)
    {
        return;
    }
    Type *returnType = symbolTable[functionName]->returnType;
    expOut->var = returnType;
}

// Exp: Exp ASSIGN Exp
// error type: 6
void checkRvalueInLeftSide(Node *Exp)
{
    if (Exp->name != "Exp")
    {
        return;
    }
    Node *leftExp = Exp->child[0];
    switch (leftExp->child.size())
    {
    case 1:
    {
        if (leftExp->child[0]->name == "ID")
        {
            return;
        }
        break;
    }
    case 3:
    {
        if (leftExp->child[0]->name == "Exp" && leftExp->child[2]->name == "ID" &&
            leftExp->child[1]->name == "DOT")
        {
            return;
        }
        break;
    }
    case 4:
    {
        if (leftExp->child[0]->name == "Exp" && leftExp->child[2]->name == "Exp" &&
            leftExp->child[1]->name == "LB" && leftExp->child[3]->name == "RB")
        {
            return;
        }
        break;
    }
    }
    rvalueLeftSetError_6(Exp->line_num);
}

// Exp: TYPE 5
// Exp: Exp ASSIGN Exp 要先保证左右EXP的 var类型是有内容的 才能进行比较
void checkAssignmentTypeMatching(Node *leftExp, Node *rightExp)
{
    Type *leftType = leftExp->var;
    Type *rightType = rightExp->var;

    if (leftType == nullptr || rightType == nullptr) // 说明左表达式或右表达式存在运算符错误
    {

        printf("有左值或右值为空");
        return;
    }
    else if (leftType == rightType) // 说明赋值不存在错误
    {
        return;
    }
    else if (leftType->category != rightType->category)
    {
        nonMatchTypeBothSide_5(leftExp->line_num);
    }
    else if (leftType->category == CATEGORY::STRUCTURE &&
             symbolTable[leftType->name]->name != symbolTable[rightType->name]->name)
    {
        nonMatchTypeBothSide_5(leftExp->line_num);
    }

    /// TODO: 数组的赋值等价
    // else if (leftType->category == CATEGORY::ARRAY)
    // {
    //     vector<int> demensionLeftArray, demensionRightArray;
    //     Type *insideLeftType, *insideRightType;
    //     std::tie(demensionLeftArray, insideLeftType) = getArrayDemensionAndType(leftType);
    //     std::tie(demensionRightArray, insideRightType) = getArrayDemensionAndType(rightType);
    //     if (demensionLeftArray.size() != demensionRightArray.size() ||
    //         std::equal(demensionLeftArray.cbegin(), demensionLeftArray.cend(), demensionRightArray.cbegin()))
    //     {
    //         func(lineNum);
    //     }
    //     else if (insideLeftType == nullptr || insideRightType == nullptr)
    //     {
    //         func(lineNum);
    //     }
    //     else if (insideRightType->category != insideLeftType->category)
    //     {
    //         func(lineNum);
    //     }
    //     else if (insideRightType->category == CATEGORY::PRIMITIVE && insideLeftType != insideRightType)
    //     {
    //         func(lineNum);
    //     }
    //     else if (insideRightType->category == CATEGORY::STRUCTURE)
    //     {
    //         if (insideLeftType->name != insideRightType->name)
    //         {
    //             func(lineNum);
    //         }
    //     }
    // }
    else
    {
        nonMatchTypeBothSide_5(leftExp->line_num);
    }
}
