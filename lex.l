%{
    // macro 
    #define EXIT_OK 0
    #define EXIT_FAIL 1

    // global variables
    int identifiers = 0;
    int lines = 0;

    //  should be ableto detect illegal form of hex-int, like 0x5gg, and report lexical errors.
%}

%option yylineno

delim   [ \t\n\r]
ws      {delim}+
letter_ [a-zA-Z_]
hex     (0|[1-9a-fA-F][0-9a-fA-F]*)
digit   [0-9]
id      {letter_}({letter_}|{digit})*
decimal_uint  {digit}+
hexadecimal_uint 0xX{hex}
int {decimal_uint}|{hexadecimal_uint}
normal_char  (?<=').*(?=')
hex_form_char \xX{hex}
char {normal_char}|{hex_form_char}


%%
"//" { 
    char c;
    // ignore the following chars until seeing a newline character
    while((c = input()) != '\n'); 
    // put the newline character back to the input buffer
    unput(c); 
}

{ws} { /*no action and no return*/ }
int|float|char {
    printf("TYPE %s\n", yytext);
    // if (strcmp(yytext, "int"))
    // {
    //     return INT;
    // }
    // else if (strcmp(yytext, "float"))
    // {
    //     return FLOAT;
    // }
    // else
    // {
    //     return CHAR;
    // }
}
"{" {printf("LC\n");}
"}" {printf("RC\n");}
"struct" {printf("STRUCT\n");}
"if" {printf("IF\n");}
"else" {printf("ELSE\n");}
"while" {printf("WHILE\n");}
"return" {printf("RETURN\n");}
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
"&&" {printf("AND\n");} 
"||" {printf("DIV\n");} 
"!" {printf("NOT\n");}
"(" {printf("LP\n");}
")" {printf("RP\n");}
"[" {printf("LB\n");}
"]" {printf("RB\n");}
{int} {
    // yylval = atoi(yytext);
    printf("INT %s\n", yytext);
}
{id} {
    // yylval = atoi(yytext);
    printf("ID %s\n", yytext);
}
. {printf("Error type A at Line %d: Unknown characters %s \n",yylineno, yytext);}

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
