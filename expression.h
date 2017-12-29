#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <string>

using std::string;

/*
Base class used for storing and evaluating data items
*/
class Expression {
public:
	Expression(const char *text);		// our first implementation will take a string as input
	
	const string value() const;			// return the stored value
	const string print() const;			// printable version
	
private:
	string text;						// data storage
};

#endif