#include <iostream>

#include "basic.h"

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
void Basic::list(){
	for( map<int, const Program *>::iterator it = lines.begin(); it!= lines.end(); ++it ){
		std::cout << it->first << " ";
		it->second->list(std::cout);
		std::cout << std::endl;
	}
}

// run the program
void Basic::execute(){
	for( map<int, const Program*>::iterator it = lines.begin(); it != lines.end(); ++it ){
		it->second->execute();
	}
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