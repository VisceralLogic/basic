%option noyywrap case-insensitive

%{
#include <cstdio>
#include <iostream>

#define YY_DECL extern "C" int yylex()

class Program;
class Expression;

#include "basic.tab.h"

%}

DIGIT    [0-9]

%%

[ \t]+	;		// skip white space
^{DIGIT}+		{ yylval.iVal = atoi(yytext); return LINE; }
\"[^\"\n]*\"	{	// remove the quote marks from either end
					yylval.sVal = (char *)malloc(sizeof(char)*strlen(yytext)-1);
					strncpy(yylval.sVal, yytext+1, strlen(yytext)-2);
					yylval.sVal[strlen(yytext)-2] = '\0';	// terminate the string!
					return STRING;
				}
(({DIGIT}+"."?)|("."{DIGIT}+)){DIGIT}*(E-?{DIGIT}+)*	{ yylval.dVal = atof(yytext); return DOUBLE; }
PRINT			{ return PRINT; }
RUN				{ return RUN; }
LIST			{ return LIST; }
,				{ return COMMA; }
\n				{ std::cout << ">"; return ENDL; }
.	;			// skip any characters that aren't part of a recognized pattern

%%
