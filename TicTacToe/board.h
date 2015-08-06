#ifndef __BOARD_H_
#define __BOARD_H_
#include <iostream>
#include <stdio.h>
#include "piece.h"

//This class represent the 2D matrix for tic tac toe, and manages the pieces.
class Board {
private:
	Piece** board;
	//This 2D char array is used for showing the board for users.
	char** view;
	int myRow = 0;
	int myCol = 0;
public:
	//constructor,initialize the board and view.
	Board(int row, int column) {
		myRow = row;
		myCol = column;
		board = new Piece*[row];
		view = new char*[row];
		for (int i = 0; i < row; i++) {
			board[i] = new Piece[column];
			view[i] = new char[column];
			for (int j = 0; j < column; j++) {
				view[i][j] = ' ';
			}
		}
	}

	//destructor
	~Board() {
		for (int i = 0; i < myRow; i++) {
			delete(board[i]);
			delete(view[i]);
		}
		delete(board);
		delete(view);
	}
	
	//check whether the position is valid before placing a actual piece.
	bool checkValid(int row, int col) {
		return (!(row < 0 || row >= myRow || col < 0 || col >= myCol || view[row][col] != ' '));
			
	}

	//if the piece is valid, player can change the piece using their type.
	bool setPiece(int row, int column, Type type) {
		if (!checkValid(row, column)) return false;
		board[row][column].setType(type);
		char c = type;
		
		switch (type)
		{
		case X:
			c = 'X';
			break;
		case O:
			c = 'O';
			break;
		case EMPTY:
			c = ' ';
			break;
		default:
			break;
		}
		
		view[row][column] = c;
		return true;
	}

	//used for output.
	char** getView() {
		return view;
	}
};
#endif
