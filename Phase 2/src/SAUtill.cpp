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

/// @brief 返回一个tuple(vector<int>,type*)
/// 通过vector来返回数组的几个维数
std::tuple<vector<int>, Type *> getArrayDemensionAndType(Type *_type)
{
    vector<int> demensions;
    Type *temp = _type;
    while (temp != nullptr && temp->foo.array != nullptr)
    {
        auto tempArray = temp->foo.array;
        temp = tempArray->base;
        demensions.push_back(tempArray->size);
    }
    return std::tuple<vector<int>, Type *>(demensions, temp);
};

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
        if (exp->var == Type::getPrimitiveINT())
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
        if (exp->var == Type::getPrimitiveFLOAT())
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
        expOut->var = Type::getPrimitiveINT();
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
        expOut->var = Type::getPrimitiveINT();
    }
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
        expOut->var = Type::getPrimitiveINT();
    }
    else if (c && d)
    {
        expOut->var = Type::getPrimitiveFLOAT();
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
            expOut->var = Type::getPrimitiveINT();
        }
        else if (b)
        {
            expOut->var = Type::getPrimitiveFLOAT();
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
            expOut->var = Type::getPrimitiveINT();
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

/// @brief 将所有可能含有返回值的EXP节点以vector的形式返回
vector<Node *> getReturnExpFromCompSt(Node *CompSt)
{
    Node *StmtList = CompSt->child[2];
    Node *temp = StmtList;
    vector<Node *> Exps;
    while (temp->child.size() != 0) //还存在Stmt
    {
        Node *Stmt = temp->child[0];

        if (Stmt->child.size() == 3 && Stmt->child[0]->name == "RETURN")
        {
            printf("找到Return关键字");
            Exps.push_back(Stmt->child[1]);
        }
        temp = temp->child[1];
    }
    return Exps;
}