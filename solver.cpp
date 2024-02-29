#include <iostream> 
#include "support.h"
#define N 9
using namespace std;

int main(int argc, char **argv){

	int game[N][N] = { { 0, 9, 7, 0, 0, 0, 4, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
                       { 5, 4, 6, 0, 0, 1, 7, 0, 0 },

                       { 0, 0, 9, 0, 0, 0, 0, 0, 5 },
                       { 2, 0, 0, 0, 9, 8, 0, 0, 7 },
                       { 0, 3, 0, 0, 0, 0, 1, 0, 0 },

                       { 6, 0, 0, 0, 4, 0, 0, 1, 0 },
                       { 0, 0, 8, 5, 3, 0, 0, 2, 0 },
                       { 0, 0, 0, 6, 0, 0, 0, 0, 0 } };

	cout << "Initial Puzzle:" << endl << endl;
	Sudoku sudo;
	sudo.print(game);

	cout << endl;
	cout << "Computing..." << endl;
	cout << endl;

	if(sudo.solver(game)){
	    cout << "Solution Found: " << endl << endl;
		sudo.print(game);
	}else
		cerr << "There is no solution to the given puzzle." << endl;
}

