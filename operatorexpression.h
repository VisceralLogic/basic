#ifndef _OPERATOREXPRESSION_H_
#define _OPERATOREXPRESSION_H_

#include "doubleexpression.h"

/*
Class for performing mathematical operations on DoubleExpressions.
*/
class OperatorExpression : public DoubleExpression {
public:
	OperatorExpression(DoubleExpression *a, DoubleExpression *b, char op);
	~OperatorExpression();					// delete the sub-expressions
	
	const std::string print() const;		// return the stored value
	const std::string list() const;			// printable version
	const double value() const;				// value of performed operation

private:
	DoubleExpression *a, *b;				// expressions on which to operate
	char op;								// operation to perform
};

#endif