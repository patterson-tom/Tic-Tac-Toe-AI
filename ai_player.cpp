#include "ai_player.h"
#include <limits.h>
#include <algorithm>
#include <iostream>

AIPlayer::AIPlayer(char symbol) {
    this->symbol = symbol;
}

int AIPlayer::negamax(Board *board, int alpha, int beta, char player, int depth) {

    std::vector<Move> validMoves = getValidMoves(board->getBoard(), player);

    if (validMoves.size() == 0) return 0;

    int value = INT_MIN;
    for (auto &move : validMoves) {

        board->applyMove(&move);

        if (board->checkWin(&move)) {
            value = INT_MAX - depth;
        } else {
            value = std::max(value, -negamax(board, -beta, -alpha, player == 'x' ? 'o' : 'x', depth+1));
        }
        
        board->undoMove(&move);

        alpha = std::max(alpha, value);
        if (alpha >= beta) {
            break;
        }
       
    }

    return value;
}

std::vector<Move> AIPlayer::getValidMoves(std::vector<char> *board, char player) {
    std::vector<Move> validMoves;

    for (unsigned int y = 0; y < 3; y++) {
        for (unsigned int x = 0; x < 3; x++) {

            if (board->at(y * 3 + x) != '-') {
                continue;
            }

            validMoves.push_back({x, y, player});
        }
    }

    return validMoves;
}

Move AIPlayer::getNextMove(Board *board) {
    std::vector<Move> validMoves = getValidMoves(board->getBoard(), symbol);
    std::vector<int> scores;
    for (auto &move : validMoves) {
        board->applyMove(&move);
        if (board->checkWin(&move)){
            scores.push_back(INT_MAX);
            board->undoMove(&move);
            break;
        }
        int val = -negamax(board, INT_MIN+1, INT_MAX, symbol == 'o' ? 'x' : 'o', 0);
        scores.push_back(val);
        board->undoMove(&move);
    }
    int index = std::distance(scores.begin(), std::max_element(scores.begin(), scores.end()));
    return validMoves.at(index);
}
