
#ifndef __PIECE_H_
#define __PIECE_H_
#include <iostream>
#include <stdio.h>

//Three types for every piece. X and O represent players.
enum Type {X,O,EMPTY};

//This class represent every single cell in Board. Every cell can be X, O  or EMPTY.
class Piece {
private:
	Type type = EMPTY;
public:
	//default constructor
	Piece() {type = EMPTY;}

	//constructor can initialize one of three types.
	Piece(Type myType) { type = myType; }

	Type getType() {
		return type;
	}
	void setType(Type t) {
		type = t;
	}
};
#endif