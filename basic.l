%option noyywrap

%{
#include <cstdio>

#define YY_DECL extern "C" int yylex()

 class Program;

#include "basic.tab.h"

%}

%%

[ \t]+	;		// skip white space
[0-9]+			{ yylval.iVal = atoi(yytext); return LINE; }
\"[^\"\n]*\"	{	// remove the quote marks from either end
					yylval.sVal = (char *)malloc(sizeof(char)*strlen(yytext)-1);
					strncpy(yylval.sVal, yytext+1, strlen(yytext)-2);
					return STRING;
				}
PRINT			{ return PRINT; }
RUN				{ return RUN; }
LIST			{ return LIST; }
\n				return ENDL;

%%
