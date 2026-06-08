package Creational.Prototype.Solution;

public class GameClientWithPrototype {
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
        GameBoard copiedBoard = initialBoard.clone();

        copiedBoard.showBoardState();
  }
}
