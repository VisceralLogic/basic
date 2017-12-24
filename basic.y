// A BASIC grammar interpreter

%{
#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

// token type definition
%union {
	int iVal;
	char *sVal;
}

// constant tokens
%token PRINT
%token RUN
%token ENDL

// terminal symbols
%token <iVal> LINE
%token <sVal> STRING

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
	LINE program		{ cout << "> Programming line " << $1 << " ^^^" << endl; }
	| RUN				{ cout << "> running..." << endl; }
;

program:
	PRINT STRING		{ cout << ">\tPRINT " << $2 << endl; }
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