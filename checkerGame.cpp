//http://stackoverflow.com/questions/12866114/logic-behind-making-a-checkers-game
By using OOP principles I would go with something like:

enum Side {
  BLACK,
  RED;
}

class Position {
  int x, int y;
}

class Piece
{
  Position position; // position inside the board
  Side side; // which side the piece is
}

class Board
{
  Piece[][] board = new Piece[8][8];

  boolean isMoveLegal(Piece p, Position newPosition) {
    ...
  }

  void doMove(Piece p, Position newPosition) {
    if (isMoveLegal(p, newPosition) {
      // game logic of movement and eating other pieces if needed
    }
  }
}
A more naive approach could use a simple map:

class Position {
  int x, int y;
}

class Piece
{
  Side side; // which side the piece is
}

class Board
{
  HashMap<Piece, Position> board;

  boolean isMoveLegal(Piece p, Position newPosition) {
    ...
  }

  void doMove(Piece p, Position newPosition) {
    if (isMoveLegal(p, newPosition) {
      // game logic of movement and eating other pieces if needed
    }
  }
}
