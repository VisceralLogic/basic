#include <cmath>

#include "operatorexpression.h"

OperatorExpression::OperatorExpression(DoubleExpression *a, DoubleExpression *b, char op) : DoubleExpression(0) {
	this->a = a;
	this->b = b;
	this->op = op;
}

OperatorExpression::~OperatorExpression(){
	delete a;
	if( b != NULL )
		delete b;
}

const std::string OperatorExpression::print() const{
	return std::to_string(value());
}

const std::string OperatorExpression::list() const{
	if( op != 'n' )
		return a->list() + op + b->list();
	else
		return "-" + a->list();
}

double OperatorExpression::value() const{
	switch( op ){
		case '+':
			return a->value() + b->value();
		case '-':
			return a->value() - b->value();
		case '*':
			return a->value() * b->value();
		case '/':
			return a->value() / b->value();
		case '^':
			return exp(log(a->value()) * b->value());
		case 'n':
			return -a->value();
	}
}