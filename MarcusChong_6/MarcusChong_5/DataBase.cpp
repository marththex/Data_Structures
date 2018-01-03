#include <iostream>
#include <string>
#include "DataBase.h"



using namespace std;

DataBase::DataBase()
{
	option = 0;
	id = 0;
	id2 = 0;
	advisor= 0;
	advisees = 0;
	name = "";
	level = "";
	major = "";
	department = "";
	GPA = 0.0;
	undoLimit = 0;
	string1 = "";
	string2 = "";
}

DataBase::~DataBase()
{
	
}

void DataBase::option1()//1. Print all students and their information (sorted by ascending id #)
{
	studentTree.printTree(1, numStu, string1);
}

void DataBase::option2()//2. Print all faculty and their information (sorted by ascending id #)
{
	facultyTree.printTree(1, numFac, string2);
}

void DataBase::option3()//3. Find and display student information given the students id
{
	cout << "" << endl;
	cout << "What is the Student's ID Number?" << endl;
	cin >> id;
	if(studentTree.contains(id)== false)
		cout << "Student not found" << endl;
	else
		studentTree.printNode(id);
	
}

void DataBase::option4()//4. Find and display faculty information given the faculty id
{
	cout << "" << endl;
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id;
	if(facultyTree.contains(id)== false)
		cout << "Faculty not found" << endl;
	else
		facultyTree.printNode(id);
}

void DataBase::option5()//5. Given a student’s id, print the name and info of their faculty advisor
{
	cout << "" << endl;
	cout << "What is the Student's ID Number?" << endl;
	cin >> id;
	if(studentTree.contains(id)== false)
		cout << "Student not found" << endl;
	else
		facultyTree.printNode((studentTree.getNode(id))->getAdvisor());
}


void DataBase::option6()//6. Given a faculty id, print ALL the names and info of his/her advisees.
{
	cout << "" << endl;
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id;
	if(facultyTree.contains(id)== false)
		cout << "Faculty not found" << endl;
	else
		for(int i = 0; i < (facultyTree.getNode(id))-> numAdvisees(); ++i)
		{
			studentTree.printNode((facultyTree.getNode(id))->getAdvisees(i));
		}

}

void DataBase::option7()//7. Add a new student
{
	if(facultyTree.isEmpty()==true)
		cout << "ERROR: NO FACULTY IN FACULTY TREE" << endl;
	else
	{
		cout << "" << endl;
		cout << "What is the Student's ID Number?" << endl;
		cin >> id;
		while(studentTree.contains(id) == true || facultyTree.contains(id) == true )
		{
			cout << "ERROR: ID ALREADY TAKEN. PLEASE TYPE IN A DIFFERENT ID." << endl;
			cin >> id;
		}
		cout << "What is the Student's Name?" << endl;
		cin >> name;
		cout << "What is the Student's Level?" << endl;
		cin >> level;
		cout << "What is the Student's Major?" << endl;
		cin >> major;
		cout << "What is the Student's GPA?" << endl;
		cin >> GPA;
		cout << "What is the Advisor's ID Number?" << endl;
		cin >> advisor;
		while(facultyTree.contains(advisor) == false)
		{
			cout <<"ERROR: CANNOT FIND ID IN FACULTY TREE. PLEASE TRY AGAIN." << endl;
			cin >> advisor;
		}
		Student* student = new Student(id, name, level, major, GPA, advisor);
		rollBack.insertFront(new RollOver(id, name, level, major, GPA, advisor, 1));//RollBack is delete student
		if(( facultyTree.getNode(advisor)) -> numAdvisees() == 0 || facultyTree.getNode(advisor) -> hasAdvisees(id) == false)
			(facultyTree.getNode(advisor)) -> addAdvisees(id);
		studentTree.insert(student);
		undoLimit++;
		cout << "Student: " << id << " added" << endl;
		numStu++;
	}
}


