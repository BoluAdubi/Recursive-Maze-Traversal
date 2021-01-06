/* -----------------------------------------------------------------------------
 *
 * File Name:  mazeWalker.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 7
 * Description:  Maze walker lab
 * Date: 11/01/2020
 *
 ---------------------------------------------------------------------------- */

#include "mazeWalker.h"

mazeWalker::mazeWalker(std::string fileName)
{
	m_stepCount = 1;
	m_isComplete = false;
	
	std::string file = fileName;
	
	std::ifstream myInFile;
	myInFile.open(file);
	
	myInFile >> m_rows;
	myInFile >> m_cols;
	myInFile >> startRow;
	myInFile >> startCol;
	
	if((m_rows  < 1) || (m_cols < 1))
	{
		throw(std::runtime_error("Invalid array dimensions"));
	}
	else
	{	
		// construct 2D array for maze
		m_maze = new char*[m_rows];
		
		for(int i = 0; i < m_rows; i++)
		{
			m_maze[i] = new char[m_cols];
		}

		// copy input file into 2D array
		for(int i = 0; i < m_rows; i++)
		{
			for(int j = 0; j < m_cols; j++)
			{
				myInFile >> m_maze[i][j];
			}
		}
		
		// construct 2D array for visited array
		m_visited = new int*[m_rows];
		
		for(int i = 0; i < m_rows; i++)
		{
			m_visited[i] = new int[m_cols];
		}
		
		// assign all cells in visited array to 0
		for(int i = 0; i < m_rows; i++)
		{
			for(int j = 0; j < m_cols; j++)
			{
				m_visited[i][j] = 0;
			}
		}
		// exception handling for start position
		if(m_maze[startRow][startCol] == 'W')
		{
			throw(std::runtime_error("Invalid start position"));
		}
	}
}

mazeWalker::~mazeWalker() // delete all heap-allocated arrays
{
	for(int i = 0; i < m_rows; i++)
	{
		delete m_maze[i];
		delete m_visited[i];
	}
	
	delete m_maze;
	delete m_visited;
}

void mazeWalker::mark(int row, int col)
{
	m_visited[row][col] = m_stepCount;
	m_stepCount++;
}

void mazeWalker::unmark(int row, int col)
{
	m_visited[row][col] = 0;
	m_stepCount--;
}

bool mazeWalker::isValidMove(int row, int col)
{
	if((row < m_rows) && (row >= 0) && (col < m_cols) && (col >= 0))
	{
		if((m_maze[row][col] == 'P' || m_maze[row][col] == 'E') && m_visited[row][col] == 0) 
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		return(false);
	}
}

bool mazeWalker::isExit(int row, int col)
{
	if(m_maze[row][col] == 'E')
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

bool mazeWalker::recWalkMaze(int row, int col)
{
	// mark cells as they're being visited
	mark(row, col);
	
	// base case
	if(isExit(row, col))
	{	
		m_isComplete = true;
		return(true);
	}
	
	// look up, right, down, left
	// up
	if(isValidMove(row-1, col))
	{
		// if moving up leads to an exit
		if(recWalkMaze(row-1, col))
		{
			m_isComplete = true;
			return(true);
		}
	}
	// right
	if(isValidMove(row, col+1))
	{
		// if moving right leads to an exit
		if(recWalkMaze(row, col+1))
		{
			return(true);
		}
	}
	// down
	if(isValidMove(row+1, col))
	{
		// if moving down leads to an exit
		if(recWalkMaze(row+1, col))
		{
			return(true);
		}
	}
	// left
	if(isValidMove(row, col-1))
	{
		// if moving left leads to an exit
		if(recWalkMaze(row, col-1))
		{
			return(true);
		}
	}
	
	// making it past all previous calls means they don't lead to an exit
	unmark(row, col);
	return(false);
}

void mazeWalker::walkMaze()
{
	recWalkMaze(startRow, startCol);
}

void mazeWalker::printSolution()
{
	if(m_isComplete)
	{
		std::cout << "Starting position: " << startRow << ", " << startCol << "\n";
		std::cout << "Size: " << m_rows << ", " << m_cols << "\n";
		for(int i = 0; i < m_rows; i++)
		{
			for(int j = 0; j < m_cols; j++)
			{
				std::cout << m_visited[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "We escaped!\n";
	}
	else
	{
		std::cout << "Starting position: " << startRow << ", " << startCol << "\n";
		std::cout << "Size: " << m_rows << ", " << m_cols << "\n";
		std::cout << "No way out!\n";
	}
}
