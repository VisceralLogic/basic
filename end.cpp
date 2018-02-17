#include "end.h"
#include "basic.h"

// run this line of the program
void End::execute() const{
	Basic::instance()->endProgram();
}

// list this line
void End::list(std::ostream& os) const{
	os << "END";
}
