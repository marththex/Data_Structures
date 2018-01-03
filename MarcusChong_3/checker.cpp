#include <iostream>
#include "checker.h"
#include <fstream>
#include<string>



using namespace std;

GenStack stack = GenStack(20);

Checker:: Checker()
{
	
}

Checker:: ~Checker()
{

}

bool Checker::readInfile(string textfile)
{
	count =  0; // count # of  ( 
	count1 =  0;// count # of  { 
	count2 =  0;// count # of  { 
	count3 =  0; // count # of  )
	count4 =  0;// count # of  }
	count5 =  0;// count # of  }
	
	readFile.open(textfile.c_str());
	
	while(!readFile.eof())
	{
		readFile >> line;
	
		if(!readFile)
		{
			break;
		}
		for(int j = 0; j < line.size(); ++j)
		{
			if(stack.isFull())
			{
				stack.resizeArray();
			}
			if(line[j] == '"')
			{
				++numQuo;
			}
			if(line[j] == '/' && line[j+1] == '/')
				break;
			if((numQuo % 2) == 0)
			{
				if (line[j] == '(' || line[j] == '{' || line[j] == '[')
				{
					if(line[j] == '(')
						count++;
					else if(line[j] == '{')
						count1++;
					else if(line[j] == '[')
						count2++;
					stack.push(stack.myArray[j]);
			
				}
			
				else if (line[j] == ')' || line[j] == '}' || line[j] == ']')
				{

					if (stack.isEmpty())
					{
						return false;
					}
					if(line[j] == ')')
						count3++;
					else if(line[j] == '}')
						count4++;
				else if(line[j] == ']')
						count5++;
					stack.pop();
				
				}	
			}
			
			
		}	
	}
	
			if (stack.isEmpty())
			{
				return true;
			}
			
			else
			{
				return false;
			}
	
	
	
	readFile.close(); 
}


int Checker::execute()
{
	response= 'y';
	cout << "-----------------------------------------------------" << endl;
	cout << "WELCOME TO DELIMITER CHECKER!" << endl;
	cout << "-----------------------------------------------------" << endl;
	while(response != 'n') // until the user submits a incorrect file or chooses not to contiue
	{
	cout << endl;
	cout << "ENTER THE LOCATION OF A SOURCE FODE FILE.(eg. ./assign3 foo.cpp)." << endl;
	cin >> textName;
	while ( !(ifstream(textName.c_str())))// Checks to see if the text file exist
	{
		cout << "Can't find my file! Please try again." << endl;
		cin >> textName;
	}
	
	
	if(readInfile(textName) == false)
	{
		if(((count+count3) % 2) != 0)
		{
			if (count < count3)
				cout << "Reached end of file: missing '('" << endl;	
			else
				cout << "Reached end of file: missing ')'" << endl;	
		}

		else if(((count1+count4) % 2) != 0)
		{
			if(count1 < count4)
				cout << "Reached end of file: missing '{'" << endl;
			else
				cout << "Reached end of file: missing '}'" << endl;
		}
		else if(((count2+count5) % 2) != 0)
		{	
			if(count2 < count5)	
				cout << "Reached end of file: missing '['" << endl;
			else
				cout << "Reached end of file: missing ']'" << endl;
		}
		response = 'n';
	}
	else
	{
		cout<< "works :D" << endl;
		cout<< "Would you like to scan another file? Enter 'y' for yes or 'n' for no." << endl;
		cin >> response;
		while(response != 'y' && response != 'n')
		{
			cout << "Incorrect input. Please try again.\n";
            cin >> response;
		}
	}
	}
	return 0;
}

