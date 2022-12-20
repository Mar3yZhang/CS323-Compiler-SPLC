
CC=gcc
CPP = g++ -std=c++17
FLEX=flex
BISON=bison
SRC_PATH=src
BIN_PATH=bin

Main = main.cpp
Node = Node.cpp

SAUtill = semantic-analysis/SAUtill.cpp
SyntaxTree = semantic-analysis/syntaxTree.cpp
SemanticError = semantic-analysis/semanticError.cpp
Type = semantic-analysis/Type.cpp

TAC =  $(basic-exp-translator) $(conditional-exp-translator) $(function-call-translator) $(function-define-translator) $(statement-translator) $(variable-declare-translator) $(ir-util)

basic-exp-translator = ir-translator/basic-exp-translator.cpp
conditional-exp-translator = ir-translator/conditional-exp-translator.cpp
function-call-translator =  ir-translator/function-call-translator.cpp
function-define-translator =  ir-translator/function-define-translator.cpp
statement-translator =  ir-translator/statement-translator.cpp
variable-declare-translator =  ir-translator/variable-declare-translator.cpp
ir-util =  ir-translator/ir-util.cpp

splc:
	@rm -rf ../$(BIN_PATH)
	@mkdir ../$(BIN_PATH)
	touch ../$(BIN_PATH)/splc
	@chmod +x ../$(BIN_PATH)/splc
	$(BISON) -d syntax.y
	$(FLEX) lex.l

	$(CPP) $(Type) $(Node) $(SemanticError) $(SyntaxTree) $(SAUtill) $(TAC) $(Main) -lfl -ly -o ../$(BIN_PATH)/splc -g
clean:
	@rm -rf ../bin/
.PHONY: splc
all: splc