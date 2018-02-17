#include <fstream>
#include <cstdio>

#include "basic.h"

extern "C" FILE *yyin;

using std::map;
using std::string;
using std::pair;

Basic *Basic::b;

// add a program line at index, overwriting if it exists
void Basic::add(int index, const Program *program){
	// see if index already exists, if so delete it
	remove(index);
	
	lines.insert(pair<int, const Program *>(index, program));
}

// remove an existing line from the program
void Basic::remove(int index){
	map<int, const Program*>::iterator it = lines.find(index);
	if( it != lines.end() ){
		const Program *old = it->second;
		delete old;
		lines.erase(it);
	}	
}

// print out the program lines
void Basic::list(std::ostream &out){
	for( map<int, const Program *>::iterator it = lines.begin(); it!= lines.end(); ++it ){
		out << it->first << " ";
		it->second->list(out);
		out << std::endl;
	}
}

// run the program
void Basic::execute(){
	counter = lines.begin();
	while( counter != lines.end() )
		counter->second->execute();
}

// access the singleton instance, creating it if necessary
Basic *Basic::instance(){
	if( b == NULL )
		b = new Basic();
	return b;
}

// assign a value to a variable
void Basic::assign(string var, double value){
	// delete value if var already exists
	map<string, double>::iterator it = vars.find(var);
	if( it != vars.end() ){
		vars.erase(it);
	}
	
	vars.insert(pair<string, double>(var, value));
}

// return variable value
double Basic::resolve(string var){
	map<string, double>::iterator it = vars.find(var);
	if( it != vars.end() ){
		return it->second;
	}
}

// save active program to disk
void Basic::saveProgram(){
	std::ofstream out;
	out.open(name + ".bas");
	list(out);
}

// delete saved program from disk
void Basic::unsaveProgram(){
	::remove((name + ".bas").c_str());
}

// start a new program
void Basic::newProgram(){
	erase();
	std::cout << "Enter a program name: ";
	std::cin >> name;
	std::cin.ignore();	// consume the newline character
}

// load program from disk
void Basic::oldProgram(){
	erase();
	std::cout << "Enter program to read: ";
	std::cin >> name;
	yyin = fopen((name + ".bas").c_str(), "r");
	if( !yyin ){
		std::cout << "ERROR: could not read file: " << name << ".bas\n";
		yyin = stdin;
	}
}

// clear stored program lines
void Basic::erase(){
	for( map<int, const Program *>::iterator it = lines.begin(); it!= lines.end(); ++it ){
		delete it->second;
	}
	lines.clear();
}

// jump to program line
void Basic::gotoLine(int line){
	counter = lines.find(line);
}

// go to next program line
void Basic::nextLine(){
	++counter;
}

void Basic::endProgram(){
	counter = lines.end();
}