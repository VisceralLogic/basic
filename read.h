#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <string>

#include "program.h"

/*
This class supports the READ statement, putting pre-stored DATA
into specified variables.
*/
class Read : public Program {
public:
	Read(std::vector<std::string> vars);
	
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line

private:
	std::vector<std::string> vars;		// variables names to receive values
};

#endif