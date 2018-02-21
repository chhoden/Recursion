/*
@Author Chhoden Gurung
@Assignment HW3 - Recursion
@Date 02/11/18
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

using namespace std;

class Maze{
public:
	Maze(string fileName);
	bool solve();
	void printMaze();

private:
	int columns;
	int rows;
	int startColumn;
	int startRow;
	char** maze;
	
	// Helper functions
	int readFile(const string fileName) throw (logic_error);
	bool move(int c, int r);
	void setInstanceVariables(string s) throw (logic_error);
	bool isOutOfBound(int c, int r);
	bool isWall(int c, int r);
	bool isVisited(int c, int r);
	void markVisited(int c, int r);
	void unMarkVisited(int c, int r);
	bool isExit(int c, int r);
};