#include "StackArrayD.h"

StackArrayD::StackArrayD(int max)
{
	top = 0;
	size = max;
	stackArray = new double[max];
}

StackArrayD::~StackArrayD()
{
	delete [] stackArray;
}

void StackArrayD::push(double value)
{
	if (top > size-1)
	{
		return;
	}
	stackArray[top++] = value;
}

double StackArrayD::pop()
{
	if (top == 0)
	{
		return 999;
	}
	return stackArray[--top];
}

double StackArrayD::getSize()
{
	return size;
}

double StackArrayD::getTopValue()
{
	if (top == 0)
	{
		return 999;
	}
	return stackArray[top-1];
}

int StackArrayD::getTop()
{
	return top;
}
