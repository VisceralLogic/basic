#ifndef _NEXT_H_
#define _NEXT_H_

#include <string>
#include <map>

#include "program.h"

class For;

/*
This class implements the NEXT part of a FOR/NEXT loop.
*/
class Next : public Program {
public:
	Next(std::string var);
	~Next();
	
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line
	void preExecute() const;			// run before main program execution
	
private:
	static std::map<const Next*, const For*> loop;	// FOR loop to jump back to
	std::string var;					// loop variable name
};

#endif