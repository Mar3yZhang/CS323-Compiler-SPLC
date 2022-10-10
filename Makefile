CC=gcc
FLEX=flex
splc:
	@rm -rf bin/
	@mkdir bin
	touch bin/splc
	@chmod +x bin/splc
	$(FLEX) lex.l
	$(CC) lex.yy.c -lfl -o bin/splc.out
clean:
	@rm -rf bin/
.PHONY: spl