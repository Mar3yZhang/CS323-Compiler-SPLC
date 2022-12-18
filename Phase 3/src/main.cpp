#include "syntax.tab.c"

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("no input path");
        return 1;
    } else if (argc > 2) {
        printf("too much input path");
        return 1;
    } else {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            printf("error of path %s", argv[1]);
            return 1;
        }
        // printf("\nTokens: \n");
        yyrestart(f);
        if (!yyparse() && (!type_A_error) && (!type_B_error)) {

//            printf("\nParsing complete\n");
//            printf("\n\nAbstract Syntex Tree: \n");

            // 是否选择打印语法分析树：
            //Node::print(ast_root,0);


            // 是否打印语义分析符号表
            print_map_keys();

        } else {
            printf("\nParsing failed\n");
        }
    }
    return 0;
}