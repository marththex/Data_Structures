#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 
#include <cmath> 
#include "GenQueue.h"
#include "Student.h"



using namespace std;

class QueueError : public exception //My Exception 
{
	virtual const char* what() const throw()
	{
		return " ERROR: Out of bounds exception.";
	}
} queueEx;	

class OtherError : public exception 
{
	virtual const char* what() const throw()
	{
		return "---------------------------------------------------------------";
	}
} otherEx;	

class Registrar
{
	
	private:
		GenQueue<Student*> myQueue;
		NaiveList<int> windowTimes;//time at the window
		NaiveList<double> windowIdle;//windows
		NaiveList<double> windowIdleTime;
		NaiveList<double> calculate;
		int calPos;
		string textName;
		fstream readFile;
		string line;
		int* timeNeed;
		int size, time, windows, noWindows, tempWindow; 
		double numStudents, avgWait, medianWait, maxSize, maxStudentWait;
		double studentsOver10, avgWindow, maxWindows, windowsOver5, maxWindowIdle;
		bool prev;
		
	public:
		
		Registrar()
		{
			timeNeed = new int(4);
			size = 4;
		}
		~Registrar()
		{
			delete[] timeNeed;
		}
		void resizeArray()
		{
			size = sizeof(timeNeed);
			int* newArray  = new int[size*2];
			for(int i = 0; i < size; ++i)
			{
				newArray[i] = timeNeed[i];
			}
			delete[] timeNeed;
			timeNeed  = newArray;
			size *= 4;
			
		}
		
		int newStudent(int i, int j)//creates new student and puts it into the queue
		{
				Student* student = new Student(i,j, 0);
				myQueue.insert(student);			
		}
		
		int readInFile(string s)
		{
			int pos = 0, count = 0, numStudent = 0;
			int student = 0;
			readFile.open(s.c_str());
			readFile >> windows;
			maxWindows = windows;
			while(!readFile.eof())
			{
				if(size%2 == 0)
				{
					resizeArray();
				}	
				readFile >> time;
				if(!readFile)
				{
					break;
				}
				
				readFile >> student;
				
				for(int i = 0; i < student; ++i)//puts the time the students needs into the array
				{
					readFile >> timeNeed[pos];
					pos++;   
					count++;
				}
				pos = pos-count;
				count = 0;
				for (int i = 0; i < student; ++i) //create new students
				{
					newStudent(time, timeNeed[pos]);
					pos++;
					
				}
			}
			
			return 0;
		}
		
