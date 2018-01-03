#include <iostream>
#include <string>
#include "RollOver.h"

using namespace std;

RollOver::RollOver()
{
	id = -1;
	id2 = -1;
	advisor = -1;
	name = "";
	level = "";
	major = "";
	department = "";
	GPA = -1.0;
	undo = -1;
}

RollOver::RollOver(int m_id, string m_name, string m_level, string m_major, double m_GPA, int m_advisor, int m_undo)//STUDENT
{
	id = m_id;
	id2 = -1;
	advisor = m_advisor;
	name = m_name;
	level = m_level;
	major = m_major;
	department ="NO DEPARTMENT";
	GPA = m_GPA;
	undo = m_undo;
}

RollOver::RollOver(int m_id, string m_name, string m_level, string m_department, int m_undo)//FACULTY
{
	id = m_id;
	id2 = -1;
	advisor = -1;
	name = m_name;
	level = m_level;
	major = "NO MAJOR";
	department = m_department;
	GPA = -1.0;
	undo = m_undo;
}

RollOver::RollOver(int m_id, int m_id2, int m_undo)//FACULTY
{
	id = m_id;
	id2 = m_id2;
	advisor = -1;
	name = "NO NAME";
	level = "NO LEVEL";
	major = "NO MAJOR";
	department = "NO DEPARTMENT";
	GPA = -1.0;
	undo = m_undo;
}

RollOver::RollOver(int m_id, int m_id2, int m_advisor, int m_undo)//FACULTY
{
	id = m_id;
	id2 = m_id2;
	advisor = m_advisor;
	name = "NO NAME";
	level = "NO LEVEL";
	major = "NO MAJOR";
	department = "NO DEPARTMENT";
	GPA = -1.0;
	undo = m_undo;
}

RollOver::~RollOver()
{

}

int RollOver::getID()
{
	return id;
}

int RollOver::getID2()
{
	return id2;
}

string RollOver::getName()
{
	return name;
}

string RollOver::getLevel()
{
	return level;
}

string RollOver::getMajor()
{
	return major;
}

double RollOver::getGPA()
{
	return GPA;
}

int RollOver::getAdvisor()
{
	return advisor;
}

string RollOver::getDepartment()
{
	return department;
}

int RollOver::getUndo()
{
	return undo;
}

void RollOver::setID(int m_id)
{
	id = m_id;
}

void RollOver::setID2(int m_id2)
{
	id2 = m_id2;
}

void RollOver:: setName(string m_name)
{
	name = m_name;
}

void RollOver:: setLevel(string m_level)
{
	level = m_level;
}

void RollOver:: setMajor(string m_major)
{
	major = m_major;
}

void RollOver:: setGPA(double m_GPA)
{
	GPA = m_GPA;
}

void RollOver:: setAdvisor(int m_advisor)
{
	advisor = m_advisor;
}

void RollOver:: setDepartment(string m_department)
{
	department = m_department;
}

void RollOver::setUndo(int m_undo)
{
	undo = m_undo;
}
