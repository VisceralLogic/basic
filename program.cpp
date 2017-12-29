#include "program.h"

// nothing to do in the base class
void Program::execute() const{
}

// if you ever see this, something is wrong
void Program::list(std::ostream& os) const{
	os << "GENERIC PROGRAM (SHOULDN'T SEE THIS)";
}