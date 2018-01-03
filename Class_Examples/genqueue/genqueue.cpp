#include <iostream>
#include "genqueue.h"

GenQueue::GenQueue(){}

GenQueue::GenQueue(int maxSize)
{
	myQueue = new char(maxSize);
	mSize = maxSize;
	head = 0;
	tail = -1;
	numElements = 0;
}

GenQueue:: ~GenQueue()
{
	delete [] myQueue;
}

void GenQueue::insert(char data)//enqueue from the back
{
	myQueue[++tail];
	++numElements;
}

char GenQueue::remove()//dequeue from the front
{
	char c = '\0';
	c = myQueue[++head];
	
	--numElements;
	return c;
}

char GenQueue::peek()
{
	
	return myQueue[head];
}

int GenQueue::isFull()
{
	return (numElements == mSize);
}

int GenQueue::isEmpty()
{
	return (numElements == 0);
}

int GenQueue::getSize()
{
	return numElements;
}