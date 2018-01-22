#ifndef _DOUBLEEXPRESSION_H_
#define _DOUBLEEXPRESSION_H_

#include "expression.h"

/*
Class used for storing a numerical value
*/
class DoubleExpression : public Expression {
public:
	DoubleExpression(double d);				// take a double as input
	
	virtual const std::string print() const;	// return the stored value
	virtual const std::string list() const;		// printable version
	virtual double value() const;				// numerical evaluation
	
private:
	double d;								// data storage
};

#endif