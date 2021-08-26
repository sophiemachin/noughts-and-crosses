#include <iostream>
#include <map>
#include <string>

using namespace std;

int board[9] = { 0 };

map<int,string> m = {
    { 0, "_" },
    { 1, "O" },
    { 2, "X" },
};


void draw() {

 
    std::cout << "\n     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";

}



int main () {

	// draw();

	cout << m[1];
	cout << "\n\n";
}