%{
    #define YYSTYPE char *
    #include "lex.yy.c"
    void yyerror(const char *s);
%}
    %locations

%token INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN
%token DOT SEMI COMMA ASSIGN LT LE GT GE NE EQ
%token PLUS MINUS MUL DIV AND OR NOT LP RP LB RB LC RC


%type Program ExtDefList
%type ExtDef ExtDecList Specifier StructSpecifier VarDec
%type FunDec VarList ParamDec CompSt StmtList Stmt DefList
%type Def DecList Dec Args Exp

%%
/* high-level definition : The dollar sign “$” represents the empty string terminal  */

Program: ExtDefList
;
ExtDefList: /* to allow empty input */
    | ExtDef ExtDefList
;
ExtDef: Specifier ExtDecList SEMI
    | Specifier SEMI
    | Specifier FunDec CompSt
;
ExtDecList: VarDec
    | VarDec COMMA ExtDecList
;
/* specifier */

Specifier: TYPE
    | StructSpecifier
;
StructSpecifier: STRUCT ID LC DefList RC
    | STRUCT ID
;;
/* declarator */

VarDec: ID
    | VarDec LB INT RB
;
FunDec: ID LP VarList RP
    | ID LP RP
;
VarList: ParamDec COMMA VarList
    | ParamDec
;
ParamDec: Specifier VarDec
;
/* statement */

CompSt: LC DefList StmtList RC
;
StmtList: /* to allow empty input */
    |Stmt StmtList
;
Stmt: Exp SEMI
    | CompSt
    | RETURN Exp SEMI
    | IF LP Exp RP Stmt
    | IF LP Exp RP Stmt ELSE Stmt
    | WHILE LP Exp RP Stmt
;
/* local definition */
DefList: /* to allow empty input */
    | Def DefList
;
Def: Specifier DecList SEMI
;
DecList: Dec
    | Dec COMMA DecList
;
Dec: VarDec
    | VarDec ASSIGN Exp
;
/* Expression */
Exp: Exp ASSIGN Exp
    | Exp AND Exp
    | Exp OR Exp
    | Exp LT Exp
    | Exp LE Exp
    | Exp GT Exp
    | Exp GE Exp
    | Exp NE Exp
    | Exp EQ Exp
    | Exp PLUS Exp
    | Exp MINUS Exp
    | Exp MUL Exp
    | Exp DIV Exp
    | LP Exp RP
    | MINUS Exp
    | NOT Exp
    | ID LP Args RP
    | ID LP RP
    | Exp LB Exp RB
    | Exp DOT ID
    | ID
    | INT
    | FLOAT
    | CHAR
;
Args: Exp COMMA Args
    | Exp   
;
// please design a grammar for the valid ip addresses and provide necessary semantic actions for production rules
%%

void yyerror(const char *s){
    printf("Error type B at Line %d: \n",yylineno);
}

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
        return yyparse();
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}