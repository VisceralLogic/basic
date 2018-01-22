#ifndef _BASIC_H_
#define _BASIC_H_

#include <map>
#include <string>

#include "program.h"
#include "doubleexpression.h"

/*
This is a singleton class which contains all the program lines.
*/
class Basic {
public:
	void add(int index, const Program *program);		// add a new line to the program
	void list();										// list out all the existing lines
	void execute();										// run the program
	void remove(int index);								// remove program line
	
	static Basic *instance();							// access the singleton instance

	void assign(std::string var, double value);			// assign a value to a variable
	double resolve(std::string var);					// return variable value
	
private:
	std::map<int, const Program*> lines;				// store the lines in a map
	std::map<std::string, double> vars;					// store variables
	
	static Basic *b;									// singleton instance
};

#endif