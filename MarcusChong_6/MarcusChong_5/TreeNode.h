#include <iostream>
#include "Student.h"
#include "Faculty.h"

using namespace std;

template<class T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(T key);
		virtual ~TreeNode(); // why does our destructor have to be virtual
		T key;
		TreeNode<T> *left;
		TreeNode<T> *right;
		
};

template<class T>
TreeNode<T> :: TreeNode()
{
	left = NULL;
	right = NULL;
}

template<class T>
TreeNode<T> :: TreeNode(T k)//overloaded constructor
{
	left = NULL;
	right = NULL;
	key = k;
}

template<class T>
TreeNode<T> :: ~TreeNode()
{
	//do we anything here?
}

template<class T>
class BST
{
	public:
		BST();
		~BST(); //why does it need to be virtual?
		
		void printTree(int a, int numNode, string s);
		void printNode(int IDNumber);
		void insert(T value);
		bool contains(int IDNumber);
		void deleteNode(int IDNumber);
		//void deleteNode(root, int IDNumber);
		bool isEmpty();
		T getNode(int IDNumber);
		T* getMin();//leftmost node Address
		T getMinValue();//leftmoast node Value
		T* getMax();//rightmost Address
		T getMaxValue();//rightmost Value
		//TreeNode<T>* getSuccessor(TreeNode<T>* d);
		void recPrint(TreeNode<T>* node, int a, int numNode, string s);
		int printRoot;
		//T key;
		
	private:
		TreeNode<T>* root;
};

template<class T>
BST<T>::BST()
{
	root = NULL;
}

template<class T>
BST<T>::~BST()
{
	//interate and delete
}	

template<class T>
bool BST<T>::isEmpty()
{
	return root == NULL;
}

template<class T>
void BST<T> :: printTree(int a, int numNode, string s)
{
	recPrint(root, a, numNode, s);
}

template<class T>
void BST<T>::recPrint(TreeNode<T>* node, int a, int numNode, string s)
{
	if(root != NULL)
	{
		if((node ->left) != NULL)
		{
			recPrint(node ->left,a, numNode, s);
		
		}
		(node) -> key -> printInfo(a, numNode, s);
		if((node ->right) != NULL)
		{
			recPrint(node ->right,a, numNode, s);
		}
		
	}
	else
	{
		cout << "tree is empty" << endl;
	}
}

template<class T>
void BST<T>::printNode(int IDNumber)
{
	bool found = false;
	TreeNode<T>* current = root;
	TreeNode<T>* predecessor = NULL;
	if(current== NULL)
	{
		 //cout<<"Tree is empty"<<endl;
		 return;
	}
	while(current!= NULL)
	{
		if((current-> key)->getID() == IDNumber)
		{
			found = true;
			cout << (current-> key) -> printInfo(1, 0, "") << endl;
			break;
		}
		else
		{
			predecessor = current;
			if(IDNumber > (current->key)->getID())
				current=current->right;
			else
				current=current->left;
		}
	}
	if(!found)
	{
		cout<<"node is not in Tree."<<endl;
		return;
	}
	
}

template<class T>
T BST<T>::getNode(int IDNumber)
{
	bool found = false;
	TreeNode<T>* current = root;
	TreeNode<T>* predecessor = NULL;
	if(current== NULL)
	{
		 //out<<"Tree is empty"<<endl;
		 return NULL;
	}
	while(current!= NULL)
	{
		if((current-> key)->getID() == IDNumber)
		{
			found = true;
			return current-> key;
			break;
		}
		else
		{
			predecessor = current;
			if(IDNumber > (current->key)->getID())
				current=current->right;
			else
				current=current->left;
		}
	}
	if(!found)
	{
		cout<<"node is not in Tree."<<endl;
		return NULL;
	}
	
}

template<class T>
T* BST<T> :: getMin()
{
	TreeNode<T>* current = root;
	
	if(current == NULL)
		return NULL;
	
	while(current-> left!= NULL)
	{
		current = current -> left;		
	}
	
	return &(current-> key);
}

template<class T>
T BST<T> :: getMinValue()
{
	TreeNode<T>* current = root;
	
	if(current == NULL)
		return -1;
	
	while(current-> left!= NULL)
	{
		current = current -> left;		
	}
	
	return (current-> key);
}

template<class T>
T* BST<T> :: getMax()
{
	TreeNode<T>* current = root;
	
	if(current == NULL)
		return NULL;
	
	while(current-> right!= NULL)
	{
		current = current -> right;		
	}
	
	return &(current-> key);
}

template<class T>
T BST<T> :: getMaxValue()
{
	TreeNode<T>* current = root;
	
	if(current == NULL)
		return -1;
	
	while(current-> right!= NULL)
	{
		current = current -> right;		
	}
	
	return (current-> key);
}

