.PHONY: all clean

all:	basic.tab.c lex.yy.c \
		basic.h basic.cpp \
		program.h program.cpp \
		print.h print.cpp \
		expression.h expression.cpp \
		stringexpression.h stringexpression.cpp \
		doubleexpression.h doubleexpression.cpp \
		operatorexpression.h operatorexpression.cpp
	g++ basic.tab.c lex.yy.c program.cpp basic.cpp print.cpp expression.cpp \
	stringexpression.cpp doubleexpression.cpp operatorexpression.cpp \
	-o basic

basic.tab.c: basic.y
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic *.o