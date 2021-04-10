#include "rem.h"
#include "basic.h"

using std::endl;
using std::cout;

// instantiate rem statement
Rem::Rem(const char* remark) : remark_(remark) {
}

// run this line of the program
void Rem::execute() const{
   // Do nothing - it is just a comment.
   cout << "DEBUG: Rem::execute() - ignoring remark: " << remark_ << endl;
   Program::execute();
}

// list this line
void Rem::list(std::ostream& os) const{
	os << remark_;
}
