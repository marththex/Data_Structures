#include <iostream>
#include "genstack"

using namespace std;

GenStack::Genstack(int maxSize)
{
	myArray = new char(maxSize);
	max = maxSize;
	top = -1;

}

Genstack::~Genstack()
{
	delete myArray[];
	cout << "object destoryed" << end;
}

void GenStack::push(char data)
{
	myArray[++top] = data;
}

char GenStack::pop()
{
	return myArray[top--];
}

char GenStack::peek()
{
	return myArray[top];
}

int GenStack::isFull()
{
	return (top == max-1);
}

int GenStack::isEmpty()
{
	return (top == -1);
}
