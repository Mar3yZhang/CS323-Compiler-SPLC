%{
    #define YYSTYPE char *
    #include "lex.yy.c"
    int yyerror(char* s);
%}

%locations

%token INT
%token FLOAT
%token CHAR 
%token ID 
%token TYPE 
%token STRUCT 
%token IF 
%token ELSE 
%token WHILE 
%token RETURN
%token DOT 
%token SEMI 
%token COMMA 
%token ASSIGN 
%token LT 
%token LE 
%token GT 
%token GE 
%token NE 
%token EQ
%token PLUS 
%token MINUS 
%token MUL 
%token DIV 
%token AND 
%token OR 
%token NOT 
%token LP 
%token RP 
%token LB 
%token RB 
%token LC 
%token RC

%left '+' '-'
%left '*' '/'


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
    ;
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


int main(int argc, char **argv) {
    printf("正在执行main函数\n");
    // return yyparse();

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
        if(yyparse() == 0){
            return EXIT_OK;
        }else{
            return EXIT_FAIL;
        }
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
