#ifndef _PRINT_H_
#define _PRINT_H_

#include <vector>

#include "program.h"
#include "expression.h"

using std::ostream;

/*
This is the implementation for the PRINT statement
*/
class Print : public Program {
public:
	Print(const std::vector<Expression*> *exprList);	// create with a vector of expressions to print

	virtual void execute() const;						// print the expression
	virtual void list(ostream& os) const;				// list this statement
	
private:
	const std::vector<Expression*> *exprList;			// store the expressions here
};

#endif