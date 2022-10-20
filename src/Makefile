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
	$(CPP) syntax.tab.c -lfl -ly -Wall -o ../bin/splc.out

clean:
	@rm -rf bin/
.PHONY: spl