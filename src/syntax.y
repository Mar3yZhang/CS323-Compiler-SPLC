%{
    #include "lex.yy.c"
    void yyerror(const char *s);
    Node* ast_root;
%}

%locations

%union{
    Node* node;
}

%token <node> INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN
%token <node> DOT SEMI COMMA ASSIGN LT LE GT GE NE EQ
%token <node> PLUS MINUS MUL DIV AND OR NOT LP RP LB RB LC RC


%type <node> Program ExtDefList
%type <node> ExtDef ExtDecList Specifier StructSpecifier VarDec
%type <node> FunDec VarList ParamDec CompSt StmtList Stmt DefList
%type <node> Def DecList Dec Args Exp

%nonassoc UELSE
%nonassoc ELSE
%nonassoc UMINUS
%right ASSIGN 
%left OR AND 
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left MUL DIV
%right NOT
%left LP RP LB RB DOT

%%
Program: ExtDefList{
    $$ = new Node(TYPE::MEDIAN,"Program","",@$.first_line);
    $$->addChild({$1});
    ast_root = $$;
}
;       
ExtDefList: /* to allow empty input */        {$$=new Node(TYPE::NOTHING,"ExtDefList","",@$.first_line);}
    | ExtDef ExtDefList                       {$$=new Node(TYPE::MEDIAN,"ExtDefList","",@$.first_line); $$->addChild({$1,$2});}
    ;         
ExtDef: Specifier ExtDecList SEMI             {$$=new Node(TYPE::MEDIAN,"ExtDef","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Specifier SEMI                          {$$=new Node(TYPE::MEDIAN,"ExtDef","",@$.first_line); $$->addChild({$1,$2});}
    | Specifier FunDec CompSt                 {$$=new Node(TYPE::MEDIAN,"ExtDef","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
ExtDecList: VarDec                            {$$=new Node(TYPE::MEDIAN,"ExtDecList","",@$.first_line); $$->addChild({$1});}
    | VarDec COMMA ExtDecList                 {$$=new Node(TYPE::MEDIAN,"ExtDecList","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
/* specifier */       
    
Specifier: TYPE                               {$$=new Node(TYPE::MEDIAN,"Specifier","",@$.first_line); $$->addChild({$1});}
    | StructSpecifier                         {$$=new Node(TYPE::MEDIAN,"Specifier","",@$.first_line); $$->addChild({$1});}
    ;         
StructSpecifier: STRUCT ID LC DefList         RC{$$=new Node(TYPE::MEDIAN,"StructSpecifier","",@$.first_line); $$->addChild({$1,$2,$3,$4,$5});}
    | STRUCT ID                               {$$=new Node(TYPE::MEDIAN,"StructSpecifier","",@$.first_line); $$->addChild({$1,$2});}
    ;         
/* declarator */          
    
VarDec: ID                                    {$$=new Node(TYPE::MEDIAN,"VarDec","",@$.first_line); $$->addChild({$1});}
    | VarDec LB INT RB                        {$$=new Node(TYPE::MEDIAN,"VarDec","",@$.first_line); $$->addChild({$1,$2,$3,$4});}
    ;         
FunDec: ID LP VarList RP                      {$$=new Node(TYPE::MEDIAN,"FunDec","",@$.first_line); $$->addChild({$1,$2,$3,$4});}
    | ID LP RP                                {$$=new Node(TYPE::MEDIAN,"FunDec","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
VarList: ParamDec COMMA VarList               {$$=new Node(TYPE::MEDIAN,"VarList","",@$.first_line); $$->addChild({$1,$2,$3});}
    | ParamDec                                {$$=new Node(TYPE::MEDIAN,"VarList","",@$.first_line); $$->addChild({$1});}
    ;         
ParamDec: Specifier VarDec                    {$$=new Node(TYPE::MEDIAN,"ParamDec","",@$.first_line); $$->addChild({$1,$2});}
;         
/* statement */       
    
CompSt: LC DefList StmtList RC                {$$=new Node(TYPE::MEDIAN,"CompSt","",@$.first_line); $$->addChild({$1,$2,$3,$4});}
;         
StmtList: /* to allow empty input */          {$$=new Node(TYPE::NOTHING,"StmtList","",@$.first_line);}
    |Stmt StmtList                            {$$=new Node(TYPE::MEDIAN,"StmtList","",@$.first_line); $$->addChild({$1,$2});}
    ;         
Stmt: Exp SEMI                                {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1,$2});}
    | CompSt                                  {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1});}
    | RETURN Exp SEMI                         {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1,$2,$3});}
    | IF LP Exp RP Stmt  %prec UELSE          {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1,$2,$3,$4,$5});}
    | IF LP Exp RP Stmt ELSE Stmt             {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1,$2,$3,$4,$5,$6,$7});}
    | WHILE LP Exp RP Stmt                    {$$=new Node(TYPE::MEDIAN,"Stmt","",@$.first_line); $$->addChild({$1,$2,$3,$4,$5});}
    ;         
/* local definition */        
DefList: /* to allow empty input */           {$$=new Node(TYPE::NOTHING,"DefList","",@$.first_line);}
    | Def DefList                             {$$=new Node(TYPE::MEDIAN,"DefList","",@$.first_line); $$->addChild({$1,$2});}
    ;         
Def: Specifier DecList SEMI                   {$$=new Node(TYPE::MEDIAN,"Def","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
DecList: Dec                                  {$$=new Node(TYPE::MEDIAN,"DecList","",@$.first_line); $$->addChild({$1});}
    | Dec COMMA DecList                       {$$=new Node(TYPE::MEDIAN,"DecList","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
Dec: VarDec                                   {$$=new Node(TYPE::MEDIAN,"Dec","",@$.first_line); $$->addChild({$1});}
    | VarDec ASSIGN Exp                       {$$=new Node(TYPE::MEDIAN,"Dec","",@$.first_line); $$->addChild({$1,$2,$3});}
    ;         
/* Expression */          
Args: Exp COMMA Args                          {$$=new Node(TYPE::MEDIAN,"Args","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp                                     {$$=new Node(TYPE::MEDIAN,"Args","",@$.first_line); $$->addChild({$1});}
    ;         
Exp: Exp ASSIGN Exp                           {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp AND Exp                             {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp OR Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp LT Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp LE Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp GT Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp GE Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp NE Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp EQ Exp                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp PLUS Exp                            {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp MINUS Exp                           {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp MUL Exp                             {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp DIV Exp                             {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | LP Exp RP                               {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | MINUS Exp %prec UMINUS                  {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2});}
    | NOT Exp                                 {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2});}
    | ID LP Args RP                           {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3,$4});}
    | ID LP RP                                {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | Exp LB Exp RB                           {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3,$4});}
    | Exp DOT ID                              {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1,$2,$3});}
    | ID                                      {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1});}
    | INT                                     {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1});}
    | FLOAT                                   {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1});}
    | CHAR                                    {$$=new Node(TYPE::MEDIAN,"Exp","",@$.first_line); $$->addChild({$1});}
    ;       
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
        printf("\nTokens: \n");
        yyrestart(f);
        if(!yyparse()){
            printf("\nParsing complete\n");
        }else{
            printf("\nParsing failed\n");
        }
        printf("\n\nAbstract Syntex Tree: \n");
        Node::print(ast_root,0);
    }
    return 0;
}