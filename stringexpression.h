#ifndef _STRINGEXPRESSION_H_
#define _STRINGEXPRESSION_H_

#include "expression.h"

/*
Class used for storing a text value
*/
class StringExpression : public Expression {
public:
	StringExpression(const char *text);		// take a string as input
	
	const std::string value() const;		// return the stored value
	const std::string print() const;		// printable version
	
private:
	std::string text;						// data storage
};

#endif