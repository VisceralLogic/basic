#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <iostream>

/*
This is the base class for executable program lines
*/
class Program{
public:
	virtual void execute() const;				// run this line of the program
	virtual void list(std::ostream& os) const;	// list this line
	virtual void preExecute() const;			// run before main program execution
};

#endif