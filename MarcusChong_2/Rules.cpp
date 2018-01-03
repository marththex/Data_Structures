#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include "Game.h"

using namespace std;
int xLine, yLine, alive = 0; 
string fileName;
char** grid;


int Rules(int m_xlines, int m_ylines, string m_fileName)
{
	xLine = m_xlines;
	yLine = m_ylines;
	fileName = m_fileName;
	
	
}

int Rules(char** m_grid)
{
	grid = m_grid;
}

char isAlive(int m_alive, int x, int y)
{
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
	if(isPopulated(a-1,b))
	{
		alive++;
	}
		
	if(isPopulated(a-1,b-1))
	{
		alive++;		
	}
		
	if(isPopulated(a,b-1))
	{
		alive++;
	}

	if(isPopulated(a+1,b-1))
	{
		alive++;
	}	
		
	if(isPopulated(a+1,b))
	{
		alive++;
	}
		
	if(isPopulated(a+1,b+1))
	{
		alive++;
	}
		
	if(isPopulated(a,b+1))
	{
		alive++;
	}
		
	if(isPopulated(a-1,b+1))
	{
		alive++;
	}
			
	return isAlive(alive, a, b);
}

char posClassic(int x, int y)// return 'X' or '-'
{
	alive = 0;
	
	if(xLine != 1 && yLine == 1) //1 row
	{
		if(x == 0)//left corner
		{
			if(isPopulated(x+1,y))
			{
					alive++;
			}
			
			return isAlive(alive, x, y);
			
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x-1,y))
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else //others in the row
		{
			if(isPopulated(x+1,y))
			{
					alive++;
			}
			
			if(isPopulated(x-1,y))
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
			if(isPopulated(x,y+1))
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y-1))
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		}
		
		else //others in the column
		{
			if(isPopulated(x,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x,y-1))
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
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
				
				if(isPopulated(x+1,y-1))
				{
				alive++;
				}
				
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y-1))
				{
					alive++;
				}
				if(isPopulated(x+1,y-1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
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
				if(isPopulated(x-1,y))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive++;
			}
		
			if(isPopulated(x-1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x,y+1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
			{
				alive++;
			}
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive++;
			}
		
			if(isPopulated(x-1,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
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
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(xLine-1,y))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 3;
			}
				
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x-1,y))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(0,y))
			{
				alive = alive + 3;
			}
		}
		
		else //others in the row
		{
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x-1,y))
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
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,yLine-1))
			{
				alive = alive + 3;
			}
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y-1))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,0))
			{
				alive = alive + 3;
			}
		}
		
		else //others in the column
		{
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,y-1))
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
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				if(isPopulated(xLine-1,y+1))
				{
					alive++;
				}
				if(isPopulated(xLine-1,y))
				{
					alive++;
				}
				if(isPopulated(xLine-1,yLine-1))
				{
					alive++;
				}
				if(isPopulated(x,yLine-1))
				{
					alive++;
				}
				if(isPopulated(xLine-2,yLine-1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
				
				if(isPopulated(x+1,y-1))
				{
					alive++;
				}
				
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				
				if(isPopulated(x+1,0))
				{
					alive++;
				}
				
				if(isPopulated(x,0))
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,0))
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,y))
				{
					alive++;
				}
				
				if(isPopulated(xLine-1,y-1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y-1))
				{
					alive++;
				}
				if(isPopulated(x+1,y-1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				if(isPopulated(xLine-1,y+1))
				{
					alive++;
				}
				if(isPopulated(xLine-1,y))
				{
					alive++;
				}
				if(isPopulated(xLine-1,y-1))
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
				if(isPopulated(x-1,y))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				
				if(isPopulated(0,y+1))
				{
					alive++;
				}
				if(isPopulated(0,y))
				{
					alive++;
				}
				if(isPopulated(0,yLine))
				{
					alive++;
				}
				if(isPopulated(xLine-1,yLine-1))
				{
					alive++;
				}
				if(isPopulated(x-1,yLine-1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive++;
				}
				
				if(isPopulated(x-1, 0))
				{
					alive++;
				}
				
				if(isPopulated(x,0))
				{
					alive++;
				}
				
				if(isPopulated(0,0))
				{
					alive++;
				}
				
				if(isPopulated(0,y))
				{
					alive++;
				}
				
				if(isPopulated(0,yLine-2))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive++;
				}
				
				if(isPopulated(0,y+1))
				{
					alive++;
				}
				
				if(isPopulated(0,y))
				{
					alive++;
				}
				
				if(isPopulated(0,y-1))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive++;
			}
		
			if(isPopulated(x-1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x,y+1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
			{
				alive++;
			}
			
			if(isPopulated(x+1,yLine-1))
			{
				alive++;
			}
			
			if(isPopulated(x,yLine-1))
			{
				alive++;
			}
			
			if(isPopulated(x-1,yLine-1))
			{
				alive++;
			}
			
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive++;
			}
		
			if(isPopulated(x-1,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
			{
				alive++;
			}
			
			if(isPopulated(x+1,0))
			{
				alive++;
			}
			
			if(isPopulated(x,0))
			{
				alive++;
			}
			
			if(isPopulated(x-1,y))
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
			if(isPopulated(x,y))
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 3;
			}
			
				
		}
		
		else if(x == xLine-1)//right corner
		{
		
			if(isPopulated(x,y))
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x-1,y))
			{
				alive = alive + 3;
			}
		}
		
		else //others in the row
		{
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x-1,y))
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
			if(isPopulated(x,y))
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x,y+1))
			{
				alive = alive + 3;
			}
			
		}
		
		else if (y == yLine-1) //bottom corner
		{
			if(isPopulated(x,y))
			{
				alive = alive + 5;
			}
			
			if(isPopulated(x,y-1))
			{
				alive = alive + 3;
			}
			
		}
		
		else //others in the column
		{
			if(isPopulated(x,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y+1))
			{
				alive = alive + 3;
			}
			
			if(isPopulated(x,y-1))
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
				if(isPopulated(x+1,y))
				{
					alive = alive + 2;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
				{
					alive = alive + 2;
				}
				if(isPopulated(x,y))
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else if(y==yLine-1)//bottom left corner
			{
				if(isPopulated(x,y-1))
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x+1,y-1))
				{
					alive++;
				}
				
				if(isPopulated(x+1,y))
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y))
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
				
			}
		
			else // noncorner leftside
			{
				if(isPopulated(x+1,y))
				{
					alive++;
				}
				if(isPopulated(x+1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y-1))
				{
					alive = alive + 2;
				}
				if(isPopulated(x+1,y-1))
				{
					alive++;
				}
				if(isPopulated(x,y+1))
				{
					alive = alive + 2;
				}
				if(isPopulated(x,y))
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
				if(isPopulated(x-1,y))
				{
					alive + 2;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y))
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else if(y==yLine-1) //bottom right corner of grid
			{
				if(isPopulated(x,y-1))
				{
					alive = alive + 2;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y))
				{
					alive = alive + 3;
				}
				
				return isAlive(alive, x, y);
		
			}
		
			else//everything else right side
			{
				if(isPopulated(x,y-1))
				{
					alive = alive + 2;
				}
			
				if(isPopulated(x-1,y-1))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y))
				{
					alive++;
				}
			
				if(isPopulated(x-1,y+1))
				{
					alive++;
				}
			
				if(isPopulated(x,y+1))
				{
					alive = alive + 2;
				}
				
				if(isPopulated(x,y))
				{
					alive++;
				}
				
				return isAlive(alive, x, y);
			}
		}
	
	
		else if(y == 0)//top side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive = alive + 2;
			}
		
			if(isPopulated(x-1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x,y+1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y+1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y))
			{
				alive++;
			}
			
			
			return isAlive(alive, x, y);
		
		}
	
		else if(y == yLine-1) // bot side of grid
		{
			if(isPopulated(x-1,y))
			{
				alive = alive + 2;
			}
		
			if(isPopulated(x-1,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x,y-1))
			{
				alive++;
			}
		
			if(isPopulated(x+1,y-1))
			{
				alive++;
			}
			
			if(isPopulated(x+1,y))
			{
				alive = alive + 2;
			}
			
			if(isPopulated(x,y))
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


