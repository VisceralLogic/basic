#include "expression.h"

#include <iostream>

// create a new Expression, storing its text
Expression::Expression(const char *text){
	this->text = std::string(text);
}

// return the text value
const string Expression::value() const{
	return text;
}

// return a string for printing
const string Expression::print() const{
	return '"' + text + '"';
}
