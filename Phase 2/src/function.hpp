#include <string>
#include <vector>
#include "type.hpp"
using std::string;
using std::vector;

/// @brief 用来判断函数参数列表和返回值是否正确的结构体
class Function
{
public:
    string name;            // 函数名
    vector<Type*> parameter; // 参数列表
    Type* return_type;       // 返回值

public:
    Function(string name, vector<Type*> parameter, Type* return_type);
    ~Function() = default;
};
