#include <iostream>
#include <string>
#include "Infix.h"

using namespace std;

// A+((B+C)*(E-F)-G)/(H-F);
// A-((C/D))

int main() {
	Infix myinfix(20);
	string input = "A+((B+C)*(E-F)-G)/(H-F)";
	cout << input << endl;

	myinfix.getInfix(input);
	myinfix.convertToPostfix();

	cout << "Infix: " << myinfix.showInfix() << endl;
	cout << "Postfix: " << myinfix.showPostfix() << endl;

	return 0;
}
