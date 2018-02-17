#include "parenexpression.h"

ParenExpression::ParenExpression(DoubleExpression *exp) : DoubleExpression(0){
	this->exp = exp;
}

ParenExpression::~ParenExpression(){
	delete exp;
}

// return a printable value
const std::string ParenExpression::print() const{
	return std::to_string(value());
}

// print a listing version
const std::string ParenExpression::list() const{
	return "(" + exp->list() + ")";
}

// numerical evaluation
double ParenExpression::value() const{
	return exp->value();
}