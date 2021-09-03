#include <iostream>
#include <map>
#include <string>
#include <unistd.h>

using namespace std;


// Compile and run with:
// g++ -std=c++11 ttt.cpp && ./a.out

int board[9] = { 0 };
int sums[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };

int winningCombos[8][3] = { 
	// rows
	{ 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	// columns
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	// diagonals
	{ 0, 4, 8 },
	{ 2, 4, 6 },
};

bool winnerDeclared = false;
int winner = 0;

map<int,string> m = {
    { 0, " " },
    { 1, "O" },
    { 2, "X" },
};


map<bool,string> mark = {
    { true, "O" },
    { false, "X" },
};

void printRow(int a, int b, int c) {
	cout << "  " << m[board[a]] << "  |  " << m[board[b]] << "  |  " << m[board[c]] << "\n";
}

void draw() {

	cout << "\033[2J\033[1;1H"; // clear the screen so the board is always drawn at the top of the terminal

    cout << "\n     |     |      \n";

	printRow(0, 1, 2);
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";

	printRow(3, 4, 5);
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
 
	printRow(6, 7, 8);

    cout << "     |     |      \n";

    cout << "\n";

}

int sumLine(int a, int b, int c, bool aF, bool bF, bool cF) {
	return sums[a]*aF + sums[b]*bF + sums[c]*cF;
}

int isWinningRow(int a, int b, int c) {
	return (sumLine(a, b, c, board[a], board[b], board[c]) == 15) && 
		((board[a] == board[b]) && (board[a] == board[c]));
}

int getWinner(int a, int b, int c) {
	if (isWinningRow(a, b, c)) {
		int sum = board[a] + board[b] + board[c];
		if (sum == 6) 
			return 2;
		else if (sum == 3)
			return 1;
	}
	return 0;
}

void printTurnInfo(int turn, int x) {
	cout << "Turn: " << turn << "\n";
	cout << "Player " << x << "'s turn\n";
}


int main () {

	draw();

	int position;
	int x = 0;
	int turn = 1;

	while (!winnerDeclared) {
		printTurnInfo(turn, x);

		int validPosition = false;

		std::cin >> position;

		validPosition = board[position] == 0;

		while (!validPosition) {
			cout << "Taken, choose another position.\n";
			std::cin >> position;
			validPosition = board[position] == 0;
		}
		
		board[position] = x + 1;

		draw();

		for (auto c : winningCombos) {
			winner = getWinner(c[0], c[1], c[2]);

			if (winner) 
				winnerDeclared = true;
		}

		x = 1 - x;

		turn++;

	}

	cout << "Player " << winner << " wins";
	cout << "\n\n";
}