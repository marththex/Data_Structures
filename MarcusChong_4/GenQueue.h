#include <iostream>
#include "NaiveList.h"

template <typename E>
class GenQueue
{
	private:
		NaiveList<E> myList;
		int mSize;
	public:
		GenQueue()
		{}
		
		GenQueue(int maxSize)
		{
			myList = new E(maxSize);
			mSize = maxSize;
		}
		
		~GenQueue()
		{
			//delete myList;
		}
		
		void insert(E data)//enqueue from the back
		{
			myList.insertBack(data);
		}
		
		E remove()//dequeue from the front
		{
			return myList.removeFront();
		}
		
		E peek()
		{
			return myList.getFront();
		}
		
		bool isEmpty()
		{
			return myList.isEmpty();
		}
		
		int getSize()
		{
			return myList.getSize();
		}
		
		E getAt(int pos)
		{
			return myList.getAt(pos);
		}
		
		
		
};
