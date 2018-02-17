#include <iostream>

#include "print.h"

using std::endl;
using std::cout;

// constructor for Print class
Print::Print(const std::vector<Expression*> *exprList){
	this->exprList = exprList;
}

// prints out each expression to std::cout
void Print::execute() const{
	for( int i = 0; i < exprList->size()-1; i++ ){
		cout << exprList->at(i)->print() << ' ';
	}
	cout << exprList->at(exprList->size()-1)->print() << endl;
	Program::execute();
}

// lists the expressions, as they were originally given
void Print::list(ostream& os) const{
	os << "PRINT ";
	for( int i = 0; i < exprList->size()-1; i++ ){
		os << exprList->at(i)->list() << ", ";
	}
	os << exprList->at(exprList->size()-1)->list();
}