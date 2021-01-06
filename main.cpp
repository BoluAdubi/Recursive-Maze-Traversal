/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 7
 * Description:  Maze walker lab
 * Date: 11/01/2020
 *
 ---------------------------------------------------------------------------- */

#include <iostream>
#include "mazeWalker.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Incorrect number of parameters!\n";
	}
	else
	{
		std::string string = argv[1];
		try
		{
			mazeWalker myWalker(string);
			myWalker.walkMaze();
			myWalker.printSolution();
		}
		catch(std::runtime_error& rte)
		{
			std::cout << rte.what() << "\n";
		}
	}
	
	return(0);
}