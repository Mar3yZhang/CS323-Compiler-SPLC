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