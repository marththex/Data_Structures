#include "ListNode.h"
#include <iostream>
#include <string>

using namespace std;
/*
class ListError : public exception //My Exception 
{
	virtual const char* what() const throw()
	{
		return " ERROR: Out of bounds exception.";
	}
} myex;	

class NotFoundError : public exception //My Exception 
{
	virtual const char* what() const throw()
	{
		return " ERROR: Value Not Found.";
	}
} myex2;	
*/

template <typename E>
class NaiveList
{
	private:
		ListNode<E> *head;
		ListNode<E> *back;
		unsigned int size;
		
	public:	
		NaiveList()
		{
			size = 0;
			head = NULL;
			back = NULL;
		}

		~NaiveList()
		{
			
		}

		unsigned int getSize() //data not negative
		{
			return size;
		}

		void insertFront(E data)
		{
			ListNode<E> *node = new ListNode<E>(data); // new pointer to ListNode
			if(size == 0)
			{
				back = node;
			}
			else
			{
				head -> prev = node;
				node -> next = head;
			}
			head = node;
			size++;
		}

		E removeFront()
		{
			
			
			if(head->next == NULL)
				back == NULL;
			E temp = head -> data;
			ListNode<E> *oldFront = head; // temp pointer
			head = head -> next;
			oldFront -> next = NULL;
			delete oldFront;
			size--;
			return temp;
			

		}

		void insertBack(E data)
		{
			ListNode<E> *node = new ListNode<E>(data); // new pointer to ListNode
			if(size == 0)
			{
				head = node;
			}
			else
			{
				back -> next = node;
				node -> prev = back;
			}
	
			back = node;
			++size;
		}

		E removeBack()
		{
			if(back->prev == NULL)
				head == NULL;
			E temp = back -> data;
			ListNode<E> *oldBack = back; // temp pointer
			back = back -> prev;
			oldBack -> prev = NULL;
			delete oldBack;
			size--;
			return temp;
		
		}

		ListNode<E>* remove(E key)
		{
			ListNode<E> *current = head;
			while(current -> data != key)
			{
				current = current -> next;
				if( current == NULL)
					return NULL;
			}
	
			//we found something
			if(current == head)
				head = current -> next;
			else
			{
				current -> prev -> next = current -> next;
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
			return current;
		}

		E getFront()
		{
			return head -> data;
		}

		E getBack()
		{
			return back -> data;
		}

		E getAt(int pos)
		{
			ListNode<E> *current = head;
		/*	try
			{
				if( pos > size)
					throw myex;
				else
				{*/
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
					
					}
				
					return current -> data;
			/*	}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}*/

		}
		
		int find(E a)
		{
		

				ListNode<E> *current = head;
				for(int i = 0; i <= size; ++i)
				{
					
					
					if(current-> data == a)
						return i;
					current = current -> next; 
					
				};
				return -1;
		
		}

		bool isEmpty()
		{
			return size == 0;
		}
		
		void deletePos(int pos)
		{
				
				ListNode<E> *curr = head;
				ListNode<E> *prev = head;
				
				if(pos == 0)
				{
					
					removeFront();
					return;

				}
				//fix delete pos
				for(int i = 0; i < pos-1; ++i)
				{
					prev = curr;
					curr = curr -> next;

				}
			
					
					prev -> next = curr -> next;
					curr -> next = NULL;
					E d = curr -> data;
					size--;
					delete curr;
					return;
				
				
		}

		void printList()
		{
			ListNode<E> *curr = head;
			while(curr != NULL)
			{
				cout << curr -> data << endl;
				curr = curr -> next;
			}
		}		
	
	void sorting()//sorting method for stackoverflow
	{
		if (head != 0)
		{
			ListNode<E> *current = head;
			ListNode<E> *prev = 0;
			ListNode<E> *tempNode = 0;
			bool changeFlag = false;
			for (int i = 0; i < getSize(); i++)
			{
				while (current->next != 0)
				{
					tempNode = current->next;
	
					if (current->data > tempNode->data)
					{
						changeFlag = true;
						current->next = tempNode->next;
						tempNode->next = current;
						if (prev != 0)
							prev->next = tempNode;
						prev = tempNode;
						if (head == current)
							head = tempNode;
						if (current->next == 0)
							back = current;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}
				if (changeFlag == false)
					break;
				else
				{
					prev = 0;
					current = head;
					changeFlag = false;
				}
			}
		}
}
	
		
};
