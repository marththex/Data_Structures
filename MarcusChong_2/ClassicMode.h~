#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;
	
	int x, y, xLine, yLine;
	int newX, newY;
	int alive, numGens, mode,printTo, printOption;
	char c;
	double density;
	bool stable = false;
	ifstream readFile;
	string inFile = " ";	
	string line = " ";
	ofstream writeFile("MarcusChong.out");

	char ** grid;
	char ** newGrid;
	char choice;
	

double rand_0_1(void)
{
    return (double)rand()/RAND_MAX;
}

char randChar(double a){

	double randNum = rand_0_1();

	if(randNum > a)
		c = 'X';
	else if(randNum <= a)
		c = '-';

return c;	
}

int newCell(){

	int sum, cell;

	switch(sum){
		case (1):
			cell = 0;
		case (2):
		//	cell = oldGrid[newXLine][newYLine];
		case (3):
			cell = 1;
		case (4):
			cell = 0;
	}

return 0;
}

void readInfile(string textfile){

	readFile.open(textfile.c_str());
	readFile>> yLine;
	readFile >> xLine;

	for(y = 0; y < yLine; ++y){
		readFile >> line;
		for(x = 0; x < xLine; ++x){

			grid[x][y] = line[x];
			writeFile << grid[x][y];
		}
		writeFile << endl;
	}
	readFile.close(); 
}

bool isPopulated(int a, int b){

	if (grid[a][b] == 'X'){
		
		return true;}
	else {
		
		return false;}
}	

char isAlive(int m_alive, int x, int y)
{
	//cout << "isAlive:" << m_alive << endl;
	if(m_alive <= 1 || m_alive >=4)	
	{
		return '-';	
	}
	else if(m_alive == 2)
	{
		return grid[x][y];
	}
	else if(m_alive == 3)
	{
		return 'X';
	}
}

char posNonEdge(int a, int b)// for cells not touching any edge
{
	//cout << "posNonEdge works" << endl;
	
	if(isPopulated(a-1,b)== true)
	{
		alive++;
	}
		
	if(isPopulated(a-1,b-1)== true)
	{
		alive++;		
	}
		
	if(isPopulated(a,b-1)== true)
	{
		alive++;
	}

	if(isPopulated(a+1,b-1)== true)
	{
		alive++;
	}	
		
	if(isPopulated(a+1,b)== true)
	{
		alive++;
	}
		
	if(isPopulated(a+1,b+1)== true)
	{
		alive++;
	}
		
	if(isPopulated(a,b+1)== true)
	{
		alive++;
	}
		
	if(isPopulated(a-1,b+1)== true)
	{
		alive++;
	}
			
	return isAlive(alive, a, b);
}

