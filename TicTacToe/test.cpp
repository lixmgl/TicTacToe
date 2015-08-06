//A test class, which tests a 3*3 tic tac toe board played by two players.
//Will show the status of each piece is invalid if they input a wrong row or column.
//Will show the status of game, and the player can choose to continue to play or stop after each game.

#include "tictactoe.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

int readInt();
void printBoard(char** board, int row, int col);

int main(void) {
	int row = 0;
	int col = 0;
	TicTacToe* ttt;
	while (1) {
		ttt = new TicTacToe(3, 3);
		row = 0;
		col = 0;
		while (!ttt->checkWon()) {
			printBoard(ttt->getBoard(),3,3);
			std::cout << "Current Player: " << ttt->getCurrPlayer() << "\n";
			std::cout << "Please enter row: \n";
			row = readInt();
			std::cout << "Please enter column: \n";
			col = readInt();
			if (!ttt->setPiece(row, col)) {
				std::cout << "cannot place here. Please try again\n";
			}
		}
		std::cout << "Congratulations!!! \n";
		std::cout << ttt->getCurrPlayer() << " won \n";
		while (1) {
			std::cout << "Would you like try again? Yes/No\n";
			std::string str;
			getline(std::cin, str);
			if (str.compare("Yes")==0) {
				break;
			}
			if (str.compare("No")==0) {
				return EXIT_SUCCESS;
			}
			std::cout << "Invalid input. Please try again.\n";
		}
		delete(ttt);

	}
	
	
}

void printBoard(char** board, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') std::cout << "_";
			else std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}
int readInt() {
	std::string str;
	int result;
	while (1) {
		getline(std::cin,str);
		std::stringstream ss(str);
		if (ss >> result) {
			std::string left;
			getline(ss, left);
			if (left == "") {
				return result;
			}
		}
			
		std::cout << "Invalid input. Please type in a number\n";
		
		
	}
}