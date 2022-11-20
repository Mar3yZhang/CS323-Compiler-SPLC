CC=gcc
CPP = g++
FLEX=flex
BISON=bison
SRC_PATH=src

splc:
	@rm -rf ../bin/
	@mkdir ../bin
	touch ../bin/splc
	@chmod +x ../bin/splc
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	
	$(CPP) Node.hpp Node.cpp syntax.tab.c -lfl -ly -o ../bin/splc
clean:
	@rm -rf ../bin/
.PHONY: spl