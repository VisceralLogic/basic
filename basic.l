%option case-insensitive

%{
#include <cstdio>
#include <iostream>
#include <vector>

#define YY_DECL extern "C" int yylex()

class Program;
class Expression;
class DoubleExpression;

#include "basic.tab.h"

%}

ALPHA    [A-Z]	
DIGIT    [0-9]

%%

[ \t]+	;		// skip white space
{DIGIT}+		{ yylval.iVal = atoi(yytext); return INT; }
\"[^\"\n]*\"	{	// remove the quote marks from either end
					yylval.sVal = (char *)malloc(sizeof(char)*strlen(yytext)-1);
					strncpy(yylval.sVal, yytext+1, strlen(yytext)-2);
					yylval.sVal[strlen(yytext)-2] = '\0';	// terminate the string!
					return STRING;
				}
(({DIGIT}+"."?)|("."{DIGIT}+)){DIGIT}*(E-?{DIGIT}+)?	{ yylval.dVal = atof(yytext); return DOUBLE; }
PRINT			{ return PRINT; }
RUN				{ return RUN; }
LIST			{ return LIST; }
,				{ return COMMA; }
\n				{
					if( yyin == stdin )
						std::cout << ">";
					return ENDL;
				}
{ALPHA}{DIGIT}?	{ yylval.sVal = strdup(yytext); return VAR; }
\+				{ return PLUS; }
-				{ return MINUS; }
\*				{ return MULT; }
\/				{ return DIV; }
\^				{ return EXP; }
SAVE			{ return SAVE; }
UNSAVE			{ return UNSAVE; }
NEW				{ return NEW; }
OLD				{ return OLD; }
CATALOG			{ return CATALOG; }
SCRATCH			{ return SCRATCH; }
RENAME			{ return RENAME; }
LET				{ return LET; }
GOTO			{ return GOTO; }
END				{ return END; }
IF				{ return IF; }
THEN			{ return THEN; }
\=				{ return EQUAL; }
\<				{ return LESS; }
\>				{ return GREATER; }
\<\=			{ return LESSEQUAL; }
\>\=			{ return GREATEREQUAL; }
\<\>			{ return NOTEQUAL; }
\(				{ return OPENPAREN; }
\)				{ return CLOSEPAREN; }
.	;			// skip any characters that aren't part of a recognized pattern

%%
