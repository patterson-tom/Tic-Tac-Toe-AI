#pragma once

#include <vector>
#include "move.h"

class Board{

    std::vector<char> board;

    void init();

    public:
        Board();
        
        void print();
        void applyMove(Move*);
        void undoMove(Move*);
        bool isMoveValid(Move*);
        bool checkWin(Move*);
        bool isDraw();
        std::vector<char>* getBoard();

};