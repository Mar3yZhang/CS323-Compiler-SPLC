%{
    // macro 
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #include "Node.hpp"
    #include "string.h"
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
"int"|"float"|"char" {yylval.node = new Node(TYPE::TYPE,"TYPE",yytext,yylineno); return TYPE;}
"struct"             {yylval.node = new Node(TYPE::OTHER,"STRUCT","struct",yylineno); return STRUCT;}
"if"                 {yylval.node =  new Node(TYPE::OTHER,"IF","if",yylineno); return IF;}
"else"               {yylval.node = new Node(TYPE::OTHER,"ELSE","else",yylineno); return ELSE;}
"while"              {yylval.node = new Node(TYPE::OTHER,"WHILE","while",yylineno); return WHILE;}
"return"             {yylval.node = new Node(TYPE::OTHER,"RETURN","return",yylineno); return RETURN;}
"for"                {yylval.node = new Node(TYPE::OTHER,"FOR","for",yylineno);return FOR;}
"."                  {yylval.node = new Node(TYPE::OTHER,"DOT",".",yylineno); return DOT;}
";"                  {yylval.node = new Node(TYPE::OTHER,"SEMI",";",yylineno); return SEMI;}
","                  {yylval.node = new Node(TYPE::OTHER,"COMMA",",",yylineno); return COMMA;}
"=="                 {yylval.node = new Node(TYPE::OTHER,"EQ","==",yylineno); return EQ;}
"="                  {yylval.node = new Node(TYPE::OTHER,"ASSIGN","=",yylineno); return ASSIGN;}
"<="                 {yylval.node = new Node(TYPE::OTHER,"LE","<=",yylineno); return LE;}
"<"                  {yylval.node = new Node(TYPE::OTHER,"LT","<",yylineno); return LT;}
">="                 {yylval.node = new Node(TYPE::OTHER,"GE",">=",yylineno); return GE;}
">"                  {yylval.node = new Node(TYPE::OTHER,"GT",">",yylineno); return GT;}
"!="                 {yylval.node = new Node(TYPE::OTHER,"NE","!=",yylineno); return NE;}
"+"                  {yylval.node = new Node(TYPE::OTHER,"PLUS","+",yylineno); return PLUS;}
"-"                  {yylval.node = new Node(TYPE::OTHER,"MINUS","-",yylineno); return MINUS;}
"*"                  {yylval.node = new Node(TYPE::OTHER,"MUL","*",yylineno); return MUL;}
"/"                  {yylval.node = new Node(TYPE::OTHER,"DIV","/",yylineno); return DIV;}
"&&"                 {yylval.node = new Node(TYPE::OTHER,"AND","&&",yylineno); return AND;}
"||"                 {yylval.node = new Node(TYPE::OTHER,"OR","||",yylineno); return OR;}
"!"                  {yylval.node = new Node(TYPE::OTHER,"NOT","!",yylineno); return NOT;}
"("                  {yylval.node = new Node(TYPE::OTHER,"LP","(",yylineno); return LP;}
")"                  {yylval.node = new Node(TYPE::OTHER,"RP",")",yylineno); return RP;}
"["                  {yylval.node = new Node(TYPE::OTHER,"LB","[",yylineno); return LB;}
"]"                  {yylval.node = new Node(TYPE::OTHER,"RB","]",yylineno); return RB;}
"{"                  {yylval.node = new Node(TYPE::OTHER,"LC","{",yylineno); return LC;}
"}"                  {yylval.node = new Node(TYPE::OTHER,"RC","}",yylineno); return RC;}
"\""                 {}

{int}                {yylval.node = new Node(TYPE::INT,"INT",yytext,yylineno); return INT;}
{digit}+{id}         {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
{id}                 {yylval.node = new Node(TYPE::ID,"ID",yytext,yylineno); return ID;}
{float}              {yylval.node = new Node(TYPE::FLOAT,"FLOAT",yytext,yylineno); return FLOAT;}
{hex_form_char}      {if ((int)strlen(yytext)>6) {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);return UNKNOWN;}else { yylval.node = new Node(TYPE::CHAR,"CHAR",yytext,yylineno); return CHAR;};} 
{char}               {yylval.node = new Node(TYPE::CHAR,"CHAR",yytext,yylineno); return CHAR;}
(\').*(\')           {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);return UNKNOWN;}
.                    {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);return UNKNOWN;}
%%


/*
"%"                  {printf("PS\n");}
"&"                  {printf("Addr\n");}


"int"|"float"|"char" {printf("TYPE: %s\n",yytext); yylval.node = new Node(TYPE::TYPE,"TYPE",yytext,yylineno); return TYPE;}
"struct"             {printf("STRUCT\n"); yylval.node = new Node(TYPE::OTHER,"STRUCT","struct",yylineno); return STRUCT;}
"if"                 {printf("IF\n"); yylval.node =  new Node(TYPE::OTHER,"IF","if",yylineno); return IF;}
"else"               {printf("ELSE\n"); yylval.node = new Node(TYPE::OTHER,"ELSE","else",yylineno); return ELSE;}
"while"              {printf("WHILE\n"); yylval.node = new Node(TYPE::OTHER,"WHILE","while",yylineno); return WHILE;}
"return"             {printf("RETURN\n"); yylval.node = new Node(TYPE::OTHER,"RETURN","return",yylineno); return RETURN;}
"for"                {printf("FOR\n");yylval.node = new Node(TYPE::OTHER,"FOR","for",yylineno);return FOR;}
"."                  {printf("DOT\n"); yylval.node = new Node(TYPE::OTHER,"DOT",".",yylineno); return DOT;}
";"                  {printf("SEMI\n"); yylval.node = new Node(TYPE::OTHER,"SEMI",";",yylineno); return SEMI;}
","                  {printf("COMMA\n"); yylval.node = new Node(TYPE::OTHER,"COMMA",",",yylineno); return COMMA;}
"=="                 {printf("EQ\n"); yylval.node = new Node(TYPE::OTHER,"EQ","==",yylineno); return EQ;}
"="                  {printf("ASSIGN\n"); yylval.node = new Node(TYPE::OTHER,"ASSIGN","=",yylineno); return ASSIGN;}
"<="                 {printf("LE\n"); yylval.node = new Node(TYPE::OTHER,"LE","<=",yylineno); return LE;}
"<"                  {printf("LT\n"); yylval.node = new Node(TYPE::OTHER,"LT","<",yylineno); return LT;}
">="                 {printf("GE\n"); yylval.node = new Node(TYPE::OTHER,"GE",">=",yylineno); return GE;}
">"                  {printf("GT\n"); yylval.node = new Node(TYPE::OTHER,"GT",">",yylineno); return GT;}
"!="                 {printf("NE\n"); yylval.node = new Node(TYPE::OTHER,"NE","!=",yylineno); return NE;}
"+"                  {printf("PLUS\n"); yylval.node = new Node(TYPE::OTHER,"PLUS","+",yylineno); return PLUS;}
"-"                  {printf("MINUS\n"); yylval.node = new Node(TYPE::OTHER,"MINUS","-",yylineno); return MINUS;}
"*"                  {printf("MUL\n"); yylval.node = new Node(TYPE::OTHER,"MUL","*",yylineno); return MUL;}
"/"                  {printf("DIV\n"); yylval.node = new Node(TYPE::OTHER,"DIV","/",yylineno); return DIV;}
"&&"                 {printf("AND\n"); yylval.node = new Node(TYPE::OTHER,"AND","&&",yylineno); return AND;}
"||"                 {printf("OR\n"); yylval.node = new Node(TYPE::OTHER,"OR","||",yylineno); return OR;}
"!"                  {printf("NOT\n"); yylval.node = new Node(TYPE::OTHER,"NOT","!",yylineno); return NOT;}
"("                  {printf("LP\n"); yylval.node = new Node(TYPE::OTHER,"LP","(",yylineno); return LP;}
")"                  {printf("RP\n"); yylval.node = new Node(TYPE::OTHER,"RP",")",yylineno); return RP;}
"["                  {printf("LB\n"); yylval.node = new Node(TYPE::OTHER,"LB","[",yylineno); return LB;}
"]"                  {printf("RB\n"); yylval.node = new Node(TYPE::OTHER,"RB","]",yylineno); return RB;}
"{"                  {printf("LC\n"); yylval.node = new Node(TYPE::OTHER,"LC","{",yylineno); return LC;}
"}"                  {printf("RC\n"); yylval.node = new Node(TYPE::OTHER,"RC","}",yylineno); return RC;}
"\""                 {printf("DQ\n");}

{int}                {printf("INT: %s\n",yytext); yylval.node = new Node(TYPE::INT,"INT",yytext,yylineno); return INT;}
{digit}+{id}         {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);}
{id}                 {printf("ID %s\n",yytext); yylval.node = new Node(TYPE::ID,"ID",yytext,yylineno); return ID;}
{float}              {printf("FLOAT: %s\n",yytext); yylval.node = new Node(TYPE::FLOAT,"FLOAT",yytext,yylineno); return FLOAT;}
{hex_form_char}      {if ((int)strlen(yytext)>6) printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);} 
{char}               {printf("CHAR: %s\n",yytext); yylval.node = new Node(TYPE::CHAR,"CHAR",yytext,yylineno); return CHAR;}
(\').*(\')           {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);return UNKNOWN;}
.                    {printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext);return UNKNOWN;}
*/


