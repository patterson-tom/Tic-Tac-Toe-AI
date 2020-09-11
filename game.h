#pragma once

#include "board.h"
#include "player.h"

class Game {
    Board board;
    Player *player1, *player2;

    public:
        Game(Player*, Player*);
        void run();
};