void DataBase::option8()//8. Delete a student given the id
{
	cout << "What is the Student's ID Number?" << endl;
	cin >> id;
	if(studentTree.contains(id) == false)
	{
		cout << "ERROR: STUDENT NOT FOUND" << endl;
	}
	else
	{
		//id2 = studentTree.getNode(id) -> getAdvisor();//advisor's id
		//facultyTree.getNode(id2) -> removeAdvisees(id);
		rollBack.insertFront(new RollOver(id, studentTree.getNode(id) -> getName(), studentTree.getNode(id) -> getLevel(), studentTree.getNode(id) -> getMajor(), studentTree.getNode(id) -> getGPA(), studentTree.getNode(id) -> getAdvisor(), 2));//RollBack is insert student
		facultyTree.getNode(studentTree.getNode(id)->getAdvisor())-> removeAdvisees(id);
			
		studentTree.deleteNode(id); 
		cout << "Student: " << id << " deleted" << endl;
		undoLimit++;
		numStu--;
	}
	
	
}


void DataBase::option9()//9. Add a new faculty member
{
	cout << "" << endl;
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id;
	while(studentTree.contains(id) == true || facultyTree.contains(id) == true)
	{
		cout << "ERROR: ID ALREADY TAKEN. PLEASE TYPE IN A DIFFERENT ID." << endl;
		cin >> id;
	}
	cout << "What is the Faculty's Name?" << endl;
	cin >> name;
	cout << "What is the Faculty's Level?" << endl;
	cin >> level;
	cout << "What is the Faculty's Department?" << endl;
	cin >> department;
	Faculty* faculty = new Faculty(id, name, level, department);
	/*cout << "How many Advisees does this Faculty have?" << endl;
	cin >> advisees;
	for(int i = 0; i < advisees; ++i)
	{
		cout <<"Type in the Advisee " << "#" << i+1 << " ID Number." << endl;
		cin >> id2;
		while(studentTree.contains(id2) == false)
		{
			cout << "ERROR: CANNOT FIND ID NUMBER IN STUDENT TREE. PLEASE TYPE IN ANOTHER ID" << endl;
			cin >> id2;
		}
		while(faculty->hasAdvisees(id2) == true)
		{
			cout << "ERROR: ALREADY AN ADVISEE. PLEASE TYPE IN ANOTHER ID" << endl;
			cin >> id2;
		}
		faculty-> addAdvisees(id);
	}*/
	facultyTree.insert(faculty);
	rollBack.insertFront(new RollOver(id, name, level, department, 3));//RollBack is delete faculty
	cout << "Faculty: " << id << " added" << endl;
	undoLimit++;
	numFac++;
}

void DataBase::option10()//10. Delete a faculty member given the id.
{
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id;
	if(facultyTree.contains(id) == false)
	{
		cout << "ERROR: FACULTY NOT FOUND" << endl;
	}
	else
	{
		cout << (facultyTree.getNode(id)) -> hasAdvisees(id) << endl;
		if((facultyTree.getNode(id)) -> hasAdvisees(id) == false)
		{
			cout << "Advisor changed is needed:" << endl;
			//cout << (facultyTree.getNode(id)) -> numAdvisees() << endl;
			for(int i = 0; i < (facultyTree.getNode(id)) -> numAdvisees(); ++i)
			{
				cout << "What is Student: " << facultyTree.getNode(id) -> getAdvisees(i) << " new Advisor's ID Number?" << endl;
				cin >> advisor;
				while(facultyTree.contains(advisor) == false || advisor == id)
				{
					cout <<"ERROR: CANNOT FIND ID IN FACULTY TREE. PLEASE TRY AGAIN." << endl;
					cin >> advisor;
				}
				studentTree.getNode(((facultyTree.getNode(id)) -> getAdvisees(i)))-> setAdvisor(advisor);
				(facultyTree.getNode(advisor)) -> addAdvisees((facultyTree.getNode(id)) -> getAdvisees(i));
			}
		}
		facultyTree.deleteNode(id);
		cout << "Faculty: " << id << " deleted" << endl;
		rollBack.insertFront(new RollOver(id, name, level, department, 4));//RollBack is insert faculty
		undoLimit++;
		numFac--;
	}
	
}


