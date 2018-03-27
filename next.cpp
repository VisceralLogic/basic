#include "next.h"
#include "basic.h"
#include "for.h"

std::map<const Next*, const For*> Next::loop;

// initialize
Next::Next(std::string var){
	this->var = var;
}

// clean up
Next::~Next(){
	loop.erase(this);
}

// run this line of the program
void Next::execute() const{
	loop.at(this)->doNext();
	Basic::instance()->gotoProgram(loop[this]);
}

// list this line
void Next::list(std::ostream& os) const{
	os << "NEXT " << var;
}

// run before main program execution
void Next::preExecute() const{
	loop[this] = Basic::instance()->popFor();
	loop.at(this)->registerNext(this);
}