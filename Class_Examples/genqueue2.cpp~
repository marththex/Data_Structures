#include <iostream>
#include "genqueue.h"

using namespace std;

int main(int argc, char**argv)
{
	GenQueue g(10);
	
	//cout << "size : " << sizeof(g) << endl);
	
	g.insert('a');
	g.insert('b');
	g.insert('c');
	
	cout<<"peek: " << g.peek() << endl;
	cout <<"remove: " << g.remove() << endl;
	cout<<"peek: " << g.peek() << endl;
	cout << "isEmpty: " <, g.isEmpty() << endl;
	
	g.insert('t');
	g.insert('u');
	g.insert('v');
	
	cout <<  "peek " << g.peek() << endl;
	
	cout << "is queue full: " << g.isFull()<< endl;
	
	while(!g.isEmpty())
		cout << g.remove() << endl;
	
	cout << "is empty: " << g.isEmpty() << endl;
}