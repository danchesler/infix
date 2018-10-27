/*
 * StackArrayD.h
 *
 *  Created on: Jun 23, 2018
 *      Author: super
 */

#ifndef STACKARRAYD_H_
#define STACKARRAYD_H_

class StackArrayD
{
private:
	double *stackArray;
	int top;
	int size;

public:
	StackArrayD(int);
	~StackArrayD();
	void push(double);
	double pop();
	double getSize();
	double getTopValue();
	int getTop();
};


#endif /* STACKARRAYD_H_ */
