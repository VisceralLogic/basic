#include "stringexpression.h"

// create a new StringExpression, storing its text
StringExpression::StringExpression(const char *text){
	this->text = std::string(text);
}

// return the text value
const std::string StringExpression::print() const{
	return text;
}

// return a string for printing
const std::string StringExpression::list() const{
	return '"' + text + '"';
}
