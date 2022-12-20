#include "../../include/syntaxTree.hpp"

/// @brief debug 用
void print_map_keys() {
    std::cout << "----------------------------" << std::endl;
    int counter = 0;
    for (auto &kv: symbolTable) {
        counter++;
        std::cout << "key" << counter << ": " << kv.first << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

void idToExp(Node *exp, Node *id) {
    if (exp->name != "Exp" || id->name != "ID") {
        return;
    }
    exp->var = symbolTable[id->content];
    // std::cout << id->content << std::endl;
}

string getName(Node *node, string nodeName) {
    if (nodeName == "DecList") {
        Node *VarDec = node->child[0]->child[0];
        return getName(VarDec, "VarDec");
    } else if (nodeName == "VarDec") {
        while (node->name == "VarDec") {
            node = node->child[0];
        }
        return node->content;
    } else if (nodeName == "ExtDecList") {
        Node *VarDec = node->child[0];
        return getName(VarDec, "VarDec");
    } else if (nodeName == "FunDec") {
        Node *ID = node->child[0];
        return ID->content;
    } else {
        return "";
    }
}

void checkExists_ID(Node *ID) {
    if (ID->name != "ID") {
        return;
    }
    string name = ID->content;
    if (symbolTable.count(name) == 0) {
        variableNoDefinition_1(ID->line_num, name);
    }
}

void checkExists_Array(Node *id) {
    if (id->child.size() == 1) {
        string arrayName = (id->child[0]->content);
        if (symbolTable.count(arrayName) != 0) {
            // array
            Type *arrayType = symbolTable[arrayName];
            if (arrayType->category != CATEGORY::ARRAY) {
                indexingOnNonArray_10((id->line_num));
            }
        } else {
            indexingOnNonArray_10((id->line_num));
        }
    } else {
        // multi-dementional array
        // string arrayName = (id->child[0]->content);
        Type *arrayType = id->var;
        if (arrayType == nullptr || arrayType->category != CATEGORY::ARRAY) {
            indexingOnNonArray_10((id->line_num));
        }
    }
}

void checkExist_FUN(Node *id) {
    string name = id->content;
    if (symbolTable.count(name) == 0) {
        functionNoDefinition_2(id->line_num, name);
    } else if (symbolTable[name]->category != CATEGORY::FUNCTION) {
        invokeNonFunctionVariable_11(id->line_num, name);
    }
}

/// @brief 检查函数的参数列表是否满足符号表中的要求  ID LP Args RP & ID LP RP
void checkParam_FUN(Node *id, Node *args) {
    string functionName = id->content;

    // 符号表中没有该函数
    if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION) {
        return;
    } else {
        //这里先处理数字不匹配的问题
        Type *function = symbolTable[functionName];
        if (get_expect_param_num(function->foo.param) == 0 && args == nullptr) //都是不需要参数
        {
            return;
        } else //参数个数匹配不上 报错
        {
            int expect = get_expect_param_num(function->foo.param);
            int real = get_real_param_num(args);
            if (real != expect) {
                invalidArgumentNumber_9(id->line_num, functionName, expect, real);
            }
        }
    }
}

void ExtDefVisit_SES(Node *node) {
    Node *specifier = node->child[0];
    if (specifier->child[0]->child.empty()) {
        // 其他基本类型的注册
        Node *extDecList = node->child[1];
        string name = getName(extDecList, "ExtDecList");
        string type_name = node->child[0]->child[0]->content;
        do {
            if (symbolTable.count(name) != 0) {
                variableRedefined_3(node->line_num, name);
            }

            Type *r = nullptr;
            if (type_name == "int") {
                r = Type::getPrimitiveINT();
            } else if (type_name == "float") {
                r = Type::getPrimitiveFLOAT();
            } else if (type_name == "char") {
                r = Type::getPrimitiveCHAR();
            }
            if (extDecList->child[0]->child[0]->child.empty()) {
                symbolTable[name] = r;
            } else {
                symbolTable[name] = new Type("", CATEGORY::ARRAY,
                                             getArrayFromVarDec(extDecList->child[0],
                                                                r));
            }
            if (extDecList->child.size() == 1) {
                break;
            }
            extDecList = extDecList->child[1];
            name = getName(extDecList, "ExtDecList");
        } while (true);
    } else
        // 结构体的注册
    {
        string structName = node->child[0]->child[0]->child[1]->content;
        Node *extDecList = node->child[1];
        string variableName = getName(extDecList, "ExtDecList");
        ExtDefVisit_SS(node);
        if (symbolTable.count(structName) == 0) {
            structNoDefinition_16(node->line_num, structName);
            // but this do not need to print, it use to happen is extDefVisit_SS;
            // do not match there
            // structRedefined(std::get<int>(node->value), structName);
        } else {
            do {

                if (symbolTable.count(variableName) != 0) {
                    variableRedefined_3(node->line_num, variableName);
                }

                if (extDecList->child[0]->child.size() == 1) {
                    // Struct with variable definition
                    symbolTable[variableName] = symbolTable[structName];
                } else {
                    // Struct with variable definition - with Array
                    symbolTable[variableName] = new Type("", CATEGORY::ARRAY,
                                                         getArrayFromVarDec(extDecList->child[0],
                                                                            symbolTable[structName]));
                }
                if (extDecList->child.size() == 1) {
                    return;
                }
                extDecList = extDecList->child[2];
                variableName = getName(extDecList, "ExtDecList");
            } while (true);
        }
    }
}

void ExtDefVisit_SS(Node *node) {
    // definition of Struct
    // std::cout << "SS\n";
    if (node->child[0]->child[0]->name == "TYPE") {
        // ignore the pureType's def likt `float;`
        return;
    }
    string name = node->child[0]->child[0]->child[1]->content; // this is structName
    vector<Node *> namesofFileds;
    getNamesOfDefList(node, namesofFileds);
    auto fieldListOfType = getFiledListFromNodesVector(namesofFileds);
    if (symbolTable.count(name) != 0) {
        structRedefined_15(node->line_num, name);
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
        }
    }
}

