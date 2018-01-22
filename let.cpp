#include "let.h"

Let::Let(char *var, const DoubleExpression *expression){
	this->var = var;
	this->expression = expression;
}

// clean up the pointer
Let::~Let(){
	delete expression;
}

// store the value of the Expression in the Basic vars map
void Let::execute() const{
	Basic::instance()->assign(var, expression->value());
}

// list this LET statement
void Let::list(std::ostream& os) const{
	os << "LET " << var << " = " << expression->list();
}