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

	cout << "\033[2J\033[1;1H"; // clear the screen so the board is always drawn at the top of the terminal

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

bool isWinner() {
	return (board[0] == board[3] == board[6] && board[0]);
}


int main () {

	draw();

	int position;
	int x = 1;

	while (!winnerDeclared) {

		cout << "Player " << x << "'s turn\n";

		int validPosition = false;

		std::cin >> position;

		validPosition = board[position] == 0;

		while (!validPosition) {
			cout << "Taken, choose another position.\n";
			std::cin >> position;
			validPosition = board[position] == 0;
		}
		
		board[position] = x + 1;

		cout << isWinner();

		draw();

		cout << "isWinner: " << isWinner();

		x = 1 - x;

	}

	cout << "\n\n";
}