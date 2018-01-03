#include <iostream>
#include <string>



using namespace std;


class Student
{
	
	private:
		int timeArrive, timeNeeded, timeWaited;
		
		
	public:
		Student()
		{
		
		}
		
		~Student()
		{
		
		}
		
		Student(int a, int b, int c) //i is the time each student needs
		{
			timeArrive = a;
			timeNeeded = b;
			timeWaited = c;
		}
		
		int getTimeArrive()
		{
			return timeArrive;
		}
		
		int getTimeNeeded()
		{
			return timeNeeded;
		}
		
		int getTimeWaited()
		{
			return timeWaited;
		}
		
		void setTimeWaited()
		{
			timeWaited++;
		}
		
		void setWTimeWaited()
		{
			timeWaited--;
		}
		
};