		int getTimeArrived()
		{
			try
			{
				if(myQueue.isEmpty())
					throw otherEx;
				return (myQueue.peek()) -> getTimeArrive();
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}
		
		int getTimeNeeded()
		{
			try
			{
				if(myQueue.isEmpty())
					throw queueEx;
				return (myQueue.peek()) -> getTimeNeeded();
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}
		
		int getTimeWaited()
		{
			
				return (myQueue.peek()) -> getTimeWaited();
			
		
		}
		
		void setTimeWaited()
		{
			
				
				(myQueue.peek()) -> setTimeWaited();
			
			
		}
		
		void remove()
		{
			try
			{
				if(myQueue.isEmpty())
					throw myex;
				myQueue.remove(); 
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}
		
		int run()
		{
			cout << "-----------------------------------------" << endl;
			cout<< "Welcome to the Registrar" << endl;	
			cout << "-----------------------------------------" << endl;
			cout << endl;
			
			cout<< "Enter the location of the text file." << endl;
			cin >> textName;
			while ( !(ifstream(textName.c_str())))// Checks to see if the text file exist
			{
				cout << "Can't find file! Please try again." << endl;
				cin >> textName;
			}
			readInFile(textName);
			cout << "Starting Size: " << myQueue.getSize() << endl;
			cout << "Num Windows: " << windows << endl;
			time = 0;
			calPos = 0;
			avgWindow = 0;
			for(int m = 0; m < maxWindows; ++m)// Fill up Windows
			{
				windowIdle.insertBack(0);
				windowTimes.insertBack(0);
					
			}	
			for(int m = 0; m < windowIdle.getSize(); ++m)// The mean window idle time
			{
				cout << "window:" << windowIdle.getAt(m) << endl;			
			}
			while(!myQueue.isEmpty())
			{	
				cout << "-----------------------------------------" << endl;
				cout << "Time: " << time << endl;
				cout << "-----------------------------------------" << endl;
				cout << endl;
				cout << "# windows: " << windows << endl;
				
				cout << "queue size: " << myQueue.getSize() << endl;
				
				while(getTimeArrived() <= time && windows != 0)//if customer arrives
				{
					tempWindow = windows;
					for(int i = 0; i < maxWindows; ++i)// closes next avaliable window
					{
							
						if(windowIdle.getAt(i) >= 0)
						{
								avgWait = avgWait + getTimeWaited();
								avgWindow = avgWindow + windowIdle.getAt(i);
								//cout << "Time Waited :" << getTimeWaited() << endl;
								calculate.insertBack(getTimeWaited());
								windowTimes.windowTimeNeeded(i,getTimeNeeded());
								windowIdleTime.insertBack(windowIdle.getAt(i));
								
								remove();
								windowIdle.closedWindow(i);
								numStudents++;	
								windows--;
						}                                                 
						if(tempWindow != windows)
							break;
						
							
					}
				
				}
				
				for(int i = 0; i < windowIdle.getSize(); ++i)// increase window idle time
				{
					cout << "window before:" << windowIdle.getAt(i) << endl;
				
						windowIdle.remainZero(i);
					cout << "window after:" << windowIdle.getAt(i) << endl;
				
				}
				
				for(int i = 0; i < windowTimes.getSize(); ++i)//checks if people left the windows
				{		
					
					if(maxWindows == 1 && windowTimes.getAt(i) <= 0)
					{
						windows++;
						windowIdle.reopenWindow(i);
					}
					if(windowTimes.getAt(i) == 0)
					{
						windows++;
						windowIdle.reopenWindow(i);
					}	
					
				}
					
				for(int j = 0; j < myQueue.getSize(); ++j)//increases waittimes for everyone in line
				{
					
						(myQueue.getAt(j)) -> setTimeWaited();
					
							
				}
				
				time++;
			
			}
				
			
			
		
			calculate.sorting();
			windowIdleTime.sorting();
			//cout << "done sorting" << endl;
			maxStudentWait = calculate.getAt(calculate.getSize()-1);//The longest student wait time.
			maxWindowIdle = windowIdleTime.getAt(windowIdleTime.getSize()-1);//The longest window idle time
			int num;
			studentsOver10 = 0;
			windowsOver5 = 0; 
			//AVERAGE
			for(int j = 0; j < calculate.getSize(); ++j)
			{
				cout << "student wait times: " << calculate.getAt(j) << endl;
				if(calculate.getAt(j) > 10)//The number of students waiting over 10 minutes
					studentsOver10++;
			}
			
			avgWindow = 0;
			for(int m = 0; m < windowIdleTime.getSize()-1; ++m)// The mean window idle time
			{
				cout << "windowIdleTime:" << windowIdle.getAt(m) << endl;
				if(windowIdleTime.getAt(m) > 5)//Number of windows idle for over 5 minutes.
					windowsOver5++;
					
			}
		
			if(calculate.getSize() % 2 == 0) // if even amount of students
			{	
				int a, b;
				a = calculate.getSize() / 2;
				b = a+1;
				medianWait = (calculate.getAt(a) + calculate.getAt(a))/2;
			}
			else
			{
				medianWait = calculate.getAt((calculate.getSize() / 2));
			}
		
			cout << "The mean student wait time: " << avgWait/numStudents << endl;
			cout << "The median student wait time: " << medianWait << endl;
			cout << "The longest student wait time: " << maxStudentWait << endl;
			cout << "The number of students waiting over 10 minutes: " << studentsOver10 << endl;
			cout << "The mean window idle time: " << avgWindow/windowIdle.getSize() << endl;
			cout << "The longest window idle time: " << maxWindowIdle << endl;
			cout << "Number of windows idle for over 5 minutes: " << windowsOver5 << endl;
			
			return 0;
			
		}
	
		
};
