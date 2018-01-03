#include<iostream>
#include<string>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;

class Student
{
	private: 
		int studentID, advisor;
		string name, level, major;
		double GPA;
		
		
		
	public:
		Student();
		~Student();
		Student(int m_studentID, string m_name, string m_level, string m_major, double m_GPA, int m_advisor);
		int getID();
		string getName();
		string getLevel();
		string getMajor();
		double getGPA();
		int getAdvisor();
		bool isGreaterThan(Student* s);
		bool isLessThan(Student* s);
		bool isEqual(Student* s);
		string printInfo(int a, int numNode, string s);
		void setID(int m_studentID);
		void setName(string m_name);
		void setLevel(string m_level);
		void setMajor(string m_major);
		void setGPA(double m_GPA);
		void setAdvisor(int m_advisor);
		
};