#include <iostream>
#include <map>
#include <string>
#include <unistd.h>

using namespace std;


// Compile and run with:
// g++ -std=c++11 ttt.cpp && ./a.out

int board[9] = { 0 };

bool winnerDeclared = false;

map<int,string> m = {
    { 0, " " },
    { 1, "O" },
    { 2, "X" },
};


map<bool,string> mark = {
    { true, "O" },
    { false, "X" },
};

void draw() {

    cout << "\n     |     |      \n";

    cout << "  " << m[board[0]] << "  |  " << m[board[1]] << "  |  " << m[board[2]] << "\n";
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
 
    cout << "  " << m[board[3]] << "  |  " << m[board[4]] << "  |  " << m[board[5]] << "\n";
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
 
    cout << "  " << m[board[6]] << "  |  " << m[board[7]] << "  |  " << m[board[8]] << "\n";
    cout << "     |     |      \n";
 
    cout << "\n";

}


int main () {

	draw();

	int position;
	int x = 1;

	// bool playerOneTurn = true;

	// cout << m[0];

	while (!winnerDeclared) {

		// cout << "Player " << x << " enter a position: \n";
		std::cin >> position;
		// cout << "You have entered: " << position <<  "\n\n";

		cout << "x: " << x;
		cout << "\n";
		// cout << mark[playerOneTurn];
		cout << "\n\n\n";

		board[position] = x + 1;

		draw();

		// playerOneTurn = !playerOneTurn;
		x = 1 - x;

	}

	// cout << argc;
	// cout << m[1];
	cout << "\n\n";
}