FieldList *getFiledListFromNodesVector(const vector<Node *> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    vector<FieldList *> fieldVec;
    for (const auto &item: vec) {
        const auto name = getName(item, "DecList");
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

void ExtDefVisit_SFC(Node *CompFunDec) {

    Node *Specifier = CompFunDec->child[0]; //表示返回值
    Node *FunDec = CompFunDec->child[1];
    Type *returnType = nullptr;
    if (Specifier->child[0]->name == "TYPE") {
        string type = Specifier->child[0]->content;
        if (type == "int") {
            returnType = Type::getPrimitiveINT();
        } else if (type == "float") {
            returnType = Type::getPrimitiveFLOAT();
        } else {
            returnType = Type::getPrimitiveCHAR();
        }
        symbolTable[FunDec->child[0]->content]->returnType = returnType;
    } else {
        Node *StructSpecifier = Specifier->child[0];
        Node *ID = StructSpecifier->child[1];
        symbolTable[ID->content]->returnType = returnType;
    }
    CompFunDec->child[0]->var = returnType;
    CompFunDec->child[1]->var = returnType;
}

/// @brief 这里逻辑有问题
void checkReturnType(Node *ExtDef) {

    /// @brief 这里应该找调用的函数
    Node *Specifer = ExtDef->child[0];
    Type *returnType = Specifer->var;
    Node *CompSt = ExtDef->child[2];

    // // 检查返回值放到最后操作
    vector<Node *> Exps = getReturnExpFromCompSt(CompSt);
    for (auto &&Exp: Exps) {
        // print_map_keys();

        // printf("--------------\n");
        // printf("当前返回值EXP:\n");
        // Node::print(Exp, 0);
        // printf("预期返回值Type:\n");
        // std::cout << (returnType == nullptr) << std::endl;
        // printf("--------------\n");

        if (Exp->var == nullptr) {
            // returnTypeDisMatch_8(Exp->line_num);
            // 非空指针compiler会报其他错误
        } else if (Exp->var != returnType) {
            returnTypeDisMatch_8(Exp->line_num);
        }
    }
}

/// @brief FunDec -> ID LP VarList RP | ID LP RP
/// 这里只拿到了函数的名字，没有拿到参数列表的具体内容
/* declarator
VarDec -> ID | VarDec LB INT RB
FunDec -> ID LP VarList RP | ID LP RP
VarList -> ParamDec COMMA VarList| ParamDec
ParamDec -> Specifier VarDec
*/
void FunDecVisit(Node *FunDec) {
    Type *function = new Type("", CATEGORY::FUNCTION, nullptr, nullptr);

    // Node *ID = FunDec->child[0];
    // function->name = ID->content;
    function->name = getName(FunDec, "FunDec");

    if (symbolTable.count(function->name) != 0) {
        functionRedefined_4(FunDec->line_num, function->name);
        // return;
    }

    if (FunDec->child.size() == 3) /// 没有参数列表 ID LP RP
    {
        symbolTable[function->name] = function;
        return;
    } else
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
        for (auto &&cur_ParamsDec: ParamsDecs) {
            Node *cur_Specifier = cur_ParamsDec->child[0]; // ParamDec -> Specifier VarDec
            Node *VarDec = cur_ParamsDec->child[1];
            if (VarDec->child.size() == 1) // 是普通类型
            {
                string ID = VarDec->child[0]->content;
                CATEGORY category = cur_Specifier->child[0]->name == "TYPE" ? CATEGORY::PRIMITIVE : CATEGORY::STRUCTURE;
                if (symbolTable.count(ID) == 0) {
                    structNoDefinition_16(VarDec->line_num, "");
                }
                switch (category) {
                    case CATEGORY::PRIMITIVE: {
                        Type *param_type = nullptr;
                        switch (string_to_prim[cur_Specifier->child[0]->content]) {
                            case PRIM::INT:
                                param_type = Type::getPrimitiveINT();
                                break;
                            case PRIM::CHAR:
                                param_type = Type::getPrimitiveCHAR();
                                break;
                            case PRIM::FLOAT:
                                param_type = Type::getPrimitiveFLOAT();
                                break;
                        }
                        // Type *param_type = new Type(ID, CATEGORY::PRIMITIVE, string_to_prim[cur_Specifier->child[0]->content]);

                        //注册参数列表中的参数到符号表上
                        symbolTable[ID] = param_type;
                        param.push_back(new FieldList((string) "", param_type)); // 基础类型的名字用不上
                        break;
                    }
                    case CATEGORY::STRUCTURE: //是结构体类型
                    {
                        string structName = cur_Specifier->child[0]->child[1]->content;
                        if (symbolTable.count(ID) == 0) {
                            structNoDefinition_16(VarDec->line_num, structName);
                        }
                        symbolTable[ID] = symbolTable[structName];
                        break;
                    }
                    default:
                        break;
                }
            } else //是数组类型
            {
                string ID = getName(VarDec, "VarDec");
                if (symbolTable.count(ID) != 0) {
                    variableRedefined_3(cur_VarList->line_num, ID);
                }
                Type *param_type;
                switch (string_to_prim[cur_Specifier->child[0]->content]) {
                    case PRIM::INT:
                        param_type = Type::getPrimitiveINT();
                        break;
                    case PRIM::CHAR:
                        param_type = Type::getPrimitiveCHAR();
                        break;
                    case PRIM::FLOAT:
                        param_type = Type::getPrimitiveFLOAT();
                        break;
                }
                // Type *param_type = new Type(ID, CATEGORY::PRIMITIVE, string_to_prim[cur_Specifier->child[0]->content]);
                symbolTable[ID] = new Type("", CATEGORY::ARRAY, getArrayFromVarDec(VarDec, param_type));
                vector<Node *> VarDecs;
                while (cur_VarList->child.size() != 1) //还没有到最后的ID
                {
                    ParamsDecs.push_back(cur_VarList->child[0]); // VarDec -> ID | VarDec LB INT RB
                    cur_VarList = cur_VarList->child[2];
                }
                ParamsDecs.push_back(cur_VarList->child[0]);
                VarDecs.clear();
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

void defVisit(Node *def) {
    Node *decList = def->child[1];
    // print_map_keys();
    string name = getName(decList, "DecList");

    if (def->child[0]->child[0]->child.empty()) {
        while (true) {
            if (symbolTable.count(name) != 0) {
                variableRedefined_3(def->line_num, name);
            }

            string type_name = def->child[0]->child[0]->content;

            if (decList->child[0]->child[0]->child.size() == 1) {
                if (type_name == "int") {
                    symbolTable[name] = Type::getPrimitiveINT();
                } else if (type_name == "float") {
                    symbolTable[name] = Type::getPrimitiveFLOAT();
                } else if (type_name == "char") {
                    symbolTable[name] = Type::getPrimitiveCHAR();
                }
            } else if (decList->child[0]->child[0]->child.size() >= 4) {
                // Array
                Type *r = nullptr;
                if (type_name == "int") {
                    r = Type::getPrimitiveINT();
                } else if (type_name == "float") {
                    r = Type::getPrimitiveFLOAT();
                } else if (type_name == "char") {
                    r = Type::getPrimitiveCHAR();
                }

                symbolTable[name] = new Type("", CATEGORY::ARRAY, getArrayFromVarDec(decList->child[0]->child[0], r));
                // Error occurs when identifying an array     int arr[3] = 5;
                if (decList->child[0]->child.size() == 3) { // tested
                    nonMatchTypeBothSide_5(decList->line_num);
                }
            }
            if (decList->child.size() == 1) {
                break;
            }
            decList = decList->child[2];
            name = getName(decList, "DecList");
        }
    } else {
        Node *defList = def->child[1];
        string structName = def->child[0]->child[0]->child[1]->content;
        string variableName = getName(defList, "DecList");
        if (symbolTable.count(structName) == 0) {
            structNoDefinition_16(def->line_num, structName);
        } else {
            do {
                if (symbolTable.count(variableName) != 0) {
                    variableRedefined_3(def->line_num, variableName);
                }
                if (defList->child[0]->child[0]->child.size() == 1) {
                    symbolTable[variableName] = symbolTable[structName];
                } else {
                    symbolTable[variableName] = new Type(variableName, CATEGORY::ARRAY,
                                                         getArrayFromVarDec(decList->child[0]->child[0],
                                                                            symbolTable[structName]));
                }
                if (decList->child.size() == 1) {
                    break;
                }
                decList = decList->child[2];
                variableName = getName(decList, "DecList");
            } while (true);
        }
    }
}

Array *getArrayFromVarDec(Node *node, Type *type) {
    if (node == nullptr || node->name != "VarDec") {
        return nullptr;
    } else {
        // std::cout<<typeid((node->child[2]->content)).name <<"\n";
        // int size = std::get<int>(node->child[2]->content);
        int size = std::stoi(node->child[2]->content);

        if (node->child[0]->child.size() == 1) {

            return new Array(size, type);
        } else {
            return new Array(size, new Type("", CATEGORY::ARRAY, getArrayFromVarDec(node->child[0], type)));
        }
    }
}

void getArrayType(Node *expOut, Node *expIn, Node *Integer) {
    //说明是别名
    if (Integer->child[0]->name == "ID") {
        Type *type = symbolTable[Integer->child[0]->content];
        if (type != Type::getPrimitiveINT()) {
            indexingByNonInteger_12(expIn->line_num);
            return;
        }
    }

    if (!checkIntegerType(Integer)) {
        expOut->var = nullptr;
        indexingByNonInteger_12(expIn->line_num);
        return;
    } else if (Integer->child.size() == 1) {
        string arrayName = expIn->child[0]->content;
        if (symbolTable.count(arrayName) != 0) {
            Type *arrayType = symbolTable[arrayName];
            if (arrayType->category == CATEGORY::ARRAY && arrayType->foo.array->base != nullptr) {

                expOut->var = arrayType->foo.array->base;
            }
        }
    } else {
        Type *arrayType = Integer->var;
        if (arrayType == nullptr) {
            expOut->var = static_cast<Type *>(nullptr);
            return;
        }
        if (arrayType->category == CATEGORY::ARRAY) {
            Type *temp = Integer->var;
            while (temp != nullptr && temp->foo.array != nullptr &&
                   temp->foo.array->base->category == CATEGORY::ARRAY) {
                temp = temp->foo.array->base;
            }
            if (temp->category == CATEGORY::PRIMITIVE) {
                expOut->var = temp->foo.array->base;
            }
        }
    }

    // printf("--------------\n");
    // printf("EXP0:\n");
    // Node::print(expOut, 0);
    // printf("EXP1:\n");
    // Node::print(expIn, 0);
    // printf("EXP2:\n");
    // Node::print(Integer, 0);
    // printf("--------------\n");
}

void getReturnTypeOfFunction(Node *expOut, Node *ID) {
    string functionName = ID->content;
    if (symbolTable.count(functionName) == 0 || symbolTable[functionName]->category != CATEGORY::FUNCTION) {
        return;
    }
    Type *returnType = symbolTable[functionName]->returnType;
    expOut->var = returnType;
}

// Exp: Exp ASSIGN Exp
// error type: 6
void checkRvalueInLeftSide(Node *Exp) {
    if (Exp->name != "Exp") {
        return;
    }
    Node *leftExp = Exp->child[0];
    switch (leftExp->child.size()) {
        case 1: {
            if (leftExp->child[0]->name == "ID") {
                return;
            }
            break;
        }
        case 3: {
            if (leftExp->child[0]->name == "Exp" && leftExp->child[2]->name == "ID" &&
                leftExp->child[1]->name == "DOT") {
                return;
            }
            break;
        }
        case 4: {
            if (leftExp->child[0]->name == "Exp" && leftExp->child[2]->name == "Exp" &&
                leftExp->child[1]->name == "LB" && leftExp->child[3]->name == "RB") {
                return;
            }
            break;
        }
    }
    rvalueLeftSetError_6(Exp->line_num);
}

// Exp: TYPE 5
// Exp: Exp ASSIGN Exp 要先保证左右EXP的 var类型是有内容的 才能进行比较
void checkAssignmentTypeMatching(Node *outExp, Node *leftExp, Node *rightExp) {
    Type *leftType = leftExp->var;
    Type *rightType = rightExp->var;

    // printf("--------------\n");
    // printf("EXP0:\n");
    // Node::print(outExp, 0);
    // printf("EXP1:\n");
    // Node::print(leftExp, 0);
    // printf("EXP2:\n");
    // Node::print(rightExp, 0);
    // printf("--------------\n");

    // printf("INT");
    // std::cout << Type::getPrimitiveINT() << std::endl;
    // printf("CHAR");
    // std::cout << Type::getPrimitiveCHAR() << std::endl;
    // printf("FLOAT");
    // std::cout << Type::getPrimitiveFLOAT() << std::endl;

    if (leftType == nullptr || rightType == nullptr) // 说明左表达式或右表达式存在运算符错误
    {
        // printf("有左值或右值为空");
        nonMatchTypeBothSide_5(leftExp->line_num);
        return;
    } else if (leftType == rightType) // 说明赋值不存在错误,这里需要考虑以下单例的问题
    {
        outExp->var = leftExp->var;
        return;
    } else if (leftType->category != rightType->category) {
        nonMatchTypeBothSide_5(leftExp->line_num);

    } else if (leftType->category == CATEGORY::STRUCTURE &&
               symbolTable[leftType->name]->name != symbolTable[rightType->name]->name) {
        nonMatchTypeBothSide_5(leftExp->line_num);
    }
    else if (leftType->category == CATEGORY::ARRAY) {
        vector<int> demensionLeftArray, demensionRightArray;
        Type *insideLeftType, *insideRightType;
        std::tie(demensionLeftArray, insideLeftType) = getArrayDemensionAndType(leftType);
        std::tie(demensionRightArray, insideRightType) = getArrayDemensionAndType(rightType);
        if (demensionLeftArray.size() != demensionRightArray.size() ||
            std::equal(demensionLeftArray.cbegin(), demensionLeftArray.cend(), demensionRightArray.cbegin())) {
            nonMatchTypeBothSide_5(leftExp->line_num);
        } else if (insideLeftType == nullptr || insideRightType == nullptr) {
            nonMatchTypeBothSide_5(leftExp->line_num);
        } else if (insideRightType->category != insideLeftType->category) {
            nonMatchTypeBothSide_5(leftExp->line_num);
        } else if (insideRightType->category == CATEGORY::PRIMITIVE && insideLeftType != insideRightType) {
            nonMatchTypeBothSide_5(leftExp->line_num);
        } else if (insideRightType->category == CATEGORY::STRUCTURE) {
            if (insideLeftType->name != insideRightType->name) {
                nonMatchTypeBothSide_5(leftExp->line_num);
            }
        }
    } else {
        nonMatchTypeBothSide_5(leftExp->line_num);
    }
}

void checkTypeOfDot(Node *expOut, Node *expIn, Node *ID) {
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