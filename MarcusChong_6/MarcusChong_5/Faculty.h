#include<iostream>
#include<string>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include "NaiveList.h"


using namespace std;

class Faculty
{
	private: 
		int facultyID, pos;
		string name, level, department;
		NaiveList<int> advisees;
		ofstream writeFile2(string s2);
		
	public:
		Faculty();
		~Faculty();
		Faculty(int m_facultyID, string m_name, string m_level, string m_department);
		int getID();
		string getName();
		string getLevel();
		string getDepartment();
		string printInfo(int a, int numNode, string s);
		void setID(int m_facultyID);
		void setName(string m_name);
		void setLevel(string m_level);
		void setDepartment(string m_major);
		void addAdvisees(int a);
		int getAdvisees(int a);
		int numAdvisees();
		void removeAdvisees(int a);
		void printAdvisees();
		bool hasAdvisees(int a);
		
};
