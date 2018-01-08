#ifndef _DOUBLEEXPRESSION_H_
#define _DOUBLEEXPRESSION_H_

#include "expression.h"

/*
Class used for storing a numerical value
*/
class DoubleExpression : public Expression {
public:
	DoubleExpression(double d);				// take a double as input
	
	const std::string value() const;		// return the stored value
	const std::string print() const;		// printable version
	
private:
	double d;								// data storage
};

#endif