template<class T>
void BST<T> :: insert(T value)
{
	TreeNode<T>* node = new TreeNode<T>(value);
	
	if(root == NULL)
	{
		root = node;
	}
		
	else
	{
		TreeNode<T>* current = root;//start at root
		TreeNode<T>* parent; //empty for now
		
		while(true)
		{
			parent = current; 
			//cout << "value: " << (node-> key )->getID() << endl;
		//	cout << "current: " << (current-> key)->getID() << endl;
			if((node-> key ) -> getID() < (current-> key)->getID())//???
			{
				current = current->left;//go left
				
				if (current == NULL) // if NULL, left insert here
				{
					parent-> left = node;
					break;
				}
			}
			
			else
			{
				
			//cout << "in else" << endl;
			current = current -> right; //go right
				
				if(current== NULL)
				{
					parent -> right = node;
					break;
				}
			}
		}
	}
}

template<class T>
bool BST<T> :: contains(int IDNumber)
{
	bool found = false;
	TreeNode<T>* current = root;
	TreeNode<T>* predecessor = NULL;
	if(current== NULL)
	{
		 //cout<<"Tree is empty"<<endl;
		 return false;
	}
	while(current!= NULL)
	{
		if((current-> key)->getID() == IDNumber)
		{
			found = true;
			return true;
		}
		else
		{
			predecessor = current;
			if(IDNumber > (current->key)->getID())
				current=current->right;
			else
				current=current->left;
		}
	}
	if(!found)
	{
		//cout<<"node is not in Tree."<<endl;
		return false;
	}
}

// Pre-Con: Root and value passed as parameters
// Post-Con: Item is deleted from the tree
template<class T>
void BST<T>::deleteNode(int IDNumber)
{
	// Find the value 
	//T value;
	bool found = false;
	TreeNode<T>* predecessor = NULL;
	TreeNode<T>* current = root;
	if(current== NULL)
	{
		// cout<<"Tree is empty"<<endl;
		 return;
	}
	while(current!= NULL)
	{
		if((current-> key)->getID() == IDNumber)
		{
			found = true;
			break;
		}
		else
		{
			predecessor = current;
			if(IDNumber > (current->key)->getID())
				current=current->right;
			else
				current=current->left;
		}
	}
	if(!found)
	{
		cout<<"node is not in Tree."<<endl;
		return;
	}
	// CASE 1: Removing a node with a single child
	if((current->left== NULL && current->right != NULL) || (current->left != NULL && current->right== NULL))
	{
		// Right Leaf Present, No Left Leaf
		if(current->left== NULL && current->right != NULL)
		{
			if(predecessor == NULL)
			{
				current = current -> right;
				delete root;
				root = current;
				cout<<IDNumber<<" has been removed from the Tree."<<endl;
				return;
			}
			// If predecessor's left tree equals Node n
			if(predecessor != NULL && (predecessor->left)-> key-> getID() == (current-> key)->getID())
			{
				// then predecessor's left tree becomes n's right tree
				// and delete n
				predecessor->left=current->right;
				delete current;
				current = NULL;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
			// If predecessor's right tree equals Node n
			else if(predecessor != NULL && (predecessor->right)->key -> getID()== (current-> key)->getID())
			{
				// then predecessor's right tree becomes n's right tree
				// and delete n
				predecessor->right=current->right;
				delete current;
				current = NULL;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
	
		}
		else // Left Leaf Present, No Right Leaf Present
		{
			if(predecessor == NULL)
			{
				current = current -> left;
				delete root;
				root = current;
				cout<< IDNumber <<" has been removed from the Tree."<<endl;
				return;
			}
			
			if((predecessor->left)-> key -> getID()== (current-> key)-> getID())
			{
				predecessor->left=current->left;
				delete current;
				current = NULL;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
			else
			{
				predecessor->right=current->left;
				delete current;
				current = NULL;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
		}
		return;
	}
	// CASE 2: Removing a Leaf Node
	if(current->left == NULL && current->right == NULL)
	{
		if(predecessor != NULL && (predecessor->left)-> key -> getID() == (current-> key)->getID())
			predecessor->left = NULL;
		else if(predecessor != NULL && (predecessor->right)-> key -> getID() == (current-> key)->getID())
			predecessor->right = NULL;
		delete current;
		if(predecessor == NULL)
		{
			current = NULL;
			root = NULL;
		}
		//cout<<value<<" has been removed from the Tree."<<endl;
		return;
	}
	// CASE 3: Node has two children
	// Replace Node with smallest value in right subtree
	if(current->left != NULL && current->right != NULL)
	{
		TreeNode<T>* check=current->right;
		if((current->left == NULL)&&(current->right == NULL))
		{
			current=check;
			delete check;
			current->right == NULL;
			//cout<<value<<" has been removed from the Tree."<<endl;
		}
		else // Right child has children
		{
			// If the node's right child has a left child
			// Move all the way down left to locate smallest element
			if((current->right)->left != NULL)
			{
				TreeNode<T>* leftCurrent;
				TreeNode<T>* leftCurrentPred;
				leftCurrentPred=  current->right;
				leftCurrent = (current->right)->left;
				while(leftCurrent->left != NULL)
				{
					leftCurrentPred=leftCurrent;
					leftCurrent=leftCurrent->left;
				}
				current->key=leftCurrent->key;
				delete leftCurrent;
				leftCurrentPred->left == NULL;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
			else
			{
				TreeNode<T>* temp=current->right;
				current->key=temp->key;
				current->right=temp->right;
				delete temp;
				//cout<<value<<" has been removed from the Tree."<<endl;
			}
		}
		return;
	}
}
