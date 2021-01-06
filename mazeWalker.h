/* -----------------------------------------------------------------------------
 *
 * File Name: mazeWalker.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 7
 * Description:  Maze walker lab
 * Date: 11/01/2020
 *
 ---------------------------------------------------------------------------- */
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <string> 
#include <fstream>
#include <iostream>

 class mazeWalker
 {
	private:
		char** m_maze;
		int** m_visited;
		int m_rows;
		int m_cols;
		int startRow;
		int startCol;
		int m_stepCount;
		bool m_isComplete;
		
		/**
		* @pre None
		* @post assigns step counter value to given cell
		* @param row number
		* @param column number
		* @throw None
		*/
		void mark(int row, int col);
		
		/**
		* @pre None
		* @post removes assigned step counter value in given cell
		* @param row number
		* @param column number
		* @throw None
		*/
		void unmark(int row, int col);
		
		/**
		* @pre None
		* @post returns true if move is valid and false if not
		* @param row number
		* @param column number
		* @throw None
		*/
		bool isValidMove(int row, int col);
		
		/**
		* @pre None
		* @post returns true if given cell is the exit, false otherwise
		* @param row number
		* @param column number
		* @throw None
		*/
		bool isExit(int row, int col);
		
		/**
		* @pre None
		* @post traverses maze recursively
		* @param row number
		* @param column number
		* @throw None
		*/
		bool recWalkMaze(int row, int col); //recursive
		
	public:
		
		/**
		* @pre None
		* @post maze walker is constructed
		* @param row number
		* @throw std::runtime error if array dimensions or starting position are invalid
		*/
		mazeWalker(std::string fileName);
		
		/**
		* @pre None
		* @post heap-allocated arrays are deleted
		* @param None
		* @throw None
		*/
		~mazeWalker();
		
		/**
		* @pre None
		* @post calls recursive maze walker
		* @param None
		* @throw None
		*/
		void walkMaze();
		
		/**
		* @pre None
		* @post Prints the solved maze
		* @param None
		* @throw None
		*/
		void printSolution();
 };
 #endif