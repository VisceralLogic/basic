#ifndef _BASIC_H_
#define _BASIC_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#include "program.h"
#include "doubleexpression.h"

class For;

/*
This is a singleton class which contains all the program lines.
*/
class Basic {
public:
	void add(int index, const Program *program);		// add a new line to the program
	void list(std::ostream &out);						// list out all the existing lines
	void execute();										// run the program
	void remove(int index);								// remove program line
	void saveProgram();									// save active program to disk
	void unsaveProgram();								// delete saved program from disk
	void newProgram();									// start a new program
	void oldProgram();									// load program from disk
	void erase();										// clear stored program lines
	void renameProgram();								// rename the current program
	void catalogPrograms();								// list saved programs
	void gotoLine(int line);							// jump to program line
	void nextLine();									// go to next program line
	void gotoProgram(const Program *program);			// go to program line
	void endProgram();									// end execution
	void read(std::string var);							// assign next data value to var
	void pushData(std::vector<double> vals);			// push more values onto data vector
	void pushFor(const For *forLoop);					// push a FOR loop onto the stack
	const For *popFor();								// pop last FOR off the stack
	
	static Basic *instance();							// access the singleton instance

	void assign(std::string var, double value);			// assign a value to a variable
	double resolve(std::string var);					// return variable value
	
private:
	std::map<int, const Program*> lines;				// store the lines in a map
	std::map<std::string, double> vars;					// store variables
	std::string name;									// name of active program
	std::map<int, const Program*>::iterator counter;	// program line to run next
	std::deque<double> data;							// stored data block for READ
	std::stack<const For*> forLoops;					// stack for registering FOR/NEXT statements
	
	static Basic *b;									// singleton instance
};

#endif