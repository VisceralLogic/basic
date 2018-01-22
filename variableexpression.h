#ifndef _VARIABLEXPRESSION_H_
#define _VARIABLEXPRESSION_H_

#include <string>

#include "doubleexpression.h"
#include "basic.h"

/*
This class is used to access variable inside an expression
*/
class VariableExpression : public DoubleExpression {
public:
	VariableExpression(char *name);

	const std::string print() const;		// return the stored value
	const std::string list() const;			// printable version
	double value() const;					// numerical evaluation

private:
	std::string var;
};

#endif