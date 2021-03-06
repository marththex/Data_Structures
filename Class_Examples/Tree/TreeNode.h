#include <iostream>

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
		
		void printTree();
		void insert(T value);
		bool contains(T value);
		void deleteNode(T value);
		void deleteNode(TreeNode<T>* n, T value);
		bool isEmpty();
		T* getMin();//leftmost node Address
		T getMinValue();//leftmoast node Value
		T* getMax();//rightmost Address
		T getMaxValue();//rightmost Value
		TreeNode<T>* getSuccessor(TreeNode<T>* d);
		void recPrint(TreeNode<T>* node);
		
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
void BST<T> :: printTree()
{
	recPrint(root);
}

template<class T>
void BST<T>::recPrint(TreeNode<T>* node)
{
	//cout << "In RecPrint" << endl;
	if(isEmpty())
	{
		cout<<" Tree is empty"<<endl;
		return;
	}
	if(node == NULL)
	{
		return;
	}
	recPrint(node -> left);
	cout << node-> key << endl;
	//cout << "made it through RecPrint" << endl;
	recPrint(node->right);
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
			//cout << "in while loop" << endl;
			if(value < current-> key)//???
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
bool BST<T> :: contains(T value)
{
	if(root == NULL)
		return false;
	else
	{
		TreeNode<T>* current = root;
		
		while(current -> key != value) //while we have not found the value, keep iterating
		{
			if(value < current -> key)
				current = current -> left;
			else
				current = current -> right;
			
			if (current == NULL)//we didn't find it
				return false;
		}
	}
	return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d) // d is the node to be deleted)
{
	TreeNode<T>* sp = d;//successor's parent
	TreeNode<T>* successor = d; //should be one right and all the way to the left
	
	TreeNode<T>* current = d -> right; // go the right
	
	while(current != NULL)
	{
		sp = successor;
		successor = current;
		current = current -> left;
	}
	
	if(successor != d-> right) // descendant of right child
	{
		sp -> left = successor -> right;
		successor -> right = d -> right;
	}
	
	return successor;
}
template<class T>
void BST<T>::deleteNode(T value)
{
	// Call Erase Recursive Function
	deleteNode(root, value);
}

// Pre-Con: Root and value passed as parameters
// Post-Con: Item is deleted from the tree
template<class T>
void BST<T>::deleteNode(TreeNode<T>* n, T value)
{
	// Find the value 

	
	bool found = false;
	TreeNode<T>* predecessor = NULL;
	TreeNode<T>* current = n;
	if(current== NULL)
	{
		 cout<<"Tree is empty"<<endl;
		 return;
	}
	//predecessor= current;
	while(current!= NULL)
	{
		if(current->key==value)
		{
			found = true;
			break;
		}
		else
		{
			predecessor = current;
			if(value > (current->key))
				current=current->right;
			else
				current=current->left;
		}
	
	}
	if(!found)
	{
		cout<<value<<" not in Tree."<<endl;
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
				cout<<value<<" has been removed from the Tree."<<endl;
				return;
			}
			// If predecessor's left tree equals Node n
			if(predecessor->left==current)
			{
				// then predecessor's left tree becomes n's right tree
				// and delete n
				predecessor->left=current->right;
				delete current;
				//current = NULL;
				cout<<value<<" has been removed from the Tree."<<endl;
			}
			// If predecessor's right tree equals Node n
			else
			{
				// then predecessor's right tree becomes n's right tree
				// and delete n
				predecessor->right=current->right;
				delete current;
				current = NULL;
				cout<<value<<" has been removed from the Tree."<<endl;
			}
		}
		else // Left Leaf Present, No Right Leaf Present
		{
			if(predecessor == NULL)
			{
				current = current -> left;
				delete root;
				root = current;
				cout<<value<<" has been removed from the Tree."<<endl;
				return;
			}
			
			if(predecessor->left==current)
			{
				predecessor->left=current->left;
				delete current;
				current = NULL;
				cout<<value<<" has been removed from the Tree."<<endl;
			}
			else
			{
				predecessor->right=current->left;
				delete current;
				current = NULL;
				cout<<value<<" has been removed from the Tree."<<endl;
			}
		}
		return;
	}
	// CASE 2: Removing a Leaf Node
	if(current->left == NULL && current->right == NULL)
	{
		cout << "in case 2 " << endl;
		if(predecessor != NULL && predecessor->left == current)
			predecessor->left = NULL;
		else if (predecessor != NULL && predecessor-> right == current)
			predecessor->right = NULL;
		else
		{
			delete current;
			current = NULL;
			root = NULL;
		}
		//delete current;
		//cout << "current deleted" << endl;
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
			cout<<value<<" has been removed from the Tree."<<endl;
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
				cout<<value<<" has been removed from the Tree."<<endl;
			}
			else
			{
				TreeNode<T>* temp=current->right;
				current->key=temp->key;
				current->right=temp->right;
				delete temp;
				cout<<value<<" has been removed from the Tree."<<endl;
			}
		}
		return;
	}
}

template<class T>
bool BST<T>::isEmpty()
{
	if(root == NULL) 
		return true;
	else
		return false;
}
