CC=gcc
CPP = g++ -std=c++17
FLEX=flex
BISON=bison
SRC_PATH=src

Type = Type.cpp
Node = Node.cpp
SAUtill = SAUtill.cpp
SyntaxTree = syntaxTree.cpp
SemanticError = semanticError.cpp

splc:
	@rm -rf ../bin/
	@mkdir ../bin
	touch ../bin/splc
	@chmod +x ../bin/splc
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	
	$(CPP) $(Type) $(Node) $(SemanticError) $(SyntaxTree) $(SAUtill) syntax.tab.c -lfl -ly -o ../bin/splc
clean:
	@rm -rf ../bin/
.PHONY: splc
all: splc