void DataBase::option11()//11. Change a student’s advisor given the student id and the new faculty id.
{
	cout << "What is the Student's ID Number?" << endl;
	cin >> id;
	while(studentTree.contains(id) == false)
	{
		cout << "ERROR: CANNOT FIND ID NUMBER IN STUDENT TREE. PLEASE TYPE IN ANOTHER ID" << endl;
		cin >> id;
	}
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id2;
	while(facultyTree.contains(id2) == false)
	{
		cout << "ERROR: CANNOT FIND ID NUMBER IN FACULTY TREE. PLEASE TYPE IN ANOTHER ID" << endl;
		cin >> id2;
	}
	rollBack.insertFront(new RollOver(id,id2, studentTree.getNode(id) -> getAdvisor(),5));//RollBack is change student advisor
	(facultyTree.getNode(studentTree.getNode(id) -> getAdvisor())) -> removeAdvisees(id);
	(studentTree.getNode(id)) -> setAdvisor(id2);
	(facultyTree.getNode(id2)) -> addAdvisees(id);
	undoLimit++;
	
}


void DataBase::option12()//12. Remove an advisee from a faculty member given the ids
{
	cout << "What is the Faculty's ID Number?" << endl;
	cin >> id;
	while(facultyTree.contains(id) == false)
	{
		cout << "ERROR: CANNOT FIND ID NUMBER IN Faculty TREE. PLEASE TYPE IN ANOTHER ID" << endl;
		cin >> id;
	}
	cout << "What is the Advisee's ID Number?" << endl;
	cin >> id2;
	while((facultyTree.getNode(id)) -> hasAdvisees(id2) == true)
	{
		cout << "ERROR: CANNOT FIND ADVISEE. PLEASE TYPE IN ANOTHER ID" << endl;
		cin >> id2;
	}
	(facultyTree.getNode(id)) -> removeAdvisees(id2);//FIX THIS
	cout << "What is the Advisee's new Advisor?" << endl;
	cin >> advisor;
	while(facultyTree.contains(advisor) == false)
	{
		cout << "ERROR: CANNOT FIND ID NUMBER IN Faculty TREE. PLEASE TYPE IN ANOTHER ID" << endl;
		cin >> advisor;
	}
	facultyTree.getNode((studentTree.getNode(id2))-> getAdvisor()) -> removeAdvisees(id2);//FIX THIS
	(studentTree.getNode(id2))-> setAdvisor(advisor);
	(facultyTree.getNode(advisor))-> addAdvisees(id2);
	rollBack.insertFront(new RollOver(id,id2,advisor,6));//RollBack is insert advisee
	undoLimit++;
}


void DataBase::option13()//13. Rollback
{
	if(rollBack.isEmpty())
		cout << "Nothing left to Undo" << endl;
	
	else if((rollBack.getFront())->getUndo() == 1 && undoLimit > 0)//RollBack is delete student
	{
		facultyTree.getNode((rollBack.getFront()) -> getAdvisor())->removeAdvisees((rollBack.getFront()) -> getID());
		studentTree.deleteNode((rollBack.getFront()) -> getID()); 
		rollBack.removeFront();
		numStu--;
		undoLimit--;
	}
	else if((rollBack.getFront())->getUndo() == 2 && undoLimit > 0)//RollBack is insert student
	{
		cout<<"test" << endl;
		Student* student = new Student((rollBack.getFront())->getID(),(rollBack.getFront())->getName(),(rollBack.getFront())->getLevel(),(rollBack.getFront())->getMajor(), (rollBack.getFront())->getGPA(),(rollBack.getFront())->getAdvisor());
		studentTree.insert(student);
		facultyTree.getNode((rollBack.getFront())->getAdvisor()) -> addAdvisees((rollBack.getFront())->getID());
		rollBack.removeFront();
		numStu++;
		undoLimit--;
	}
	else if((rollBack.getFront())->getUndo() == 3 && undoLimit > 0)//RollBack is delete faculty
	{
		facultyTree.deleteNode((rollBack.getFront()) -> getID());
		rollBack.removeFront();
		numFac--;
		undoLimit--;
	}
	else if((rollBack.getFront())->getUndo() == 4 && undoLimit > 0)//RollBack is insert faculty
	{
		Faculty* faculty = new Faculty((rollBack.getFront())->getID(), (rollBack.getFront())->getName(), (rollBack.getFront())->getLevel(), (rollBack.getFront())->getDepartment());
		facultyTree.insert(faculty);
		rollBack.removeFront();
		numFac++;
		undoLimit--;
	}
	else if((rollBack.getFront())->getUndo() == 5 && undoLimit > 0)//RollBack is change student advisor
	{
		//stu, new, old
		(facultyTree.getNode(studentTree.getNode((rollBack.getFront())->getID()) -> getAdvisor())) -> removeAdvisees((rollBack.getFront())->getID());
		(studentTree.getNode((rollBack.getFront())->getID())) -> setAdvisor((rollBack.getFront())->getAdvisor());
		(facultyTree.getNode((rollBack.getFront())->getID2())) -> addAdvisees((rollBack.getFront())->getID());
		undoLimit--;
		
	}
	else if((rollBack.getFront())->getUndo() == 6 && undoLimit > 0)//RollBack is insert advisee
	{
		//fac, advisee, new Advisor
		facultyTree.getNode((rollBack.getFront())->getAdvisor()) -> removeAdvisees((rollBack.getFront())->getID2());
		(studentTree.getNode((rollBack.getFront())->getID2()))-> setAdvisor(id);
		(facultyTree.getNode(id))-> addAdvisees((rollBack.getFront())->getID2());
		undoLimit--;
	}
	else
		cout << "Nothing left to Undo" << endl;
}

