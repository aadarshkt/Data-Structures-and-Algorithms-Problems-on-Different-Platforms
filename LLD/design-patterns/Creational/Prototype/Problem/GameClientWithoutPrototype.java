package Creational.Prototype.Problem;

public class GameClientWithoutPrototype {
    public static void main(String[] args){
        GameBoard initialBoard = new GameBoard();
        initialBoard.addPiece(new Piece("Red", 5));
        initialBoard.addPiece(new Piece("Blue", 10));

        initialBoard.showBoardState();

        //Copying logic should not be in the client.
        //Easy to make mistakes.
        //Tight coupling with copying logic, copying logic should be handled by the
        //individual class.

        //Copying without a prototype pattern
        GameBoard copiedBoard = new GameBoard();
        for(Piece piece : initialBoard.getBoardState()) {
            //created deep copy of a new piece instead of using .addPiece(piece)
            copiedBoard.addPiece(new Piece(piece.getColor(), piece.getPosition()));
        }

        copiedBoard.showBoardState();
  }
}
