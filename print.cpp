#include <iostream>

#include "print.h"

using std::endl;
using std::cout;

// constructor for Print class
Print::Print(const std::vector<Expression>& exprList){
	this->exprList = exprList;
}

// prints out each expression to std::cout
void Print::execute() const{
	for( int i = 0; i < exprList.size()-1; i++ ){
		cout << exprList[i].value() << ' ';
	}
	cout << exprList[exprList.size()-1].value() << endl;
}

// lists the expressions, as they were originally given
void Print::list(ostream& os) const{
	os << "PRINT ";
	for( int i = 0; i < exprList.size()-1; i++ ){
		os << exprList[i].print() << ", ";
	}
	os << exprList[exprList.size()-1].print();
}