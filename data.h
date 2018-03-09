#ifndef _DATA_H_
#define _DATA_H_

#include <vector>

#include "program.h"

/*
This class implements the DATA statement, storing numbers
for later use by READ.
*/
class Data : public Program {
public:
	Data(std::vector<double> vals);
	
	// use parent 'execute' implementation
	void list(std::ostream& os) const;	// list this line
	void preExecute() const;			// run before main program execution
	
private:
	std::vector<double> vals;			// doubles to be stored
};

#endif