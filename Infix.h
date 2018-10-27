/*
 * Infix.h
 *
 *  Created on: Jun 24, 2018
 *      Author: super
 */

#ifndef INFIX_H_
#define INFIX_H_

#include "StackArrayD.h"
#include <string>
#include <iostream>
using namespace std;

class Infix : public StackArrayD
{
private:
	string infx;
	string pfx;

public:
	Infix(int max);
	~Infix();

	void getInfix(string); //stores infix expression
	string showInfix(); //outputs infix expression
	string showPostfix(); //outputs postfix expression
	bool precedence(char first, char second); //determine precedence of operators, returns 1 if first is >= precedence than second
	void convertToPostfix(); //convert the infix expression to postfix

};



#endif /* INFIX_H_ */
