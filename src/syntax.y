%{
    #include "lex.yy.c"
    void yyerror(const char *s);
    Node* root;
%}

%locations

%union{
    Node* node;
}

%token INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN
%token DOT SEMI COMMA ASSIGN LT LE GT GE NE EQ
%token PLUS MINUS MUL DIV AND OR NOT LP RP LB RB LC RC


%type <node> Program ExtDefList
%type <node> ExtDef ExtDecList Specifier StructSpecifier VarDec
%type <node> FunDec VarList ParamDec CompSt StmtList Stmt DefList
%type <node> Def DecList Dec Args Exp

%%
/* high-level definition : The dollar sign “$” represents the empty string terminal  */
Program: ExtDefList{
    root=$$;
}
;
ExtDefList: /* to allow empty input */{}
    | ExtDef ExtDefList{}
    ;
ExtDef: Specifier ExtDecList SEMI{}
    | Specifier SEMI{}
    | Specifier FunDec CompSt{}
    ;
ExtDecList: VarDec{}
    | VarDec COMMA ExtDecList{}
    ;
/* specifier */

Specifier: TYPE{}
    | StructSpecifier{}
    ;
StructSpecifier: STRUCT ID LC DefList RC{}
    | STRUCT ID{}
    ;
/* declarator */

VarDec: ID{}
    | VarDec LB INT RB{}
    ;
FunDec: ID LP VarList RP{}
    | ID LP RP{}
    ;
VarList: ParamDec COMMA VarList{}
    | ParamDec{}
    ;
ParamDec: Specifier VarDec{}
;
/* statement */

CompSt: LC DefList StmtList RC{}
;
StmtList: /* to allow empty input */{}
    |Stmt StmtList{}
    ;
Stmt: Exp SEMI{}
    | CompSt{}
    | RETURN Exp SEMI{}
    | IF LP Exp RP Stmt{}
    | IF LP Exp RP Stmt ELSE Stmt{}
    | WHILE LP Exp RP Stmt{}
    ;
/* local definition */
DefList: /* to allow empty input */{}
    | Def DefList{}
    ;
Def: Specifier DecList SEMI{}
    ;
DecList: Dec{}
    | Dec COMMA DecList{}
    ;
Dec: VarDec{}
    | VarDec ASSIGN Exp{}
    ;
/* Expression */
Args: Exp COMMA Args{}
    | Exp{}
    ;
Exp: Exp ASSIGN Exp{}
    | Exp AND Exp{}
    | Exp OR Exp{}
    | Exp LT Exp{}
    | Exp LE Exp{}
    | Exp GT Exp{}
    | Exp GE Exp{}
    | Exp NE Exp{}
    | Exp EQ Exp{}
    | Exp PLUS Exp{}
    | Exp MINUS Exp{}
    | Exp MUL Exp{}
    | Exp DIV Exp{}
    | LP Exp RP{}
    | MINUS Exp{}
    | NOT Exp{}
    | ID LP Args RP{}
    | ID LP RP{}
    | Exp LB Exp RB{}
    | Exp DOT ID{}
    | ID{}
    | INT{}
    | FLOAT{}
    | CHAR{}
    ;
// please design a grammar for the valid ip addresses and provide necessary semantic actions for production rules
%%

void yyerror(const char *s){
    // printf("Error type B at Line %d: \n",yylineno);

	printf("ERROR: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}


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
        yyrestart(f);
        if(!yyparse()){
            printf("\nParsing complete\n");
        }else{
            printf("\nParsing failed\n");
        }
    }
    return 0;
}