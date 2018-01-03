#include<iostream>
#include<string>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include "TreeNode.h"
#include "RollOver.h"

using namespace std;

class DataBase
{
	public:
		DataBase();
		~DataBase();
		void option1();
		void option2();
		void option3();
		void option4();
		void option5();
		void option6();
		void option7();
		void option8();
		void option9();
		void option10();
		void option11();
		void option12();
		void option13();
		void readInFile(string s, string s2);
		void writeInFile(string s, string s2);
		void run();
		
	private:
		BST<Student*> studentTree;
		BST<Faculty*> facultyTree;
		int option, id, id2, advisor, advisees, undo, undoLimit;
		string name, level, major, department,string1, string2;
		double GPA;
		NaiveList<RollOver*> rollBack;
		fstream readFile, readFile2;
		int numFac, numStu;
		
	
		
		
};

