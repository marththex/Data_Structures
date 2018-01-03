#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Map
{
	public:
		int introduction()
		{
			int mapFileOption = 0;; // Whether to provide or randomize a mapfile
	
	
			cout << "---------------------------------" << endl;
			cout<< "WELCOME TO THE GAME OF LIFE!" << endl;
			cout << "---------------------------------" << endl;
			cout << endl;
	
			cout << "Do you wish to provide a mapfile or would you like a random assignment?" << endl; // Ask the user for a map file
			cout <<  "Press '1' to provide a mapfile or '2' to make a random assignment." << endl;
			cin >> mapFileOption;
			
			while( mapFileOption != 1 && mapFileOption != 2) // checkes for valid input
			{
				cout << "ERROR: PLEASE TYPE IN A VALID INPUT" << endl;
				cin >> mapFileOption;
			}
			
			return mapFileOption;
		}
		
		string nameOfTxt()
		{
	
			cout << "What is the name of the file you would like to read (include .txt)" << endl;
			cin >> fileName;
	
			while ( !(ifstream(fileName.c_str())))// Checks to see if the text file exist
			{
				cout << "Can't find my file! Please try again." << endl;
				cin >> fileName;
			}
				
			return fileName;
			
		}
		
		int rowsTxt(string m_fileName)
		{
			ifstream readFile;
			answer = 0;
		
			readFile.open(m_fileName.c_str());
			for(int i = 0; i < 2; ++i)
				readFile >> dim[i];
			answer = dim[0];
		
			return answer ;
			readFile.close();   
		}
		
		int columnsTxt(string m_fileName)
		{
			ifstream readFile;
			answer = 0;
		
			readFile.open(m_fileName.c_str());
		
			for(int i = 0; i < 2; ++i)
				readFile >> dim[i];
			answer = dim[1];
	
			return answer ;
			readFile.close();   
		}
		
		bool isPopulated(string m_fileName, int a, int b, int m_rows, int m_columns) // checks if the a certain place in the grid is occupied
		{
			ifstream readFile;
			string temp[m_rows][m_columns]; 
			readFile.open(m_fileName.c_str());
			
			//cout << m_rows << " " << m_columns << endl;
			
			for(int i = 2; i < m_rows +2; ++i)
			{
				//cout<< "i: " << i << endl;
				for(int j = 0; j < m_columns; ++j)
				{
						
					readFile >> temp[i][j];
					
				//	cout << "i: " << i << " j: " << j << endl;
					//cout << temp[i][j] << endl;
				
							
				}
			}
					
			//cout << temp[a][b] << endl;
			if (temp[a][b] == "X")
				return true;
			else 
				return false;

			readFile.close();  
		}
		
		int rowsRand()
		{
			
			cout << "How may rows would you like in your map?" << endl;
			cin >> answer;
			return answer;
		}
		
		int columnsRand()
		{
			
			cout << "How may columns would you like in your map?" << endl;
			cin >> answer;
			return answer;
		}
		
		double population() // Initial Population Density
		{
	
			cout << "What is the intial population density (Type in a decimal between 0 and 1)?" << endl;
			cin >> d_answer;
			return d_answer;
		}
		
	private:
		
		int answer, line, count, stringLength;
		int dim[2];
		double d_answer;
		bool b_answer;
		string fileName, s_line, s_answer, number, temp_answer, test;
		

		
		

		
};
