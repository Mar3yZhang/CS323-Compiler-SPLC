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