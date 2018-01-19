#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <string>

/*
Base class used for storing and evaluating data items
*/
class Expression {
public:
	virtual const std::string print() const;		// return a string version for PRINT
	virtual const std::string list() const;			// printable version suitable for LIST
};

#endif