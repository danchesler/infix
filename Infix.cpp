/*
 * Infix.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: super
 */
#include "Infix.h"

Infix::Infix(int max):StackArrayD(max)
{
	infx = "";
	pfx = "";

}
Infix::~Infix(){}

void Infix::getInfix(string input)
{
	infx = input;
}

string Infix::showInfix()
{
	return infx;
}

string Infix::showPostfix()
{
	return pfx;
}

//returns 1 if precedence of second is greater than or equal to first
bool Infix::precedence(char first, char second)
{
	if (second == '*' || second == '/')
	{
		return 1;
	}
	else if ((first == '+' || first == '-') && (second == '+' || second == '-'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Infix::convertToPostfix()
{
	char sym = 0;
	char sym2 = 0;
	for (unsigned int i = 0; i < infx.length(); i++)
	{
		sym = infx[i];
		//if symbol is operand append to pfx by checking ASCII range for symbol
		if ((sym > 64 && sym < 91) || (sym > 96 && sym < 122))
		{
			pfx += sym;
			continue;
		}

		//if symbol is '(' push sym into stack
		if (sym == '(')
		{
			push(sym);
			continue;
		}

		//if symbol is ')' pop and append all symbols from stack
		//until most recent '(' then pop and discard the '('
		if (sym == ')')
		{
			while (1)
			{
				sym = pop();
				if (sym == '(')
				{
					break;
				}
				else
				{
					pfx += sym;
				}
			}
			continue;
		}

		//if symbol is an operator pop and append all operators above the most recent '(' and have precedence >= to sym
		//then push sym onto stack
		//works for +-*/
		if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
		{
			sym2 = getTopValue();
			while (sym2 != '(' && getTop() != 0 && precedence(sym, sym2))
			{
				cout << sym << " " << sym2 << endl;
				sym2 = pop();
				pfx += sym2;
				sym2 = getTopValue();
			}

			push(sym);
			continue;
		}

	}
	while (getTop() != 0)
	{
		sym = pop();
		pfx += sym;
	}
}

