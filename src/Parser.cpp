//============================================================================
// Name        : Parser.cpp
// Author      : Anubhav Sharma
//============================================================================

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class ExprAST {
public:
	virtual ~ExprAST() {
	}
};

class NumberExprAST: public ExprAST {
	double val;
public:
	NumberExprAST(double val) :
			val(val) {
	}
};

class VariableExprAST: public ExprAST {
	std::string name;
public:
	VariableExprAST(std::string &name) :
			name(name) {
	}
};

class BinaryExprAST : public ExprAST{
	std::string op;
//	std::unique
};

int main(void) {
	cout << ("Hllo World!!!");
	return 0;
}
