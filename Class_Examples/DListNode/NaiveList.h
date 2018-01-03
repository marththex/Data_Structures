#include "ListNode.h"

class NaiveList
{
	private:
		ListNode *head;
		ListNode *back;
		unsigned int size;
		
	public:
		NaiveList();
		~NaiveList();
		void insertFront(int data);
		int removeFront();
		void insertBack(int data);
		int removeBack();
		int getFront();
		int getBack();
		int getAt(int pos)
		int find(int value);
		unsigned int getSize(); //value not negative
		bool isEmpty();
		int deletePos(int pos);
		void printList();
		
};
