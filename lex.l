%{
    // macro 
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #define YYSTYPE char *
    //#include "syntax.tab.h"
    #include "string.h"
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
hexadecimal_uint 0(x|X){hex}
int {decimal_uint}|{hexadecimal_uint}
normal_char  (\').(\')
hex_form_char (\')(\\)x{hex}(\')
char {normal_char}|{hex_form_char}
float  (0|[1-9][0-9]*)(\.){digit}+


%%
"/*" {
    char c;
    while(1){
    while ((c = input()) != '/'){};
    if(yytext[yyleng-1] == '*') {
        break;
        }
    }  
}
"//" { 
    char c;
    // ignore the following chars until seeing a newline character
    while((c = input()) != '\n'); 
    // put the newline character back to the input buffer
    unput(c); 
}
{ws} { /*no action and no return*/ }
"int"|"float"|"char" {printf("TYPE: %s\n",yytext);}
"struct" {printf("STRUCT\n");}
"if" {printf("IF\n");}
"else" {printf("ELSE\n");}
"while" {printf("WHILE\n");}
"return" {printf("RETURN\n");}
"for" {printf("FOR\n");}
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
"||" {printf("OR\n");}
"!" {printf("NOT\n");}
"(" {printf("LP\n");}
")" {printf("RP\n");}
"[" {printf("LB\n");}
"]" {printf("RB\n");}
"{" {printf("LC\n");}
"}" {printf("RC\n");}
"\"" {printf("DQ\n");}
"%" {printf("PS\n");}
{int} {printf("INT: %s\n",yytext);}
{digit}+{id} {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
{id} {printf("ID %s\n",yytext);}
{float} {printf("FLOAT: %s\n",yytext);}
{hex_form_char} {if ((int)strlen(yytext)>6) printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);} 
{char} { printf("CHAR: %s\n",yytext);}
(\').*(\') {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
. {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
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
