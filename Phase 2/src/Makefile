CC=gcc
CPP = g++
FLEX=flex
BISON=bison
SRC_PATH=src

Type = Type.hpp Type.cpp
Node = Node.hpp Node.cpp
Function = Function.hpp Function.cpp
SAUtill = SAUtill.hpp SAUtill.cpp
SyntaxTree = syntaxTree.hpp syntaxTree.cpp
SemanticError = semanticError.hpp semanticError.cpp

splc:
	@rm -rf ../bin/
	@mkdir ../bin
	touch ../bin/splc
	@chmod +x ../bin/splc
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	
	$(CPP) $(Type) $(Node) $(SemanticError) $(Function) $(SyntaxTree) $(SAUtill) syntax.tab.c -lfl -ly -o ../bin/splc
clean:
	@rm -rf ../bin/
.PHONY: spl