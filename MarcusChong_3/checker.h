#include <iostream>
#include <string>
#include<fstream>
#include "genstack.h"

using namespace std;

class Checker
{
	public:
	char response; // whether or not to exit the loop for a correct syntax

	int numQuo;// Ignores characters within quotation marks
	int count, count1, count2, count3, count4, count5; // count # of  ( or ) / { or }  /  [ or ]
	string inFile;
	string line;
	string textName, textLocation;
	ifstream readFile;
	
	
	Checker();
	~Checker();
	bool readInfile(string textfile);
	int execute();
	
};