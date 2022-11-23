#include "SAUtill.hpp"

/// @brief 返回参数列表中参数的个数
int countParamNum(FieldList *param)
{
    int counter = 0;
    FieldList *temp = param;

    if (temp == nullptr)
    {
        return 0;
    }
    while (temp->next != nullptr)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

/// @brief 将FieldList vector展开成链表
FieldList *vector_to_fieldlist(vector<FieldList *> param)
{
    FieldList *ans, *temp;
    for (size_t i = 0; i < param.size(); i++)
    {
        if (i == 0)
        {
            ans = param[i];
            temp = param[i];
        }
        else
        {
            temp->next = param[i];
            temp = temp->next;
        }
    }
    return ans;
}

int get_expect_param_num(FieldList *param)
{
    int counter = 0;
    FieldList *temp = param;
    while (temp != nullptr)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

// Args -> Exp COMMA Args | Exp
int get_real_param_num(Node *args)
{
    if (args == nullptr)
    {
        return 0;
    }
    else
    {
        int counter = 0;
        Node *temp = args;
        while (temp->child.size() != 1) //还没有到最后一个参数
        {
            counter++;
            temp = temp->child[2];
        }
        counter++;
        return counter;
    }
}

// 检查传入的两个type是否完全相同
bool checkTypeMatching(Type *leftType, Type *rightType)
{
    if (leftType == nullptr || rightType == nullptr)
    {
        return false;
    }
    else if (leftType == rightType)
    {
        return true;
    }
    else if (leftType->category != rightType->category)
    {
        return false;
    }

    /// TODO: 对数组和结构体类型判断的处理

    // }
    // else if (leftType->category == CATEGORY::STRUCTURE &&
    //          symbolTable[leftType->name]->name != symbolTable[rightType->name]->name)
    // {
    //     return false;
    // }
    // else if (leftType->category == CATEGORY::ARRAY)
    // {
    //     vector<int> demensionLeftArray, demensionRightArray;
    //     Type *insideLeftType, *insideRightType;
    //     std::tie(demensionLeftArray, insideLeftType) = getArrayDemensionAndType(leftType);
    //     std::tie(demensionRightArray, insideRightType) = getArrayDemensionAndType(rightType);
    //     if (demensionLeftArray.size() != demensionRightArray.size() ||
    //         std::equal(demensionLeftArray.cbegin(), demensionLeftArray.cend(), demensionRightArray.cbegin()))
    //     {
    //         return false;
    //     }
    //     else if (insideLeftType == nullptr || insideRightType == nullptr)
    //     {
    //         return false;
    //     }
    //     else if (insideRightType->category != insideLeftType->category)
    //     {
    //         return false;
    //     }
    //     else if (insideRightType->category == CATEGORY::PRIMITIVE && insideLeftType != insideRightType)
    //     {
    //         return false;
    //     }
    //     else if (insideRightType->category == CATEGORY::STRUCTURE)
    //     {
    //         if (insideLeftType->name != insideRightType->name)
    //         {
    //             return false;
    //         }
    //     }
    // }
    else
    {
        return false;
    }
}

/// @brief 检查EXP的var是否是整数类型
bool checkIntegerType(Node *exp)
{

    if (exp->var == nullptr)
    {
        // printf("当前EXP节点的var类型: Integer 还未初始化!\n");
        // 即内部嵌套的exp存在类型错误
        return false;
    }
    else
    {
        if (exp->var->category == CATEGORY::PRIMITIVE &&
            exp->var->foo.primitive == PRIM::INT)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool checkFloatType(Node *exp)
{

    if (exp->var == nullptr)
    {
        // printf("当前EXP节点的var类型: Float 还未初始化!\n");
        // 即内部嵌套的exp存在类型错误
        return false;
    }
    else
    {
        if (exp->var->category == CATEGORY::PRIMITIVE &&
            exp->var->foo.primitive == PRIM::FLOAT)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/// @brief 将外层的EXP的var设置为布尔类型 否则出错
void setBoolOperatorType(Node *expOut, Node *expLeft, Node *expRight)
{
    bool a = checkIntegerType(expLeft);
    bool b = checkIntegerType(expRight);

    if (a && b)
    {
        expOut->var = expLeft->var;
    }
    else
    {
        if (expLeft->var != nullptr && expRight->var != nullptr)
        {
            binaryOperatorNotValid_7(expOut->line_num);
        }
    }
}

void setCompareOperatorType(Node *expOut, Node *expLeft, Node *expRight)
{
    bool a = checkIntegerType(expLeft);
    bool b = checkIntegerType(expRight);
    bool c = checkFloatType(expLeft);
    bool d = checkFloatType(expRight);

    if ((a && b) || (c && d))
    {
        expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
    else
    {
        if (expLeft->var != nullptr && expRight->var != nullptr)
        {
            binaryOperatorNotValid_7(expOut->line_num);
        }
    }
}

void setAlrthOperatorType(Node *expOut, Node *expLeft, Node *expRight)
{
    bool a = checkIntegerType(expLeft);
    bool b = checkIntegerType(expRight);
    bool c = checkFloatType(expLeft);
    bool d = checkFloatType(expRight);

    if (a && b)
    {
        expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
    }
    else if (c && d)
    {
        expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::FLOAT);
    }
    else
    {
        if (expLeft->var != nullptr && expRight->var != nullptr)
        {
            binaryOperatorNotValid_7(expOut->line_num);
        }
    }
}

void setAlrthOperatorType(Node *expOut, Node *innerExp)
{
    if (expOut->name == "MINUS")
    {
        bool a = checkIntegerType(innerExp);
        bool b = checkFloatType(innerExp);

        if (a)
        {
            expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
        }
        else if (b)
        {
            expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::FLOAT);
        }
        else
        {
            if (innerExp == nullptr)
            {
                singleOperatorNotValid_7(expOut->line_num);
            }
        }
    }
    else if (expOut->name == "NOT")
    {
        bool a = checkIntegerType(innerExp);

        if (a)
        {
            expOut->var = new Type("", CATEGORY::PRIMITIVE, PRIM::INT);
        }
        else
        {
            if (innerExp == nullptr)
            {
                singleOperatorNotValid_7(expOut->line_num);
            }
        }
    }
}