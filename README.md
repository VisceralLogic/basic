# basic
Tutorial on using flex/bison to build a BASIC interpreter

## grammar
lines: /* empty */  
  | line  
  | lines line  
  ;

line: LINENUM statement  
  | statement  
  ;
  
statement: iStatement  
  | forStmt  
  | nextStmt  
  | endStmt  
  ;

iStatement: letStmt  
  | readStmt  
  | dataStmt  
  | printStmt  
  | gotoStmt  
  | ifStmt  
  | error  
  ;
  
ids: ID  
  | ids ',' ID  
  ;
  
exprs: expr  
  | exprs ',' expr  
  ;
  
exprsAndLabels: exprOrLabel  
  | exprsAndLabels ',' exprOrLabel  
  ;
  
exprOrLabel: expr  
  | STRING  
  ;

letStmt: "LET" ID '=' expr;

readStmt: "READ" ids;

dataStmt: "DATA" exprs;

printStmt: "PRINT" exprsAndLabels;

gotoStmt: "GOTO" LINENUM;

ifStmt: "IF" expr rel expr "THEN" LINENUM;
