#ifndef _END_H_
#define _END_H_

#include <iostream>

#include "program.h"

class End : public Program {
public:
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line
};

#endif