#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Sorting
{
	public:
		Sorting();
		~Sorting();
		void quickSort(double arr[], int left, int right);
		void insertionSort(double arr[]);
		void bubbleSort(double arr[]);
		void printTime();
		ifstream readFile;
		string fileName;
		int answer, arraySize;                       
		double value;
		
};