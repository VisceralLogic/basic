// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);

#include "basic.h"
#include "expression.h"
#include "stringexpression.h"
#include "doubleexpression.h"
#include "print.h"
#include "program.h"

%}

// token type definition
%union {
	int iVal;
	double dVal;
	char *sVal;
	Program *progVal;
	Expression *eVal;
	std::vector<Expression*> *eList;
}

// constant tokens
%token PRINT
%token RUN
%token ENDL
%token LIST
%token COMMA

// terminal symbols
%token <iVal> LINE
%token <sVal> STRING
%token <dVal> DOUBLE

// non-terminal symbols
%type <progVal> program 
%type <eList> exprList
%type <eVal> expr

%% /* Grammar rules and actions follow */

input:
	/* empty */
	| input line
;

line:
	ENDL
	| stmt ENDL
;

stmt:
	LINE				{ Basic::instance()->remove($1); }
	| LINE program		{ Basic::instance()->add($1, $2); }
	| RUN				{ Basic::instance()->execute(); }
	| LIST				{ Basic::instance()->list(); }
;

program:
	PRINT exprList		{ $$ = new Print($2); }
;

exprList:
	expr					{ $$ = new std::vector<Expression*>(1, $1); }
	| exprList COMMA expr	{
								$1->push_back($3);
								$$ = $1;
							}
;

expr:
	STRING			{
						$$ = new StringExpression($1);
						free($1);	// malloced in basic.l
					}
	| DOUBLE		{ $$ = new DoubleExpression($1); }
;

%%

int main(int argc, char **argv){
	std::cout << "Welcome to BASIC!\n>";
	do {
		yyparse();
	} while( !feof(yyin) );
	
	return 0;
}

void yyerror(const char *s){
	std::cout << "Error: " << s << std::endl;
}