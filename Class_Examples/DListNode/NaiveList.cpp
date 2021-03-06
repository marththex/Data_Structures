#include "NaiveList.h"
#include <cstddef>
#include <iostream>

using namespace std;

NaiveList:: NaiveList()
{
	size = 0;
	head = NULL;
	back = NULL;
}

NaiveList:: ~NaiveList()
{
	//come back later
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
	if(size == 0)
	{
		back = node;
	}
	else
	{
		head -> prev = node;
		node -> next = head;
	}
	head = node;//?????
	size++;
}

int NaiveList:: removeFront()
{
	List *temp = head;
	if(head->next == NULL)
		back == NULL;
	else
	{
		head-> next -> prev = NULL;	
	}
	head = head-> next;
	int val = temp -> data;
	delete temp;
	--size;
	return val;
}

int NaiveList::insertBack(int data)
{
	ListNode *node = new ListNode(data); // new pointer to ListNode
	if(size == 0)
	{
		front = node;
	}
	else
	{
		back -> next = node;
		node -> prev = back;
	}
	
	back = node;
	++size;
}

int NaiveList::removeBack(int data)
{
	//this is for you guys
}

ListNode* NaiveList:: remove(int key)
{
	ListNode *current = head;
	while(current -> data != key)
	{
		current -> current -> next;
		if( current == NULL)
			return NULL;
	}
	
	//we found something
	if(current == head)
		head = current -> next;
	else
	{
		current -> prev -> next = curret -> next;
	}
	
	if(current == back)
		back = current-> prev;
	else
	{
		current -> next -> prev = current -> prev;	
	}
	
	current -> next = NULL;
	current -> prev = NULL;
	
	--size;
	return current;l
	
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
