%{
    // macro 
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    

    #include "syntax.tab.h"

    // help to keep track of the location of tokens in Bison
    // ref: https://www.gnu.org/software/bison/manual/html_node/Token-Locations.html
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylineno; \
        yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng;\
        yycolumn += yyleng;

    #include "string.h"
    // global variables
    int identifiers = 0;
    int lines = 0;

    extern "C" int yylex(void);



    //  should be ableto detect illegal form of hex-int, like 0x5gg, and report lexical errors.
%}
%option yylineno
%option noyywrap 

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
    while ((c = yyinput()) != '/'){};
    if(yytext[yyleng-1] == '*') {
        break;
        }
    }  
}
"//" { 
    char c;
    // ignore the following chars until seeing a newline character
    while((c = yyinput()) != '\n'); 
    // put the newline character back to the input buffer
    unput(c); 
}
{ws} { /*no action and no return*/ }
"int"|"float"|"char" {printf("TYPE: %s\n",yytext); return TYPE;}
"struct"             {printf("STRUCT\n"); return STRUCT;}
"if"                 {printf("IF\n"); return IF;}
"else"               {printf("ELSE\n"); return ELSE;}
"while"              {printf("WHILE\n"); return WHILE;}
"return"             {printf("RETURN\n"); return RETURN;}
"for"                {printf("FOR\n");}
"."                  {printf("DOT\n"); return DOT;}
";"                  {printf("SEMI\n"); return SEMI;}
","                  {printf("COMMA\n"); return COMMA;}
"=="                 {printf("EQ\n"); return EQ;}
"="                  {printf("ASSIGN\n"); return ASSIGN;}
"<="                 {printf("LE\n"); return LE;}
"<"                  {printf("LT\n"); return LT;}
">="                 {printf("GE\n"); return GE;}
">"                  {printf("GT\n"); return GT;}
"!="                 {printf("NE\n"); return NE;}
"+"                  {printf("PLUS\n"); return PLUS;}
"-"                  {printf("MINUS\n"); return MINUS;}
"*"                  {printf("MUL\n"); return MUL;}
"/"                  {printf("DIV\n"); return DIV;}
"&&"                 {printf("AND\n"); return AND;}
"||"                 {printf("OR\n"); return OR;}
"!"                  {printf("NOT\n"); return NOT;}
"("                  {printf("LP\n"); return LP;}
")"                  {printf("RP\n"); return RP;}
"["                  {printf("LB\n"); return LB;}
"]"                  {printf("RB\n"); return RB;}
"{"                  {printf("LC\n"); return LC;}
"}"                  {printf("RC\n"); return RC;}
"\""                 {printf("DQ\n");}
"%"                  {printf("PS\n");}
"&"                  {printf("Addr\n");}
{int}                {printf("INT: %s\n",yytext); return INT;}
{digit}+{id}         {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
{id}                 {printf("ID %s\n",yytext); return ID;}
{float}              {printf("FLOAT: %s\n",yytext); return FLOAT;}
{hex_form_char}      {if ((int)strlen(yytext)>6) printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);} 
{char}               {printf("CHAR: %s\n",yytext); return CHAR;}
(\').*(\')           {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
.                    {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
%%
