.PHONY: all clean

all:	basic.tab.c lex.yy.c \
		basic.h basic.cpp \
		program.h program.cpp \
		print.h print.cpp \
		expression.h expression.cpp \
		stringexpression.h stringexpression.cpp \
		doubleexpression.h doubleexpression.cpp \
		operatorexpression.h operatorexpression.cpp \
		let.h let.cpp \
		variableexpression.h variableexpression.cpp \
		parenexpression.h parenexpression.cpp \
		goto.h goto.cpp \
		end.h end.cpp \
		ifthen.h ifthen.cpp \
		read.h read.cpp \
		data.h data.cpp
	g++ -std=c++11 basic.tab.c lex.yy.c program.cpp basic.cpp print.cpp expression.cpp \
	stringexpression.cpp doubleexpression.cpp operatorexpression.cpp let.cpp \
	variableexpression.cpp parenexpression.cpp goto.cpp end.cpp ifthen.cpp  read.cpp \
	data.cpp \
	-o basic

basic.tab.c: basic.y basic.h expression.h stringexpression.h doubleexpression.h \
		operatorexpression.h print.h program.h let.h variableexpression.h parenexpression.h \
		goto.h end.h ifthen.h read.h data.h
	bison -d basic.y
	
basic.tab.h: basic.y
	bison -d basic.y

lex.yy.c: basic.tab.h basic.l
	flex basic.l

clean:
	rm basic.tab.c basic.tab.h lex.yy.c basic *.o