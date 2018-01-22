#include "variableexpression.h"

VariableExpression::VariableExpression(char *name) : DoubleExpression(0) {
	var = name;
}

// return the stored value
const std::string VariableExpression::print() const{
	return std::to_string(value());
}

// printable version
const std::string VariableExpression:: list() const{
	return var;
}

// numerical evaluation
double VariableExpression::value() const{
	return Basic::instance()->resolve(var);
}
