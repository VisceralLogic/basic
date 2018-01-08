#include "doubleexpression.h"

// create a new DoubleExpression, storing its value
DoubleExpression::DoubleExpression(double d){
	this->d = d;
}

// return the text value
const std::string DoubleExpression::value() const{
	return std::to_string(d);
}

// return a string for printing
const std::string DoubleExpression::print() const{
	return value();
}
