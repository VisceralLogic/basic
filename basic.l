%{
#include <cstdio>
using namespace std;

#define YY_DECL extern "C" int yylex()

#include "basic.tab.h"
%}

%%

[ \t]+	;		// skip white space
[0-9]+			{ yylval.iVal = atoi(yytext); return LINE; }
\"[^\"\n]*\"	{ yylval.sVal = strdup(yytext); return STRING; }
PRINT			{ return PRINT; }
RUN				{ return RUN; }
\n				return ENDL;

%%