char posClassic(int x, int y)// return 'X' or '-'
{
	alive = 0;
	//cout<<"position" << endl;
	if(xLine != 1 && yLine == 1) //1 row
	{
		if(x == 0)//left corner
		{
			if(isPopulated(x+1,y)== true)
			{
					alive++;
			}
			
			return isAlive(alive, x, y);
			
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else //others in the row
		{
			if(isPopulated(x+1,y)== true)
			{
					alive++;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
	}
	
	else if( xLine == 1 && yLine != 1) // 1 column
	{
		if(y == 0) //top corner
		{
			if(isPopulated(x,y+1)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y-1)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else //others in the column
		{
			if(isPopulated(x,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,y-1)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
	}
	
	else if(xLine ==1 && yLine ==1) // 1 cell
	{
		return '-';
	} 
	
	
	else //others
	{
		if(x == 0)//left side of grid
		{
			if(y ==0)//top left corner
			{
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
				
				if(isPopulated(x+1,y-1)== true)
				{
				alive++;
				}
				
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y-1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
		}
	
		else if(x == xLine-1)//right side of grid
		{
			if(y ==0) //top right corner of grid
			{
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
		
			if(isPopulated(x-1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
		
			if(isPopulated(x-1,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
	
		else //everything else
		{
			return posNonEdge(x,y);
		}
	}
}

char posDonut(int x, int y)// return 'X' or '-'
{
	alive = 0;
	
	if(xLine != 1 && yLine == 1) //1 row
	{
		if(x == 0)//left corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(xLine-1,y)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 3;
			}
				
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(0,y)== true)
			{
				alive = alive + 3;
			}
		}
		
		else //others in the row
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 3;
			}
		}
		
		return isAlive(alive, x, y);
	}
	
	else if( xLine == 1 && yLine != 1) // 1 column
	{
		if(y == 0) //top corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,yLine-1)== true)
			{
				alive = alive + 3;
			}
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y-1)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,0)== true)
			{
				alive = alive + 3;
			}
		}
		
		else //others in the column
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,y-1)== true)
			{
				alive = alive + 3;
			}
		}
		
		return isAlive(alive, x, y);
	}
	
	else if(xLine ==1 && yLine ==1) // 1 cell
	{
		return '-';
	} 
	
	
	else //2x2 or bigger
	{
		if(x == 0)//left side of grid
		{
			if(y ==0)//top left corner
			{
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,y)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,yLine-1)== true)
				{
					alive++;
				}
				if(isPopulated(x,yLine-1)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-2,yLine-1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
				
				if(isPopulated(x+1,y-1)== true)
				{
					alive++;
				}
				
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				
				if(isPopulated(x+1,0)== true)
				{
					alive++;
				}
				
				if(isPopulated(x,0)== true)
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,0)== true)
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,y)== true)
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,y-1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y-1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,y)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,y-1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		
		}
	
		else if(x == xLine-1)//right side of grid
		{
			if(y ==0) //top right corner of grid
			{
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(0,y)== true)
				{
					alive++;
				}
				if(isPopulated(0,yLine)== true)
				{
					alive++;
				}
				if(isPopulated(xLine-1,yLine-1)== true)
				{
					alive++;
				}
				if(isPopulated(x-1,yLine-1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
				
				if(isPopulated(x-1, 0)== true)
				{
					alive++;
				}
				
				if(isPopulated(x,0)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,0)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,y)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,yLine-2)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,y+1)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,y)== true)
				{
					alive++;
				}
				
				if(isPopulated(0,y-1)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
		
			if(isPopulated(x-1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,yLine-1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,yLine-1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x-1,yLine-1)== true)
			{
				alive++;
			}
			
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
		
			if(isPopulated(x-1,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,0)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,0)== true)
			{
				alive++;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
	
		else //everything else
		{
			return posNonEdge(x,y);
		}
	}
}

char posMirror(int x, int y)// return 'X' or '-'
{
	alive = 0;
	
	if(xLine != 1 && yLine == 1) //1 row
	{
		if(x == 0)//left corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 3;
			}
			
				
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x,y)== true)
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 3;
			}
		}
		
		else //others in the row
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 3;
			}
		}
		
		return isAlive(alive, x, y);
	}
	
	else if( xLine == 1 && yLine != 1) // 1 column
	{
		if(y == 0) //top corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive = alive + 3;
			}
			
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x,y-1)== true)
			{
				alive = alive + 3;
			}
			
		}
		
		else //others in the column
		{
			if(isPopulated(x,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,y-1)== true)
			{
				alive = alive + 3;
			}
		}
		
		return isAlive(alive, x, y);
	}
	
	else if(xLine ==1 && yLine ==1) // 1 cell
	{
		return '-';
	} 
	
	
	else //2x2 or bigger
	{
		if(x == 0)//left side of grid
		{
			if(y ==0)//top left corner
			{
				if(isPopulated(x+1,y)== true)
				{
					alive = alive + 2;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive = alive + 2;
				}
				if(isPopulated(x,y)== true)
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1)== true)
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x+1,y-1)== true)
				{
					alive++;
				}
				
				if(isPopulated(x+1,y)== true)
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y)== true)
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y)== true)
				{
					alive++;
				}
				if(isPopulated(x+1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y-1)== true)
				{
					alive = alive + 2;
				}
				if(isPopulated(x+1,y-1)== true)
				{
					alive++;
				}
				if(isPopulated(x,y+1)== true)
				{
					alive = alive + 2;
				}
				if(isPopulated(x,y)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		
		}
	
		else if(x == xLine-1)//right side of grid
		{
			if(y ==0) //top right corner of grid
			{
				if(isPopulated(x-1,y)== true)
				{
					alive + 2;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y)== true)
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1)== true)
				{
					alive = alive + 2;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y)== true)
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1)== true)
				{
					alive = alive + 2;
				}
			
				if(isPopulated(x-1,y-1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y)== true)
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1)== true)
				{
					alive++;
				}
			
				if(isPopulated(x,y+1)== true)
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y)== true)
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 2;
			}
		
			if(isPopulated(x-1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x,y+1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y)== true)
			{
				alive++;
			}
			
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y)== true)
			{
				alive = alive + 2;
			}
		
			if(isPopulated(x-1,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x,y-1)== true)
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1)== true)
			{
				alive++;
			}
			
			if(isPopulated(x+1,y)== true)
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y)== true)
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
	
		else //everything else
		{
			return posNonEdge(x,y);
		}
	}
}

