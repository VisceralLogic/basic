#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <string>

/*
Base class used for storing and evaluating data items
*/
class Expression {
public:
	virtual const std::string value() const;			// return the stored value
	virtual const std::string print() const;			// printable version
};

#endif