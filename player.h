#pragma once

#include "board.h"
#include "move.h"

class Player {

    protected:
        char symbol;
    
    public:
        virtual Move getNextMove(Board*) = 0;
        char getSymbol();
};