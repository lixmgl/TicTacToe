
#ifndef __PLAYER_H_
#define __PLAYER_H_
#include <iostream>
#include <stdio.h>
#include "piece.h"
#include "tictactoe.h"

//This class represent each player.
class Player {
private:
	Type piece;
public:
	//default constructor
	Player() {
		piece = EMPTY;
	}

	//constructor can initialize a type for the player.
	Player(Type myPiece) {
		piece = myPiece;
	}
	void setType(Type t) {
		piece = t;
	}

	Type getType() {
		return piece;
	}

};

#endif