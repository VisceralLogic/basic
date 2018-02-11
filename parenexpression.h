#ifndef _PARENEXPRESSION_H_
#define _PARENEXPRESSION_H_

#include <string>

#include "doubleexpression.h"

/*
This class is used to store a parenthesized expression
*/
class ParenExpression : public DoubleExpression {
public:
	ParenExpression(DoubleExpression *exp);
	~ParenExpression();

	const std::string print() const;		// return a printable value
	const std::string list() const;			// print a listing version
	double value() const;					// numerical evaluation

private:
	DoubleExpression *exp;
};

#endif