.PHONY: all clean

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	FLEX := l
else
	FLEX := fl
endif

all: basic.tab.c lex.yy.c
	g++ basic.tab.c lex.yy.c -l$(FLEX) -o basic

basic.tab.c: basic.y
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic