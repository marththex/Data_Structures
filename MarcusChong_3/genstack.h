#include <string>


using namespace std;

class GenStack
{
	private:
	
	int max, size;
	
	
	public:
	int top;
	char* myArray;
	//constructor
	GenStack(int maxSize);
	~GenStack();//destructor
	void push(char data);
	char pop();
	char peek();
	int isFull();
	int isEmpty();
	void resizeArray();
	//stack API
	
	
};
