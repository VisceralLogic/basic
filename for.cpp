#include "for.h"
#include "basic.h"
#include "next.h"

std::map<const For*, const Next*> For::nextLine;
std::map<const For*, bool> For::initial;

// initialize with all necessary information
For::For(DoubleExpression *start, DoubleExpression *stop, DoubleExpression *step, std::string var){
	this->start = start;
	this->stop = stop;
	this->step = step;
	this->var = var;
	initial[this] = true;
}

// clean up pointers
For::~For(){
	delete start;
	delete stop;
	delete step;
	initial.erase(this);
	nextLine.erase(this);
}

// run this line of the program
void For::execute() const{
	double s = 1.0;						// default step size
	double val;
	
	if( step != NULL )
		s = step->value();				// evaluate the step every time
	
	if( initial[this] ){						// start the loop
		val = start->value();
	} else {							// increment the loop
		val = Basic::instance()->resolve(var) + s;
	}
	
	initial[this] = true;						// reset
	
	Basic::instance()->assign(var, val);	// store the value
	
	// check for loop termination
	if( (s > 0 && val > stop->value()) || (s < 0 && val < stop->value()) ){
		Basic::instance()->gotoProgram(nextLine[this]);
	}
	
	Program::execute();	// continue to next line
}

// list this line
void For::list(std::ostream& os) const{
	os << "FOR " << var << " = " << start->list() << " TO " << stop->list();
	if( step != NULL )
		os << " STEP " << step->list();
}

// run before main program execution
void For::preExecute() const{
	Basic::instance()->pushFor(this);
}

// register NEXT statement
void For::registerNext(const Next *next) const{
	nextLine[this] = next;
}

// called from NEXT statement
void For::doNext() const{
	initial[this] = false;
}
