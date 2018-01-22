#ifndef _LET_H_
#define _LET_H_

#include <string>

#include "program.h"
#include "doubleexpression.h"
#include "basic.h"

/*
The Let class provides variable assignment capability.
*/
class Let : public Program {
public:
	Let(char *var, const DoubleExpression *expression);	// create a new LET assignment
	~Let();												// clean up

	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line
	
private:
	std::string var;
	const DoubleExpression *expression;
};

#endif