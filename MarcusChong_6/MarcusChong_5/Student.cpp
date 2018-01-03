#include<iostream>
#include<string>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>

#include "Student.h"

using namespace std;

Student::Student()
{
	studentID = 0;
	name = "";
	level = "";
	major = "";
	GPA = 0.0;
	advisor = 0;
}

Student::~Student()
{
	
}

Student::Student(int m_studentID, string m_name, string m_level, string m_major, double m_GPA, int m_advisor)
{
	studentID = m_studentID;
	name = m_name;
	level = m_level;
	major = m_major;
	GPA = m_GPA;
	advisor = m_advisor;
}

int Student::getID()
{
	return studentID;
}

string Student::getName()
{
	return name;
}

string Student::getLevel()
{
	return level;
}

string Student::getMajor()
{
	return major;
}

double Student::getGPA()
{
	return GPA;
}

int Student::getAdvisor()
{
	return advisor;
}

bool Student::isGreaterThan(Student* s)
{
	return (getID() <  s -> getID());
}

bool Student::isLessThan(Student* s)
{
	return (getID() > s -> getID());
}

bool Student::isEqual(Student* s)
{
	return (getID() == s -> getID());
}

string Student::printInfo(int a, int numNode, string s)
{
	if(a==1)
	{
		cout << "---------------------------------------" << endl;
		cout << "Student ID: "<< studentID << endl;
		cout << "Name: " << name << endl;
		cout << "Level: " << level << endl;
		cout << "Major: " << major << endl;
		cout << "GPA: " << GPA << endl;
		cout << "Advisor: " << advisor << endl;
		return "---------------------------------------";
	}
	else if(a == 2)
	{
		ofstream writeFile("StudentData.txt",fstream::app);
		if(writeFile.is_open())
		{
			writeFile << studentID << endl;
			writeFile<< name << endl;
			writeFile<< level << endl;
			writeFile<< major << endl;
			writeFile << GPA << endl;
			writeFile << advisor << endl;
		}
		writeFile.close();
	}
}

void Student::setID(int m_studentID)
{
	studentID = m_studentID;
}

void Student:: setName(string m_name)
{
	name = m_name;
}

void Student:: setLevel(string m_level)
{
	level = m_level;
}

void Student:: setMajor(string m_major)
{
	major = m_major;
}

void Student:: setGPA(double m_GPA)
{
	GPA = m_GPA;
}

void Student:: setAdvisor(int m_advisor)
{
	advisor = m_advisor;
}
