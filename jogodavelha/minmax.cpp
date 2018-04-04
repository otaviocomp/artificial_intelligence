#include "minmax.h"
#include "board.h"
#include "globals.h"
#include <iostream>

Move Ai::Search(int player){
    switch(board.Evaluate(player)){
        case WIN:
            return WIN_SCORE;
        case LOSE:
            return -WIN_SCORE;
        case TIE:
            return TIE_SCORE;
    }
    Move bestMove;
    bestMove.score = -INF; //begin with a very low value
    for(int i = 0; i < 9; i++){
        if(board.GetSquare(i) == EMPTY){
            Move move;
            move.location = i;
            board.SetSquare(i, player);
            move.score = -Search(-player).score;
            board.UnsetSquare(i);
            // att the score
            if(move.score > bestMove.score)
                bestMove = move;
        }
    }
    return bestMove;
}
