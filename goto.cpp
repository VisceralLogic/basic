#include "goto.h"
#include "basic.h"

// instantiate goto statement
Goto::Goto(int line){
	this->line = line;
}

// run this line of the program
void Goto::execute() const{
	Basic::instance()->gotoLine(line);
}

// list this line
void Goto::list(std::ostream& os) const{
	os << "GOTO " << line;
}