int clearPrevGen()
{
for (int y = 0; y < yLine; y++){ 
	for (int x = 0; x < xLine; x++) { 

		grid[x][y] = newGrid[x][y];
	} 
}
return 0;
}

int nextGen(int type)
{
		cout << "Generation: " << numGens << endl;
		for (int y = 0; y < yLine; y++){ 
			for (int x = 0; x < xLine; x++) { 

				if(type == 1)
					newGrid[x][y] = posClassic(x,y);
				else if(type == 2)
					newGrid[x][y] = posDonut(x,y);
				else if(type == 3)
					newGrid[x][y] = posMirror(x,y);
				cout << newGrid[x][y]; 
			} 
			cout << endl; 
		}
		numGens++;
	return 0;
}

int nextGen2(int type)
{
		writeFile << "Generation: " << numGens << endl;
	
		for (int y = 0; y < yLine; y++){ 
			for (int x = 0; x < xLine; x++) { 

				if(type == 1)
					newGrid[x][y] = posClassic(x,y);
				else if(type == 2)
					newGrid[x][y] = posDonut(x,y);
				else if(type == 3)
					newGrid[x][y] = posMirror(x,y);
				writeFile << newGrid[x][y]; 
			} 
			writeFile << endl; 
		}
		numGens++;
	return 0;
}


int randClassic(){


	cout << "Enter an numeric value for the horizontal line: \n";
	cin >>  xLine;
	cout << "Enter an numeric value for the vertical line: \n";
	cin >>  yLine;
	cout << "Enter a decimal for the density: \n";
	cin >> density;
	cout << "What mode would you like?" << endl;
	cout << "Choose 1 for Classic" << endl;
	cout << "Choose 2 for Donut" << endl;
	cout << "Choose 3 for Mirror" << endl;
	cin >> mode;
	cout << "Would you like to print in the terminal or a text file?" << endl;
	cout << "Choose 1 for Terminal" << endl;
	cout << "Choose 2 for Textfile" << endl;
	cin >> printTo;
	if(printTo == 1)
	{
		cout << "Would you like the program to run or to give you an option to continue to the next Generation?" << endl;
		cout << "Choose 1 to let the program run" << endl;
		cout << "Choose 2 to give you an option to continue  to the next Generation" << endl;
		cin >> printOption;
	}
	grid = new char*[xLine];
	newGrid = new char*[xLine];
	
	
	if(printTo == 1)
	{
		cout <<"Generation: " << numGens << endl;
		numGens++;
		for(x = 0; x < xLine; ++x){
			grid[x] = new char[yLine];
			newGrid[x] = new char[yLine];
		}	

		for (int y = 0; y < yLine; y++){ 
			for (int x = 0; x < xLine; x++) { 

				grid[x][y] = randChar(density);
				cout << grid[x][y]; 
			} 
			cout << endl; 
		}
		
		if(printOption == 1)
		{
			
			do
			{
				if(mode == 1)
					nextGen(1);
				else if(mode == 2)
					nextGen(2);
				else if(mode == 3)
					nextGen(3);
				stable = true;
				for (int y = 0; y < yLine; y++){ 
					for (int x = 0; x < xLine; x++) { 
						if(grid[x][y] != newGrid[x][y])
						{
							stable = false;
						}
					} 
				}
				clearPrevGen();
			}while(stable != true);
			
		}
		else if (printOption == 2)
		{
			do{
				cout << "Would you like to view the next generation? [Y/N] \n";
	
				cin >> choice;

				if (choice == 'Y')
				{
					if(mode == 1)
						nextGen(1);
					else if(mode == 2)
						nextGen(2);
					else if(mode == 3)
						nextGen(3);
					clearPrevGen();
				}
				else if( choice == 'N')
					break;

			}while(choice != 'Y' || choice != 'N' );
		}
	}
	else if (printTo == 2)
	{
			writeFile <<"Generation: " << numGens << endl;
			numGens++;
			for(x = 0; x < xLine; ++x){
			grid[x] = new char[yLine];
			newGrid[x] = new char[yLine];
			}	

			for (int y = 0; y < yLine; y++){ 
				for (int x = 0; x < xLine; x++) { 

					grid[x][y] = randChar(density);
					writeFile << grid[x][y]; 
				} 
				writeFile << endl; 
			}
		
			do
			{
				if(mode == 1)
					nextGen2(1);
				else if(mode == 2)
					nextGen2(2);
				else if(mode == 3)
					nextGen2(3);
				stable = true;
				for (int y = 0; y < yLine; y++){ 
					for (int x = 0; x < xLine; x++) { 
						if(grid[x][y] != newGrid[x][y])
						{
							stable = false;
						}
					} 
				}
				clearPrevGen();
				
			}while(stable != true);
			writeFile.close();
		
	}
return 0;
}


