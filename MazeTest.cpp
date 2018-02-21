/*
@Author Chhoden Gurung
@Assignment HW3 - Recursion
@Date 02/11/18
*/

#include <iostream>
#include "Maze.h"

using namespace std;
// Driver program
int main(int argc, char* argv[]) {

	if (argc < 2) {
		cout << "Missing filename!!" << endl;
		return 1;
	}

	Maze simpleMaze(argv[1]);

	simpleMaze.solve();
	simpleMaze.printMaze();

	return 0;
} 

