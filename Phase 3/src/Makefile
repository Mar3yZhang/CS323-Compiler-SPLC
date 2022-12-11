
CC=gcc
CPP = g++ -std=c++17
FLEX=flex
BISON=bison
SRC_PATH=src
BIN_PATH=bin

Type = Type.cpp
Node = Node.cpp
SAUtill = SAUtill.cpp
SyntaxTree = syntaxTree.cpp
SemanticError = semanticError.cpp
Main = main.cpp

splc:
	@rm -rf $(BIN_PATH)
	@mkdir $(BIN_PATH)
	touch $(BIN_PATH)/splc
	@chmod +x $(BIN_PATH)/splc
	$(BISON) -d $(SRC_PATH)/syntax.y
	$(FLEX) $(SRC_PATH)/lex.l
	
	$(CPP) \
 	$(SRC_PATH)/$(Type) \
 	$(SRC_PATH)/$(Node) \
    $(SRC_PATH)/$(SemanticError) \
	$(SRC_PATH)/$(SyntaxTree) \
	$(SRC_PATH)/$(SAUtill) \
	$(SRC_PATH)/$(Main) -lfl -ly -o $(BIN_PATH)/splc
clean:
	@rm -rf bin/
.PHONY: splc
all: splc