
CC=gcc
CPP = g++ -std=c++17
FLEX=flex
BISON=bison
SRC_PATH=src
BIN_PATH=bin

Node = Node.cpp
SAUtill = semantic-analysis/SAUtill.cpp
SyntaxTree = semantic-analysis/syntaxTree.cpp
SemanticError = semantic-analysis/semanticError.cpp
Type = semantic-analysis/Type.cpp
Main = main.cpp

splc:
	@rm -rf ../$(BIN_PATH)
	@mkdir ../$(BIN_PATH)
	touch ../$(BIN_PATH)/splc
	@chmod +x ../$(BIN_PATH)/splc
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	
	$(CPP) $(Type) $(Node) $(SemanticError) $(SyntaxTree) $(SAUtill) $(Main) -lfl -ly -o ../$(BIN_PATH)/splc
clean:
	@rm -rf ../bin/
.PHONY: splc
all: splc