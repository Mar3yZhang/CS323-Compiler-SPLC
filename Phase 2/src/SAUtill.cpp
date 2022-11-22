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