#ifndef __TICTACTOE_H_
#define __TICTACTOE_H_
#include <iostream>
#include "player.h"
#include "piece.h"
#include "board.h"

//This is the game class, and will be initialized directly in test.cpp file.
class TicTacToe{ 
private:
	Player* players;
	Board* board;
	int PLAYERNUM = 2;
	int rows = 0;
	int columns= 0;
	int currPlayer = 0;

public:
	//constructor
	TicTacToe(int r, int c) {
		rows = r;
		columns = c;
		board = new Board(rows, columns);
		players = new Player[PLAYERNUM];
		//set types for two players, and current player is the first one with X.
		players[0].setType(X);
		players[1].setType(O);
		currPlayer = 0;
	}

	//Used for output the whole board
	char** getBoard() {
		return board->getView();
	}

	//This class will return '1' or '2' to repesent the first and second player.
	char getCurrPlayer() {
		return '1'+currPlayer;
	}

	//destructor
	~TicTacToe() {
		delete(board);
		//delete(players[0]);
		//delete(players[1]);
		delete(players);
	}

	/*Four cases are defined a win: 
	 * 1)every piece in one row is placed by the same player.
	 * 2)every piece in one column is placed by the same player.
	 * 3)every piece in one diagnal(top left to bottom right) is placed by the same player.
	 * 4)every piece in another diagnal(bottom left to top right) is placed by the same player.	
	*/
	bool checkWon() {
		int r = 0;
		int c = 0;
		char ** view = board->getView();
		for (r = 0; r < rows; r++) {
			if (view[r][0] != ' ') {
				for (c = 1; c < columns; c++) {
					if (view[r][c] != view[r][c - 1]) break;
				}
				if (c == columns) return true;
			}
		}

		for (c = 0; c < rows; c++) {
			if (view[0][c] != ' ') {
				for (r = 1; r < rows; r++) {
					if (view[r][c] != view[r - 1][c]) break;
				}
				if (r == rows) return true;
			}
		}

		if (view[0][0] != ' ') {
			for (r = 1; r < rows; r++) {
				if (view[r][r] != view[r - 1][r - 1]) break;
			}
			if (r == rows) return true;
		}

		if (view[rows - 1][0] != ' ') {
			for (r = 1; r < rows; r++) {
				if (view[rows - r - 1][r] != view[rows - r][r - 1]) break;
			}
			if (r == rows) return true;
		}
		return false;
	}


	bool setPiece(int r, int c) {
		if (board->setPiece(r, c, players[currPlayer].getType())) {
			if (checkWon()) return true;
			changeTurn();
			return true;
		}
		return false;
	}

	//change to the other player after one player is placed.
	void changeTurn() {
		if (currPlayer < PLAYERNUM-1) {
			currPlayer++;
		}
		else {
			currPlayer = 0;
		}
	}
};

#endif
