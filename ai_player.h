#pragma once

#include "player.h"
#include "board.h"
#include <vector>

class AIPlayer : public Player{

    int negamax(Board*, int, int, char, int);
    std::vector<Move> getValidMoves(std::vector<char>*, char);

    public:
        AIPlayer(char);
        Move getNextMove(Board*);
};