#include <iostream>
#include <string>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
	facultyID = 0;
	name = "";
	level = "";
	department = "";
}

Faculty::~Faculty()
{
	
}

Faculty::Faculty(int m_facultyID, string m_name, string m_level, string m_department)
{
	facultyID = m_facultyID;
	name = m_name;
	level = m_level;
	department = m_department;
}

int Faculty::getID()
{
	return facultyID;
}

string Faculty::getName()
{
	return name;
}

string Faculty::getLevel()
{
	return level;
}

string Faculty::getDepartment()
{
	return department;
}

string Faculty::printInfo(int a, int numNode, string s)
{
	if(a == 1)//print terminal
	{
		cout << "---------------------------------------"<< endl;
		cout << "Faculty ID: "<< facultyID << endl;
		cout << "Name: " << name << endl;
		cout << "Level: " << level << endl;
		cout << "Department: " << department << endl;
		cout << "Advisees: " << endl;
		for(int i = 0; i < advisees.getSize(); ++i)
		{
			cout << "#" << i+1 << ": " << advisees.getAt(i) << endl;	
		}
		return "---------------------------------------";
	}
	else if(a == 2)//write to file
	{
		ofstream writeFile2("FacultyData.txt",fstream::app);
		if(writeFile2.is_open())
		{
			writeFile2 << facultyID << endl;
			writeFile2 << name << endl;
			writeFile2 << level << endl;
			writeFile2 << department << endl;
			writeFile2 << advisees.getSize() << endl;
			for(int i = 0; i < advisees.getSize(); ++i)
			{
				writeFile2 << advisees.getAt(i) << endl;	
			}
		}
		writeFile2.close();
	}
}

void Faculty::setID(int m_facultyID)
{
	facultyID = m_facultyID;
}

void Faculty:: setName(string m_name)
{
	name = m_name;
}

void Faculty:: setLevel(string m_level)
{
	level = m_level;
}

void Faculty:: setDepartment(string m_department)
{
	department = m_department;
}

void Faculty:: addAdvisees(int a)
{
	advisees.insertBack(a);
}

int Faculty:: getAdvisees(int a)
{
	if(!advisees.isEmpty())
	{
			return advisees.getAt(a);
	}
	else
	{
		cout << "Faculty has no advisees" << endl;
		return -1;
	}
}

int Faculty::numAdvisees()
{
	return advisees.getSize();
}
void Faculty::removeAdvisees(int a)
{
	pos = advisees.find(a);
	advisees.deletePos(pos);
	
}

void Faculty::printAdvisees()
{
	if(!advisees.isEmpty())
	{
		cout << "Advisees: " << endl;
		for(int i = 0; i < advisees.getSize(); ++i)
		{
			cout << "#" << i+1 << ": " << advisees.getAt(i) << endl;	
		}
	}
	else
		cout << "Faculty has no advisees" << endl;
}

bool Faculty::hasAdvisees(int a)
{
	return advisees.isEmpty();
}
