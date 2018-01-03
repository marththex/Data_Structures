#include "NaiveList.h"
#include <cstddef>
#include <iostream>

using namespace std;

NaiveList:: NaiveList()
{
	size = 0;
	head = NULL;
}

NaiveList:: ~NaiveList()
{
	while(head != NULL)
		delete head;
}

unsigned int NaiveList::getSize()
{
	return size;
}

void NaiveList::printList()
{
	ListNode *curr = head;
	while(curr != NULL)
	{
		cout << curr -> data << endl;
		curr = curr -> next;
	}
}

void NaiveList::insertFront(int data)
{
	ListNode *node = new ListNode(data); // new pointer to ListNode
	node -> next = head;
	head = node;
	size++;
}

int NaiveList:: removeFront()
{
	int temp = head -> data;
	ListNode *oldFront = head; // temp pointer
	
	head = head -> next;
	oldFront -> next = NULL;
	delete oldFront;
	size--;
	return temp;
}

int NaiveList::deletePos(int pos)
{
	ListNode *curr = head;
	ListNode *prev = head;
	
	int idx = 0; //index
	
	while(idx != pos)
	{
		prev = curr;
		curr = curr -> next;
		++idx;
	}
	
	prev -> next = curr -> next;
	curr -> next = NULL;
	int d = curr -> data;
	size--;
	delete curr;
	return d;
}
