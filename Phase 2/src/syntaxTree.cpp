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
void ExtDefVisit_SES(Node *node) {
    if (node->child[0]->child[0]->child.empty()) {
        Node *extDecList = node->child[1];
        string name = getName(extDecList,"ExtDecList");
        string type_name = node->child[0]->child[0]->content;
        do {
            if (symbolTable.count(name) != 0) {
                variableRedefined_3(node->line_num, name);
            }
            if (extDecList->child[0]->child[0]->child.empty()) {
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
            } else {
                //TODO 
            }
            if (extDecList->child.size() == 1) {
                break;
            }
            extDecList = extDecList->child[2];
            name = getName(extDecList,"ExtDecList");
        } while (true);
    }else {
        string structName = node->child[0]->child[0]->child[1]->content;
        Node *extDecList = node->child[1];
        string variableName = getName(extDecList,"ExtDecList");
        ExtDefVisit_SS(node);
        if (symbolTable.count(structName) == 0) {
            structNoDefinition_16(node->line_num,structName);
            // but this do not need to print, it use to happen is extDefVisit_SS;
            // do not match there
            //structRedefined(std::get<int>(node->value), structName);
        } else {
            do {
                if (symbolTable.count(variableName) != 0) {
                    variableRedefined_3(node->line_num, variableName);
                }
                if (extDecList->child[0]->child.size() == 1) {
                    //Struct with variable definition
                    symbolTable[variableName] = symbolTable[structName];
                } else {
                    //Struct with variable definition - with Array
                }
                if (extDecList->child.size() == 1) {
                    return;
                }
                extDecList = extDecList->child[2];
                variableName = getName(extDecList,"ExtDecList");
            } while (true);
        }
    }
}
void ExtDefVisit_SS(Node *node) {
    // definition of Struct
    //std::cout << "SS\n";
    if (node->child[0]->child[0]->name == "TYPE") {
        // ignore the pureType's def likt `float;`
        return;
    }
    string name = node->child[0]->child[0]->child[1]->content; // this is structName
    vector<Node *> namesofFileds;
    getNamesOfDefList(node, namesofFileds);
    auto fieldListOfType = getFiledListFromNodesVector(namesofFileds);
    if (symbolTable.count(name) != 0) {
        structRedefined_15(node->line_num,name.c_str());
    } else {
        symbolTable[name] = new Type{name, CATEGORY::STRUCTURE, fieldListOfType};
    }
}

void getNamesOfDefList(Node *node, vector<Node *> &namesofFileds) {
    if (!node->child[0]->child[0]->child[3]->child.empty()) {
        auto nodeofField = node->child[0]->child[0]->child[3];
        while (nodeofField != nullptr && !nodeofField->child.empty() && nodeofField->name == "DefList") {
            auto declistNode = nodeofField->child[0]->child[1];
            while (declistNode != nullptr && declistNode->name == "DecList") {
                namesofFileds.push_back(declistNode);
                if (declistNode->child.size() == 3) {
                    declistNode = declistNode->child[2];
                } else {
                    break;
                }
            }
            nodeofField = nodeofField->child[1];
        };
    }
}

FieldList *getFiledListFromNodesVector(const vector<Node *> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    vector<FieldList *> fieldVec;
    for (const auto &item : vec) {
        const auto name = getName(item,"DecList");
        fieldVec.push_back(new FieldList{name, symbolTable[name]});
        symbolTable.erase(name);
    }
    for (auto i = static_cast<size_t>(0); i < vec.size() - 1; ++i) {
        fieldVec[i]->next = fieldVec[i + 1];
    }
    return fieldVec.front();
}

/// @brief 给函数添加上返回值类型
// ExtDef: Specifier FunDec CompSt

void ExtDefVisit_SFC(Node *ExtDef)
{

     
    printf("22222222222");
    
    Node *Specifier = ExtDef->child[0]; //表示返回值


    
    // printf("12312312312");

    Type *returnType;
    if (Specifier->child[0]->name == "TYPE")
    {
        string type = Specifier->child[0]->content;
        if (type == "int")
        {
            Type *returnType = Type::getPrimitiveINT();
        }
        else if (type == "float")
        {
            Type *returnType = Type::getPrimitiveFLOAT();
        }
        else
        {
            Type *returnType = Type::getPrimitiveCHAR();
        }

        Type *returnType = symbolTable[Specifier->child[0]->content]->returnType;
    }
    else
    {
        Node *StructSpecifier = Specifier->child[0];
        Node *ID = StructSpecifier->child[1];
        Type *returnType = symbolTable[ID->content]->returnType;
    }


    Node *CompSt = ExtDef->child[2];
    vector<Node *> Exps = getReturnExpFromCompSt(CompSt);
    for (auto &&Exp : Exps)
    {
        if (Exp->var == nullptr)
        {
            returnTypeDisMatch_8(Exp->line_num);
        }
        else if (Exp->var != returnType)
        {
            returnTypeDisMatch_8(Exp->line_num);
        }
        /// TODO: 比较结构体的名字 和 数组的维数与结构
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
                    string structName = cur_Specifier->child[0]->child[1]->content;
                    if (symbolTable.count(ID) == 0) {
                        structNoDefinition_16(VarDec->line_num,structName.c_str());
                    }
                    symbolTable[ID] = symbolTable[structName];
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
    Node *decList = def->child[1];
    // print_map_keys();  
    string name = getName(decList, "DecList");
    while (true) {
        if (symbolTable.count(name) != 0)
        {
            variableRedefined_3(def->line_num, name.c_str());
        }

    /// 暂时不考虑结构体和数组的情况
        if (decList->child[0]->child[0]->child.size() == 1) {
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
        }
        if (decList->child.size() == 1) {
            break;
        }
        decList = decList->child[2];
        name = getName(decList,"DecList");
    }
    Node *defList = def->child[1];
    /// TODO: 完成结构体的访问
    if (!def->child[0]->child[0]->child.empty()) {
        string structName = def->child[0]->child[0]->child[1]->content;
        string variableName = getName(defList,"DecList");
        if (symbolTable.count(structName) == 0) {
            structNoDefinition_16(def->line_num,structName.c_str());
        }else {
            do{
            if (defList->child[0]->child[0]->child.size() == 1) {
                symbolTable[variableName] = symbolTable[structName];
            }
            if (decList->child.size() == 1) {
                break;
            }
            decList = decList->child[2];
            variableName = getName(decList,"DecList");
            }while(true);
        }
    }

    /// TODO: 完成数组的访问
}

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

void checkTypeOfDot(Node *expOut, Node *expIn, Node *ID) {
    //std::cout<<expOut->child[0]->var<<std::endl;
    if (expOut->name == "Exp" && expOut->child[0]->var != nullptr &&
    expOut->child[0]->var->category != CATEGORY::STRUCTURE) {
        nonStructFVariable_13(expOut->line_num);
    }
    if (expIn->var == nullptr) {
        nonStructFVariable_13(expIn->line_num);
        return;
    }
    if (expIn->var->foo.structure == nullptr) {
        return;
    }
    FieldList *fieldList = expIn->var->foo.structure;
    string idName = ID->content;
    while (fieldList != nullptr) {
        if (fieldList->name == idName) {
            expOut->var = fieldList->type;
            return;
        }
        
        fieldList = fieldList->next;
    }
    noSuchMember_14(expOut->line_num, idName);
}