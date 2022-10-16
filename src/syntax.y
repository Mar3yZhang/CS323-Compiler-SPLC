%{
    // #define YYSTYPE char *
    #include "lex.yy.cc"
    int yyerror(char* s);
%}

%token INT,FLOAT,CHAR,ID,TYPE,STRUCT,IF,ELSE,WHILE,RETURN
%token DOT,SEMI,COMMA,ASSIGN,LT,LE,GT,GE,NE,EQ
%token PLUS,MINUS,MUL,DIV,AND,OR,NOT,LP,RP,LB,RB,LC,RC



%%
/* high-level definition : The dollar sign “$” represents the empty string terminal  */
Program -> ExtDefList
ExtDefList -> ExtDef ExtDefList
| $
ExtDef -> Specifier ExtDecList SEMI
| Specifier SEMI
| Specifier FunDec CompSt
ExtDecList -> VarDec
| VarDec COMMA ExtDecList
/* specifier */
Specifier -> TYPE
| StructSpecifier
StructSpecifier -> STRUCT ID LC DefList RC
| STRUCT ID
/* declarator */
VarDec -> ID
| VarDec LB INT RB
FunDec -> ID LP VarList RP
| ID LP RP
VarList -> ParamDec COMMA VarList
| ParamDec
ParamDec -> Specifier VarDec
/* statement */
CompSt -> LC DefList StmtList RC
StmtList -> Stmt StmtList
| $
Stmt -> Exp SEMI
| CompSt
| RETURN Exp SEMI
| IF LP Exp RP Stmt
| IF LP Exp RP Stmt ELSE Stmt
| WHILE LP Exp RP Stmt
/* local definition */
DefList -> Def DefList
| $
Def -> Specifier DecList SEMI
DecList -> Dec
| Dec COMMA DecList
Dec -> VarDec
| VarDec ASSIGN Exp
/* Expression */
Exp -> Exp ASSIGN Exp
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
Args -> Exp COMMA Args
| Exp   
// please design a grammar for the valid ip addresses and provide necessary semantic actions for production rules
%%

int yyerror(char* s) {
    fprintf(stderr, "%s\n", "Invalid");
    return 1;
}
int main() {
    yyparse();
}

