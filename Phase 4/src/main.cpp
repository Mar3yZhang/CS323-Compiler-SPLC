#include "syntax.tab.c"

int main(int argc, char **argv) {

    std::cout << "input path: " << argv[1] << std::endl;

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
//            Node::print(root_node, 0);

//             是否打印语义分析符号表
//            print_map_keys();

            // 是否翻译为三地址码
            translate_to_tac();
            // 是否导出三地址码为IR
            dump_ir_file(argv[1]);


//            print_data_func();
//            print_mips_code(ir_tac);

            // 是否打印翻译的MIPS32
            translate_to_mips32();

        } else {
            printf("\nParsing failed\n");
        }
    }
    return 0;
}