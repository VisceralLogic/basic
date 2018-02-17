#ifndef _GOTO_H_
#define _GOTO_H_

#include <iostream>

#include "program.h"

/*
This class implements the GOTO statement
*/
class Goto : public Program {
public:
	Goto(int line);						// instantiate goto statement
	
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line

private:
	int line;							// line to goto
};

#endif