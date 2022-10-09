%{
    // macro 
    #define EXIT_OK 0
    #define EXIT_FAIL 1

    // global variables
    int identifiers = 0;
    int lines = 0;
%}

%option yylineno

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
hexadecimal_int 0[xX][0-9a-fA-F]+
hex_form_char \x


%%
[\t\r\n ]+ { /* does nothing when seeing white spaces or new line */ }
int|float|char {printf("TYPE %s\n", yytext);}
struct {printf("STRUCT\n");}
if {printf("IF\n");}
else {printf("ELSE\n");}
while {printf("WHILE\n");}
return {printf("RETURN\n");}
"." {printf("DOT\n");}
";" {printf("SEMI\n");}
"," {printf("COMMA\n");}
"==" {printf("EQ\n");}
"=" {printf("ASSIGN\n");}
"<=" {printf("LE\n");}
"<" {printf("LT\n");}
">=" {printf("GE\n");}
">" {printf("GT\n");}
"!=" {printf("NE\n");}
"+" {printf("PLUS\n");}
"-" {printf("MINUS\n");}
"*" {printf("MUL\n");}
"/" {printf("DIV\n");}

// . { /* a final rule that matches when seeing any character but new line */ }
// <<EOF>> { printf("There are %d occurrences of valid identifiers\n", identifiers); yyterminate(); }

%%
int main(int argc, char **argv){
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        yylex();
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
