#include "genstack.h"
#include <iostream>
#include <string>
#include<fstream>
#include<exception>

using namespace std;

class StackEmpty : public exception //My Exception for pop
{
	virtual const char* what() const throw()
	{
		return "The Stack is Empty";
    }
} myex;

GenStack::GenStack(int maxSize)
{
	myArray = new char(maxSize);
	max = maxSize;
	top = -1;

}

GenStack::~GenStack()
{
	delete myArray;
}

void GenStack::push(char data)
{
	
	myArray[++top] = data;
}

char GenStack::pop() 
{
	try
	{
	if(isEmpty()) 
		throw myex;
	return myArray[top--];
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
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

void GenStack::resizeArray()
{
	size = sizeof(myArray);
	char* newArray  = new char[size*2];
	for(int i = 0; i < size; ++i)
	{
		newArray[i] = myArray[i];
	}
	delete[] myArray;
	myArray  = newArray;
	size *= 2;
	
}
