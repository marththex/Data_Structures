#include <iostream>

class GenQueue
{
	public:
	GenQueue(int maxSize);
	~GenQueue();
	void incert(char data);
	char remove();
	char peek();
	int isFull();
	int isEmpty();
	int head;
	int tail;
	int mSize;
	int numElements;
	int getSize();
	char *myQueue;
}