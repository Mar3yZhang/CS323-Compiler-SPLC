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
	$(FLEX) lex.l
	$(CPP) lex.yy.c -lfl -o ../bin/splc.out
clean:
	@rm -rf ../bin/
.PHONY: spl