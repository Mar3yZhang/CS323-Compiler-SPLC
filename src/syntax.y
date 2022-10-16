%{
    #define YYSTYPE char *
    #include "lex.yy.c"
    int yyerror(char* s);
%}

%token INT,FLOAT,CHAR,ID,TYPE,STRUCT,IF,ELSE,WHILE,RETURN
%token DOT,SEMI,COMMA,ASSIGN,LT,LE,GT,GE,NE,EQ
%token PLUS,MINUS,MUL,DIV,AND,OR,NOT,LP,RP,LB,RB,LC,RC

%%
Ip: /* to allow empty input */
    | Exp {}
    ;
Exp: Term
    | Exp DOT Term {dot_number++;}
    | Exp COLON Term {colon_number++;}
    ;
Term: X{};
// please design a grammar for the valid ip addresses and provide necessary semantic actions for production rules
%%

int yyerror(char* s) {
    fprintf(stderr, "%s\n", "Invalid");
    return 1;
}
int main() {
    yyparse();
}

