#include "ListNode.h"
#include <cstddef>

ListNode:: ListNode()
{}

ListNode:: ListNode(int d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

ListNode:: ~ListNode()
{
	if(next != NULL)
		delete next;
}
