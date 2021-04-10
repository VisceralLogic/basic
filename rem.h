#ifndef _REM_H_
#define _REM_H_

#include <iostream>

#include "program.h"

/*
This class implements the REM statement
*/
class Rem : public Program {
public:
	Rem(const char* remark);	// instantiate rem statement
	
	void execute() const;				// run this line of the program
	void list(std::ostream& os) const;	// list this line

private:
   std::string remark_;					// string containing remark
};

#endif
