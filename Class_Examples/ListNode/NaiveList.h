#include "ListNode.h"

class NaiveList
{
	private:
		ListNode *head;
		unsigned int size;
		
	public:
		NaiveList();
		~NaiveList();
		void insertFront(int data);
		int removeFront();
		int find(int value);
		unsigned int getSize(); //value not negative
		bool isEmpty();
		int deletePos(int pos);
		void printList();
		
};
