#include <iostream>
#include <string>
#include "TreeNode.h"


using namespace std;

int main(int argc, char ** argv)
{
	BST<int> tree;
	tree.insert(0);
	//cout <<"made it through insert" << endl;
	tree.insert(1);
	//cout <<"made it through insert" << endl;
	tree.insert(2);
	tree.insert(2);
	tree.insert(2);
	tree.insert(2);
	tree.insert(2);
	tree.insert(3);
	tree.insert(0);
	tree.printTree();
	tree.deleteNode(0);
	//cout <<"made it through insert" << endl;
	//cout << "deleted" << endl;
	tree.printTree();

	return 0;
}
