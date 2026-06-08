package Creational.Prototype.Solution;

import java.util.ArrayList;
import java.util.List;

public class GameBoard implements Prototype<GameBoard> {
    List<Piece> board = new ArrayList<>();

    void addPiece(Piece piece) {
        board.add(piece);
    }

    void showBoardState() {
        System.out.println("The board state is");
        for(Piece piece : board){
            System.out.println(piece);
        }
    }

    List<Piece> getBoardState() {
        return this.board;
    }


    @Override
    public GameBoard clone() {
        GameBoard newGameBoard = new GameBoard();
        for(Piece piece : this.board) {
            newGameBoard.addPiece(piece.clone());
        }
        return newGameBoard;
    }
}
