// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);

#include "basic.h"
#include "expression.h"
#include "print.h"
#include "program.h"

%}

// token type definition
%union {
	int iVal;
	char *sVal;
	Program *progVal;
}

// constant tokens
%token PRINT
%token RUN
%token ENDL
%token LIST

// terminal symbols
%token <iVal> LINE
%token <sVal> STRING

// non-terminal symbols
%type <progVal> program 

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
	LINE program		{ Basic::instance()->add($1, $2); }
	| RUN				{ Basic::instance()->execute(); }
	| LIST				{ Basic::instance()->list(); }
;

program:
	PRINT STRING		{
							Expression e($2);
							vector<Expression> v(1, e);
							free($2);	// malloced in basic.l
							$$ = new Print(v);
						}
;

%%

int main(int argc, char **argv){
	do {
		yyparse();
	} while( !feof(yyin) );
	
	return 0;
}

void yyerror(const char *s){
	cout << "Error: " << s << endl;
}