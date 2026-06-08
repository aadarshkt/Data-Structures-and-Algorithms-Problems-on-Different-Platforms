package Creational.Prototype.Problem;

import java.util.ArrayList;
import java.util.List;

public class GameBoard implements Cloneable {
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
}
