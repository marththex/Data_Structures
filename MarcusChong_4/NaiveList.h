#include "ListNode.h"
#include <iostream>
#include <string>

using namespace std;

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
			head = node;//?????
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
			deletePos(getSize()-1);
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
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
					
					}
				
					return current -> data;
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}

		int windowTimeNeeded(int pos, int a)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
						current -> data = a;
					}
				
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}

		int windowIdle(int pos)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
						(current -> data)++;
					}
				
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}

		int closedWindow(int pos)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
						current -> data = -1;
					}
				
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}

		int reopenWindow(int pos)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
						current -> data = 0;
					}
				
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}

		int remainZero(int pos)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					for(int i = 0; i <= pos-1; ++i)
					{
						current = current -> next;
						current -> data = (current -> data) + 1;
					}
				
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}
		
		int setWTimeWaited(int pos)
		{
			ListNode<E> *current = head;
			try
			{
				if( pos > size)
					throw myex;
				else
				{
					if(size == 1)
					{
						//current = current -> next;
						current -> data = (current -> data) -1;	
					}
					else	
					{
						for(int i = 0; i <= pos-1; ++i)
						{
							current = current -> next;
							current -> data = (current -> data) -1;	
						}
					}
					
					return (current -> data);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}

		}
		int find(E data)
		{
			try
			{
				ListNode<E> *current = head;
				for(int i = 0; i <= size; ++i)
				{
					if(current-> data == data)
						return i;
					current = current -> next; 
					
				};
				throw myex2;
			}
			
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}

		
		bool isEmpty()
		{
			return size == 0;
		}
		
		E deletePos(int pos)
		{
				if(pos == 0)
					removeFront();
				ListNode<E> *curr = head;
				ListNode<E> *prev = head;
				try
				{
					
					if( pos > size)
						throw myex;
					else
					{
						for(int i = 0; i < pos; ++i)
						{
							prev = curr;
							curr = curr -> next;
						}
							
							prev -> next = curr -> next;
							curr -> next = NULL;
							E d = curr -> data;
							size--;
							delete curr;
							return d;
						
					}
				}
				
				catch (exception& e)
				{
					cout << e.what() << '\n';
				}
			
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
		
	/*void sorting()
	{
	   Node* tempNode = NULL;
	   Node* tempHead = head;
	   Node* tempNext = head->next;
	
	   while(tempNext!=NULL) {
	
		   if(tempHead->key > tempNext->key) {
			   tempNode = tempHead;
			   tempHead = tempNext;
			   tempNode->next = tempNode->next->next;
			   tempHead->next = tempNode;
			   tempNext = tempHead->next;
			   print_list(tempHead);
	
	
			}
			else {  
				tempHead = tempHead->next;
				tempNext = tempNext->next;
	
			}
		}
	}*/
	
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