void DataBase::readInFile(string s, string s2)
{
	
	
		readFile.open(s.c_str());
		readFile >> numStu;
		for(int i = 0; i < numStu; ++i)
		{
			readFile >> id;
			readFile >> name;
			readFile >> level;
			readFile >> major;
			readFile >> GPA;
			readFile >> advisor;
			Student* student = new Student(id, name, level, major, GPA, advisor);
			studentTree.insert(student);
		}
		readFile.close();
	
	
		readFile2.open(s2.c_str());
		readFile2 >> numFac;
		for(int i = 0; i < numFac; ++i)
		{
			//cout << "test" << endl;
			readFile2 >> id;
			readFile2 >> name;
			readFile2 >> level;
			readFile2 >> department;
			Faculty* faculty = new Faculty(id, name, level, department);
			readFile2 >> advisees;
			for(int j = 0; j < advisees; ++j)
			{
				readFile2  >> id2;
				faculty -> addAdvisees(id2);
			}
			facultyTree.insert(faculty);
		}
		readFile2.close();
	
}

void DataBase::run()
{
	string1 = "StudentData.txt";
	string2 = "FacultyData.txt";
	readInFile(string1,string2);
	
	cout << "----------------------------------------" << endl;
	cout << "Welcome to the Database" << endl;
	cout << "----------------------------------------" << endl;
	while(option != 14)
	{
		cout << "" << endl;
		cout << "Choose an option:" << endl;
		cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
		cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
		cout << "3. Find and display student information given the students id" << endl;
		cout << "4. Find and display faculty information given the faculty id" << endl;
		cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
		cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
		cout << "7. Add a new student" << endl;
		cout << "8. Delete a student given the id" << endl;
		cout << "9. Add a new faculty member" << endl;
		cout << "10. Delete a faculty member given the id." << endl;
		cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
		cout << "12. Remove an advisee from a faculty member given the ids" << endl;
		cout << "13. Rollback" << endl;
		cout << "14. Exit" << endl;
		cin >> option;
		if(option == 1)
			option1();
		else if (option == 2)
			option2();
		else if (option == 3)
			option3();
		else if (option ==4)
			option4();
		else if (option == 5)
			option5();
		else if (option == 6)
			option6();
		else if (option == 7)
			option7();
		else if (option == 8)
			option8();
		else if (option == 9)
			option9();
		else if (option == 10)
			option10();
		else if (option == 11)
			option11();
		else if (option == 12)
			option12();
		else if (option == 13)
			option13();
		else if(option == 14)
			{}
		else
			cout << "ERROR: INVALID OPTION" << endl;	
	}
	ofstream writeFile("StudentData.txt");
	if(writeFile.is_open())
	{
		writeFile << numStu << endl;
	}
	writeFile.close();
	ofstream writeFile2("FacultyData.txt");
	if(writeFile2.is_open())
	{
		writeFile2 << numFac << endl;
	}
	writeFile2.close();
	if(!studentTree.isEmpty())
		studentTree.printTree(2, numStu, "StudentData.txt");
	if(!facultyTree.isEmpty())
	facultyTree.printTree(2, numFac, "FacultyData.txt");
	
	cout << "GOODBYE!!!" << endl;
	
}