1.Time:
I spent 3 hours to finish it. This game is  written in C++.

2.Assumption:
This is a n*n board played by two players.
Four cases are defined a win:
1)every piece in one row is placed by one player.
2)every piece in one column is placed by one player.
3)every piece in diagonal(top left to bottom right) is placed by one player.
4)every piece in the other diagonal(bottom left to top right) is placed by one player.

3.Classes:
1)player: define each player type (X or O).
2)piece: define each cell in the board.
3)board: define a 2D matrix for the game, each cell is a piece can be placed by player.
4)tictactoe: define the game.
5)test: run this class to test the game.

4.Test steps:
1)run ‘test.cpp’ file.
2)Player can input row and column numbers to select a place in the board to set the piece.
3)If the row and column is not inside this board or the piece is already placed, it will output cannot place here message.
4)After one player meets one of four winning cases, it will output a win message. Then the player can select to continue the game or stop.
