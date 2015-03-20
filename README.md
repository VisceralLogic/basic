# basic
Tutorial on using flex/bison to build a BASIC interpreter

## grammar
statements: /* empty */  
  | statement  
  | statements statement  
  ;
  
statement: iStatement  
  | LINENUM iStatement  
  | LINENUM forStmt  
  | LINENUM nextStmt  
  | LINENUM endStmt  
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
  
expr: addend  
  | addend '+' addend  
  | addend '-' addend  
  ;
  
addend: multiplicand  
  | multiplicand '*' multiplicand  
  | multiplicand '/' multiplicand  
  ;
  
multiplicand: expt  
  | expt '^' expt  
  ;
  
expt: NUM  
  | ID  
  | '(' expr ')'  
  ;

letStmt: "LET" ID '=' expr;

readStmt: "READ" ids;

dataStmt: "DATA" exprs;

printStmt: "PRINT" exprsAndLabels;

gotoStmt: "GOTO" LINENUM;

ifStmt: "IF" relExpr "THEN" LINENUM;

relExpr: expr '=' expr  
  | expr '<' expr  
  | expr '>' expr  
  | expr ">=" expr  
  | expr "<=" expr  
  | expr "<>" expr  
  ;
  
forStmt: "FOR" ID '=' expr "TO" expr  
  | "FOR" ID '=' expr "TO" expr "STEP" expr  
  ;
  
nextStmt: "NEXT" ID;  

endStmt: "END";
