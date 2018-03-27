#ifndef _FOR_H_
#define _FOR_H_

#include <string>
#include <map>

#include "program.h"
#include "doubleexpression.h"

class Next;

/*
This class provides the functionality to handle the FOR
loop statement.
*/
class For : public Program {
public:
	For(DoubleExpression *start, DoubleExpression *stop, DoubleExpression *step, std::string var);
	~For();
	
	void execute() const;					// run this line of the program
	void list(std::ostream& os) const;		// list this line
	void preExecute() const;				// run before main program execution
	void registerNext(const Next *next) const;	// register NEXT statement
	void doNext() const;					// called from NEXT statement

private:
	DoubleExpression *start;			// expression to evaluate to start the loop
	DoubleExpression *stop;				// end condition expression
	DoubleExpression *step;				// step size expression
	std::string var;					// loop variable name
	static std::map<const For*, const Next*> nextLine;	// NEXT statement to jump past when loop terminates
	static std::map<const For*, bool> initial;	// is this the first time executing
};

#endif