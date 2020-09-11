#pragma once

#include "player.h"
#include "move.h"
#include "board.h"

class HumanPlayer : public Player {
    
    public:
        HumanPlayer(char);
        Move getNextMove(Board*);
};