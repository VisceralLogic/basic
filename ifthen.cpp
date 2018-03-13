#include <cstring>

#include "ifthen.h"
#include "basic.h"

// create a new statement instance
IfThen::IfThen(DoubleExpression *a, DoubleExpression *b, char *op, int line){
	this->a = a;
	this->b = b;
	this->op = op;
	this->line = line;
}

// clean up the expression pointers
IfThen::~IfThen(){
	delete a;
	delete b;
}

// run this line of the program
void IfThen::execute() const{
	double aVal = a->value();
	double bVal = b->value();
	bool result = false;
	
	if( strcmp(op, "=") == 0 )
		result = aVal == bVal;
	else if( strcmp(op, "<") == 0 )
		result = aVal < bVal;
	else if( strcmp(op, ">") == 0 )
		result = aVal > bVal;
	else if( strcmp(op, "<=") == 0 )
		result = aVal <= bVal;
	else if( strcmp(op, ">=") == 0 )
		result = aVal >= bVal;
	else if( strcmp(op, "<>") == 0 )
		result = aVal != bVal;
	
	if( result )
		Basic::instance()->gotoLine(line);
	else
		Program::execute();
}

// list this line
void IfThen::list(std::ostream& os) const{
	os << "IF " << a->list() << ' ' << op << ' ';
	os << b->list() << " THEN " << line;
}
