#include <utility>

#include "../include/mips_code_generation.hpp"

using namespace std;



inline static const string pre_built_func =
#include "preBuiltFunc.asm"

inline static const string pre_built_data =

#include "preBuiltData.asm"

//存放变量名和变量存储的位置（reg 和 mem）
unordered_map <string , vector<string> > var_table;

void print_data_func() {
    std::cout << pre_built_data << std::endl;
    // for (const auto &vari_name : this->vari_names) {
    //     printf("_%s: .word 0\n", vari_name.c_str());
    // }
    std::cout << pre_built_func << std::endl;
}

void load_variable(const TAC * tac){

}


// enum class TAC_TYPE {
//     LABEL,
//     FUNCTION,
//     ASSIGN,
//     ADDITION,
//     SUBTRACTION,
//     MULTIPLICATION,
//     DIVISION,
//     GOTO,
//     CONDITION_LT,
//     CONDITION_LE,
//     CONDITION_GT,
//     CONDITION_GE,
//     CONDITION_NE,
//     CONDITION_EQ,
//     RETURN,
//     PARAM,
//     ARG,
//     CALL,
//     READ,
//     WRITE
// };
void print_mips_code(vector<TAC *> ir_tac){
    
    
    for (const TAC * tac :ir_tac)
    {
        // cout << tac->type == TAC_TYPE::ADDITION<< endl;
        switch (tac->type)
        {
        case TAC_TYPE::LABEL:{
            break;
        }
        case TAC_TYPE::FUNCTION:{
            break;
        }

        case TAC_TYPE::ADDITION:{
            break;
        }
        case TAC_TYPE::SUBTRACTION:{
            break;
        }case TAC_TYPE::MULTIPLICATION:{
            break;
        }case TAC_TYPE::DIVISION:{
            break;
        }case TAC_TYPE::ASSIGN:{
            break;
        }case TAC_TYPE::GOTO:{
            break;
        }case TAC_TYPE::CONDITION_EQ:{
            break;
        }case TAC_TYPE::CONDITION_GE:{
            break;
        }case TAC_TYPE::CONDITION_GT:{
            break;
        }
        }case TAC_TYPE::CONDITION_LE:{
            break;
        }case TAC_TYPE::CONDITION_LT:{
            break;
        }case TAC_TYPE::CONDITION_NE:{
            break;
        }case TAC_TYPE::RETURN:{
            break;
        }case TAC_TYPE::PARAM:{
            break;
        }case TAC_TYPE::ARG:{
            break;
        }case TAC_TYPE::CALL:{
            break;
        }case TAC_TYPE::READ:{
            break;
        }case TAC_TYPE::WRITE:{
            break;
        }

        default:
            break;
        }
    }
    
}