int fileClassic(){

	cout << "Enter .txt file: \n";
	cin >> inFile;
	ifstream infile(inFile.c_str());

	readFile.open(inFile.c_str());
	readFile >> yLine;
	readFile >> xLine;
	readFile.close();  
	cout << "What mode would you like?" << endl;
	cout << "Choose 1 for Classic" << endl;
	cout << "Choose 2 for Donut" << endl;
	cout << "Choose 3 for Mirror" << endl;
	cin >> mode;
	cout << "Would you like to print in the terminal or a text file?" << endl;
	cout << "Choose 1 for Terminal" << endl;
	cout << "Choose 2 for Textfile" << endl;
	cin >> printTo;
	if(printTo == 1)
	{
		cout << "Would you like the program to run or to give you an option to continue to the next Generation?" << endl;
		cout << "Choose 1 to let the program run" << endl;
		cout << "Choose 2 to give you an option to continue  to the next Generation" << endl;
		cin >> printOption;
	}
	grid = new char*[xLine];
	newGrid = new char*[xLine];

	if(printTo == 1)
	{
		cout <<"Generation: " << numGens << endl;
		numGens++;
		for(x = 0; x < xLine; ++x){
			grid[x] = new char[yLine];
			newGrid[x] = new char[yLine];
		}	
		readInfile(inFile);
		
		if(printOption == 1)
		{
			
			do
			{
				if(mode == 1)
					nextGen(1);
				else if(mode == 2)
					nextGen(2);
				else if(mode == 3)
					nextGen(3);
				stable = true;
				for (int y = 0; y < yLine; y++){ 
					for (int x = 0; x < xLine; x++) { 
						if(grid[x][y] != newGrid[x][y])
						{
							stable = false;
						}
					} 
				}
				clearPrevGen();
			}while(stable != true);
			
		}
		else if (printOption == 2)
		{
			do{
				cout << "Would you like to view the next generation? [Y/N] \n";
	
				cin >> choice;

				if (choice == 'Y')
				{
					if(mode == 1)
						nextGen(1);
					else if(mode == 2)
						nextGen(2);
					else if(mode == 3)
						nextGen(3);
					clearPrevGen();
				}
				else if( choice == 'N')
					break;

			}while(choice != 'Y' || choice != 'N' );
		}
	}
	else if (printTo == 2)
	{
			writeFile <<"Generation: " << numGens << endl;
			numGens++;
			for(x = 0; x < xLine; ++x)
			{
			grid[x] = new char[yLine];
			newGrid[x] = new char[yLine];
			}	

			readInfile(inFile);
			
			cout << "Done!" << endl;
		
			do
			{
				if(mode == 1)
					nextGen2(1);
				else if(mode == 2)
					nextGen2(2);
				else if(mode == 3)
					nextGen2(3);
				stable = true;
				for (int y = 0; y < yLine; y++){ 
					for (int x = 0; x < xLine; x++) { 
						if(grid[x][y] != newGrid[x][y])
						{
							stable = false;
						}
					} 
				}
				clearPrevGen();
				
			}while(stable != true);
			writeFile.close();
		
	}
return 0;
}

// ACCESSED FROM MAIN
int classic(){

	int choice;
	cout << "--------------------------------------------" << endl;
	cout << "WELCOME TO THE GAME OF LIFE" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "OPTIONS: \n1. Input .txt file\n2. Randomized map\n\n";
	cin >> choice;
	switch (choice){
		case (1):
			fileClassic();
			break;
		case (2):
			randClassic();
			break;
	}

return 0;
}






