/*
@Author Chhoden Gurung
@Assignment HW3 - Recursion
@Date 02/11/18
*/

#include "Maze.h"

using namespace std;

Maze::Maze(string fileName)
{
	try {
		readFile(fileName);
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

bool Maze::solve()
{
	if (move(1, 2)) {
		return true;
	}
	else
	{
		cout << "No exit !" << endl;
		return false;
	}
}

// Recursive move function to find the path to the exit
// from the given start point
bool Maze::move(int c, int r)
{
	if (isOutOfBound(c, r) || isWall(c, r) || isVisited(c, r)) {
		return false;
	}

	if (isExit(c, r)) {
		cout << "[" << c << "," << r << "]" << endl;
		return true;
	}

	markVisited(c, r);

	//move right
	if (move(c + 1, r)) {
		return true;
	}

	//move down
	if (move(c, r + 1)) {
		return true;
	}

	//move left
	if (move(c - 1, r)) {
		return true;
	}

	//move up
	if (move(c, r - 1)) {
		return true;
	}

	unMarkVisited(c, r);
	return false;
}

// Sets the instance variable from the given string
void Maze::setInstanceVariables(string s) throw (logic_error)
{	
	stringstream stream(s);

	// convert string to vector<int> and remove whitespace
	vector<int> values= vector<int>(
		istream_iterator<int>(stream),
		istream_iterator<int>()
	);

	if (values.size() != 4) throw logic_error("Invalid input! Please supply rows, columns, startColumn and start row.");

	//Assign instance variables
	rows = values.at(0);
	columns = values.at(1);
	startColumn = values.at(2);
	startRow = values.at(3);

	// check if start point is within bound
	if (isOutOfBound(startColumn, startRow)) {
		throw logic_error("Invalid start point!");
	}
}

// Takes in a filename and parses out the content to store it
// as an instance variables
int Maze::readFile(const string fileName) throw (logic_error)
{
	string line;
	ifstream myFile(fileName);

	if(myFile.is_open())
	{
		// Read the first line and set 
		// the instance variables
		getline(myFile, line);

		try{
			setInstanceVariables(line);
		}
		catch (exception e) {
			throw e;
		}

		// initialize maze 
		maze = new char*[rows];
		for (int i = 0; i < rows; i++) {
			maze[i] = new char[columns];
		}

		// build maze
		for (int r = 0; r < rows; r++) {
			// Read next line
			getline(myFile, line);
		
			// Store in columns
			for (int c = 0; c < columns; c++) {
				if (line.at(c) == '#' || line.at(c) == 'o' || line.at(c) == ' ') {
					maze[r][c] = line.at(c);
				}
				else {
					throw logic_error("Invalid character!");
				}
			}
		}

		myFile.close();
	}
	else
	{
		throw logic_error("Unable to open file");
	}
	return 0;
}

// Print the maze. Hides the unMarkVisited path.
void Maze::printMaze()
{
	cout << endl;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			// print unmarkvisited as ' '
			if (maze[r][c] == '-') {
				cout << ' ';
			}
			else 
			{
				cout << maze[r][c];
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool Maze::isOutOfBound(int c, int r)
{
	return((r < 0 || r >= rows) || (c < 0 || c >= columns));
}

bool Maze::isWall(int c, int r)
{
	return (maze[r][c] == '#');
}

bool Maze::isVisited(int c, int r)
{
	return (maze[r][c] == '+' || maze[r][c] == '-');
}

void Maze::markVisited(int c, int r)
{
	// print the path taken by adventurer
	cout << "[" << c << "," << r << "]->";
	maze[r][c] = '+';
}

void Maze::unMarkVisited(int c, int r)
{
	maze[r][c] = '-';
}

bool Maze::isExit(int c, int r)
{
	return maze[r][c] == 'o';
}
