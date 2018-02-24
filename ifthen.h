#ifndef _IFTHEN_H_
#define _IFTHEN_H_

#include "program.h"
#include "doubleexpression.h"

/*
This class provides support for the IF-THEN statement.
*/
class IfThen : public Program {
public:
	IfThen(DoubleExpression *a, DoubleExpression *b, char *op, int line);
	~IfThen();
	
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line

private:
	DoubleExpression *a, *b;
	char *op;
	int line;
};

#endif