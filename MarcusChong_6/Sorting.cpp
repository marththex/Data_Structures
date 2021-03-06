#include<iostream>
#include<string>
#include "Sorting.h"
#include <ctime>



using namespace std;


Sorting::Sorting()
{
	fileName = "";
	answer = 0;
}

Sorting::~Sorting()
{

}

void Sorting::quickSort(double arr[], int left, int right)
{
   	 int i = left, j = right;
     int tmp;
     int pivot = arr[(left + right) / 2];
 
      /* partition */
     while (i <= j) 
     {
           while (arr[i] < pivot)
                 i++;
           while (arr[j] > pivot)
                 j--;
           if (i <= j) {
                 tmp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = tmp;
                 i++;
                 j--;
           }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void Sorting::insertionSort(double arr[])
{
	int i, j ,tmp;
	 for (i = 1; i < arraySize; i++) 
	 {
		 j = i;
		 while (j > 0 && arr[j - 1] > arr[j])
		 {
			 tmp = arr[j];
			 arr[j] = arr[j - 1];
			 arr[j - 1] = tmp;
			 j--;
		 }//end of while loop
	
	 }//end of for loop
}

void Sorting::bubbleSort(double arr[])
{
	int temp;	
	for (int c = 0 ; c < ( arraySize - 1 ); c++)
	{
		for (int d = 0 ; d < arraySize - c - 1; d++)
		{
			  if (arr[d] > arr[d+1]) /* For decreasing order use < */
			  {
				temp = arr[d];
				arr[d] = arr[d+1];
				arr[d+1] = temp;
			  }
		}
    }
 
}

void Sorting::printTime()
{
	
	while( answer != 1) 
	{ //does not exit program until the user says so
	
	cout << "What is the name of the file you would like to read (include .txt)" << endl;
	cin >> fileName;
	

	while ( !(ifstream(fileName.c_str())))// Checks to see if the text file exist
	{
		cout << "Can't find my file! Please try again." << endl;
		cin >> fileName;
	}
	readFile.open(fileName.c_str());

	readFile >> arraySize; 
	double dummyArray[arraySize];
	double doubleArray1[arraySize];
	double doubleArray2[arraySize];
	double doubleArray3[arraySize];
	for(int i = 0; i < arraySize; ++i)
	{
		if(!readFile)
			break;
		readFile >> value;
		dummyArray[i] = value;
		doubleArray1[i] = value;
		doubleArray2[i] = value;
		doubleArray3[i] = value;
		
	}
	readFile.close();
	clock_t start, end;
	
	start = clock();
  //  end = clock();
    
	cout << "QuickSort: " << endl;
	cout << "Before: " << "0" << " ms" << endl;
	start = clock();
    quickSort(doubleArray1, 0, arraySize-1);
    end = clock();
    cout << "After: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    cout << endl;
    
    cout << "Insertion Sort: " << endl;
	cout << "Before: " << "0" << " ms" << endl;
    start = clock();
    insertionSort(doubleArray2);
    end = clock();
    cout << "After: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    cout << endl;
    
    cout << "Bubble Sort: " << endl;
	cout << "Before: " << "0" << " ms" << endl;
    start = clock();
    bubbleSort(doubleArray3);
    end = clock();
    cout << "After: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	 cout << endl; 
	
	
	cout << "Done! Would you like to read a different file? Press '0' for yes or 1 for 'no'." << endl;
	cin >> answer;
	}
	
	cout << "Goodbye!!!!" << endl;
	
}