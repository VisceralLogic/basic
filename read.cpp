#include "read.h"
#include "basic.h"

Read::Read(std::vector<std::string> vars){
	this->vars = vars;
}

// run this line of the program
void Read::execute() const{
	for( std::vector<std::string>::const_iterator it = vars.cbegin(); it != vars.cend(); ++it ){
		Basic::instance()->read(*it);
	}
	Program::execute();
}

// list this line
void Read::list(std::ostream& os) const{
	os << "READ";
	for( std::vector<std::string>::const_iterator it = vars.cbegin(); it != vars.cend(); ++it ){
		os << ' ' << *it;
	}
}
