#include<iostream>
#include<string>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;

int main(int argc, char ** argv)
{
	ifstream readFile;
	ofstream writeFile("MarcusChong.out");
	string fileName = "";

	string word;
	string name;
	int id;
	int stringLength = 0, stringLengthSquared =  0, numStrings=0;
	int numBigram = 0;
	
	int numA = 0, numC = 0, numT= 0, numG =  0; //number of Nucleotides
	int numAA = 0, numAC = 0, numAT = 0, numAG = 0, numCA = 0, numCC = 0, numCT = 0, numCG  = 0; 
	int numTA = 0, numTC = 0, numTT = 0, numTG = 0, numGA = 0, numGC = 0, numGT =  0,  numGG = 0; 
	double average = 0, variance = 0, stdDeviation = 0;
	
	double probA = 0, probC = 0, probT= 0, probG =  0; // probability of Nucleotides
	double probAA = 0, probAC = 0, probAT = 0, probAG = 0, probCA = 0, probCC = 0, probCT = 0, probCG  = 0; 
	double probTA = 0, probTC = 0, probTT = 0, probTG = 0, probGA = 0, probGC = 0, probGT =  0,  probGG = 0; 
	
	double a = 0.0, b = 0.0, randLetter = 0.0; 
	int randLength = 0;
	int answer = 0;
	
	while( answer != 1) { //does not exit program until the user says so
	
	cout << "What is the name of the file you would like to read (include .txt)" << endl;
	cin >> fileName;
	

	while ( !(ifstream(fileName.c_str())))// Checks to see if the text file exist
	{
		cout << "Can't find my file! Please try again." << endl;
		cin >> fileName;
	}
	readFile.open(fileName.c_str());

	
	while(!readFile.eof())
	{
		readFile >> word;
		if(!readFile)
			break;
		
		stringLength += word.length(); //Sum of DNA strings
		stringLengthSquared += ((word.length())* (word.length())); //Sum of of each DNA String squared
		
		for(int i = 0; i < word.size(); i++) //Check Single Nucleotide
		{
			
			if(word[i] == 'A' || word[i] == 'a') // Find number of 'A' in the file
			{
				numA++;
				
				//Find Bigram
				if(word[i+1] == 'A' || word[i+1] == 'a')
				{
					numAA++;
					numA++;
				}
				
				else if(word[i+1] == 'C' || word[i+1] == 'c')
				{
					numAC++;
					numC++;
				}
				
				else if(word[i+1] == 'T' || word[i+1] == 't')
				{				
					numAT++;
					numT++;
				}
				
				else if(word[i+1] == 'G' || word[i+1] == 'g')
				{	
					numAG++;
					numG++;
				}
			}
			
			else if(word[i] == 'C' || word[i] == 'c') // Find number of 'C' in the file
			{
				numC++;
				
				//Find Bigram
				if(word[i+1] == 'A' || word[i+1] == 'a')
				{
					numCA++;
					numA++;
				}
				
				else if(word[i+1] == 'C' || word[i+1] == 'c')
				{
					numCC++;
					numC++;
				}
				
				else if(word[i+1] == 'T' || word[i+1] == 't')
				{
					numCT++;
					numT++;
				}
				
				else if(word[i+1] == 'G' || word[i+1] == 'g')
				{
					numCG++;
					numG++;
				}
				
			}
			
			else if(word[i] == 'T' || word[i] == 't') // Find number of 'T' in the file
			{
				numT++;
				
				//Find Bigram
				if(word[i+1] == 'A' || word[i+1] == 'a')
				{
					numTA++;
					numA++;
				}
				
				else if(word[i+1] == 'C' || word[i+1] == 'c')
				{
					numTC++;
					numC++;
				}
				
				else if(word[i+1] == 'T' || word[i+1] == 't')
				{
					numTT++;
					numT++;
				}
				
				else if(word[i+1] == 'G' || word[i+1] == 'g')
				{
					numTG++;
					numG++;
				}
			}
			
			else if(word[i] == 'G' || word[i] == 'g') // Find number of 'G' in the file
			{
				numG++;
				
				//Find Bigram
				if(word[i+1] == 'A' || word[i+1] == 'a')
				{
					numGA++;
					numA++;
				}
				
				else if(word[i+1] == 'C' || word[i+1] == 'c')
				{
					numGC++;
					numC++;
				}
				
				else if(word[i+1] == 'T' || word[i+1] == 't')
				{
					numGT++;
					numT++;
				}
				
				else if(word[i+1] == 'G' || word[i+1] == 'g')
				{
					numGG++;
					numG++;
				}
			}
			++i;
			
		}
			
		++numStrings; //  Number of DNA strands
	}
	
	average = ((double)stringLength/numStrings); // average DNA strand
	
	variance = ((double)stringLengthSquared/numStrings); // caluculate variance
	
	stdDeviation = sqrt(variance); // calculate standard deviation 
	
	numBigram = stringLength/2; // Calculate number of bigram nucleotides.
	
	//probablity of single nucleotides
	probA = ((double)numA/stringLength)*100;
	probC = ((double)numC/stringLength)*100;
	probT = ((double)numT/stringLength)*100;
	probG = ((double)numG/stringLength)*100;
	
	//probably of bigram nucliotides
	probAA = ((double)numAA/numBigram)*100;
	probAC = ((double)numAC/numBigram)*100;
	probAG = ((double)numAG/numBigram)*100;
	probAT = ((double)numAT/numBigram)*100;
	probCA = ((double)numCA/numBigram)*100;
	probCC = ((double)numCC/numBigram)*100;
	probCT = ((double)numCT/numBigram)*100;
	probCG = ((double)numCG/numBigram)*100;
	probTA = ((double)numTA/numBigram)*100;
	probTC = ((double)numTC/numBigram)*100;
	probTT = ((double)numTT/numBigram)*100;
	probTG = ((double)numTG/numBigram)*100;
	probGA = ((double)numGA/numBigram)*100;
	probGC = ((double)numGC/numBigram)*100;
	probGT = ((double)numGT/numBigram)*100;
	probGG = ((double)numGG/numBigram)*100;
	readFile.close();    
	
	if(writeFile.is_open())
	{
		writeFile << "Characters: " << stringLength << endl << " Strings:" << numStrings << endl << " Average:" << average << endl << " Variance: " << variance << endl << " Standard Deviation: " << stdDeviation << endl;
		writeFile << endl;
		writeFile << "Number of 'A': " << numA << endl << " Number of 'C':"<< numC << endl << " Number of 'T':"<< numT << endl << " Number of 'G':"<< numG << endl;
		writeFile << endl;
		writeFile << "Number of \"AA\":" <<  numAA << endl << " Number of \"AC\":" <<  numAC << endl << " Number of \"AT\":" <<  numAT << endl << " Number of \"AG\":" <<  numAG << endl;
		writeFile << endl;
		writeFile << "Number of \"CA\":" <<  numCA << endl << " Number of \"CC\":" <<  numCC << endl << " Number of \"CT\":" <<  numCT << endl << " Number of \"CG\":" <<  numCG << endl;
		writeFile << endl;
		writeFile<< "Number of \"GA\":" <<  numGA << endl << " Number of \"GC\":" <<  numGC << endl << " Number of \"GT\":" <<  numGT << endl << " Number of \"GG\":" <<  numGG << endl;
		writeFile << endl;
		writeFile << "Number of \"TA\":" <<  numTA << endl << " Number of \"TC\":" <<  numTC << endl << " Number of \"TT\":" <<  numTT << endl << " Number of \"TG\":" <<  numTG << endl;
		writeFile << endl;
		writeFile << "Probablity of 'A':" << probA << "%" << endl << " Probablity of 'C':" << probC << "%" << endl << " Probablity of 'T':" << probT << "%" << endl <<" Probablity of 'G':" << probG << "%" <<endl;
		writeFile << endl;
		writeFile << "Probablilty of \"AA\":" << probAA << "%" << endl << " Probablilty of \"AC\":" << probAC << "%" << endl <<" Probablilty of \"AT\":" << probAT << "%" << endl <<" Probablilty of \"AG\":" << probAG << "%" << endl;
		writeFile << endl;
		writeFile << "Probablilty of \"CA\":" << probCA << "%" << endl << " Probablilty of \"CC\":" << probCC << "%" << endl <<" Probablilty of \"CT\":" << probCT << "%" << endl <<" Probablilty of \"CG\":" << probCG << "%" << endl;
		writeFile << endl;
		writeFile<< "Probablilty of \"TA\":" << probTA << "%" << endl << " Probablilty of \"TC\":" << probTC << "%" << endl <<" Probablilty of \"TT\":" << probTT << "%" << endl <<" Probablilty of \"TG\":" << probTG << "%" << endl;
		writeFile << endl;
		writeFile << "Probablilty of \"GA\":" << probGA << "%" << endl << " Probablilty of \"GC\":" << probGC << "%" << endl <<" Probablilty of \"GT\":" << probGT << "%" << endl <<" Probablilty of \"GG\":" << probGG << "%" << endl;
		writeFile << endl;
		writeFile << endl;
		
		for(int k = 0; k < 1000; ++k)
		{
			a = ((double) rand() / (RAND_MAX));
			b = ((double) rand() / (RAND_MAX));
			
			randLength = ((stdDeviation*(sqrt(-2*log10(a)) * cos(2*M_PI*b))) + variance) + .5;
		
			for (int l = 0; l < randLength; ++l)
			{
				randLetter = ((double) rand() / (RAND_MAX))*100;
				if(randLetter < probA)
				{
					writeFile << "A"; 
				}
				
				else if(randLetter < (probA + probC))
				{
					writeFile << "C"; 
				}
				
				else if(randLetter < (probA + probC + probT))
				{
					writeFile << "T"; 
				}
				
				else 
				{
					writeFile << "G"; 
				}
			}
			writeFile << endl;
			
		}
	}
	writeFile.close();
	cout << "Done! Would you like to read a different file? Press '0' for yes or 1 for 'no'." << endl;
	cin >> answer;
}
	cout << "Goodbye!!!!" << endl;
	return 0;
}