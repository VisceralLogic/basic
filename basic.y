// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yywrap();

void yyerror(const char *s);

#include "basic.h"
#include "expression.h"
#include "stringexpression.h"
#include "doubleexpression.h"
#include "operatorexpression.h"
#include "variableexpression.h"
#include "print.h"
#include "program.h"
#include "let.h"

%}

// token type definition
%union {
	int iVal;
	double dVal;
	char *sVal;
	Program *progVal;
	Expression *eVal;
	DoubleExpression *dxVal;
	std::vector<Expression*> *eList;
}

// constant tokens
%token PRINT
%token RUN
%token ENDL
%token LIST
%token COMMA
%token PLUS
%token MINUS
%token MULT
%token DIV
%token EXP
%token SAVE
%token UNSAVE
%token NEW
%token OLD
%token LET
%token EQUAL

// terminal symbols
%token <iVal> LINE
%token <sVal> STRING
%token <dVal> DOUBLE
%token <sVal> VAR

// non-terminal symbols
%type <progVal> program 
%type <eList> exprList
%type <eVal> expr
%type <dxVal> doubleExpr
%type <dxVal> addExpr
%type <dxVal> mulExpr
%type <dxVal> expExpr
%type <dxVal> term

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
	| LIST				{ Basic::instance()->list(std::cout); }
	| NEW				{ Basic::instance()->newProgram(); }
	| OLD				{ Basic::instance()->oldProgram(); }
	| SAVE				{ Basic::instance()->saveProgram(); }
	| UNSAVE			{ Basic::instance()->unsaveProgram(); }
;

program:
	PRINT exprList			{ $$ = new Print($2); }
	| LET VAR EQUAL doubleExpr	{
									$$ = new Let($2, $4);
									free($2);	// malloced in basic.l
								}
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
	| doubleExpr
	
doubleExpr:
	addExpr
;

addExpr:
	mulExpr
	| mulExpr PLUS mulExpr	{ $$ = new OperatorExpression($1, $3, '+'); }
	| mulExpr MINUS mulExpr	{ $$ = new OperatorExpression($1, $3, '-'); }
;

mulExpr:
	expExpr
	| expExpr MULT expExpr	{ $$ = new OperatorExpression($1, $3, '*'); }
	| expExpr DIV expExpr	{ $$ = new OperatorExpression($1, $3, '/'); }
;

expExpr:
	term
	| term EXP term			{ $$ = new OperatorExpression($1, $3, '^'); }
;

term:
	DOUBLE			{ $$ = new DoubleExpression($1); }
	| VAR			{
						$$ = new VariableExpression($1);
						free($1);
					}
;

%%

int main(int argc, char **argv){
	std::cout << "Welcome to BASIC!\n";
	Basic::instance()->newProgram();
	std::cout << '>';
	do {
		yyparse();
	} while( !feof(yyin) );
	
	return 0;
}

void yyerror(const char *s){
	std::cout << "Error: " << s << std::endl;
}

int yywrap(){
	if( yyin == stdin )
		return 1;
	fclose(yyin);
	yyin = stdin;
	return 0;
}