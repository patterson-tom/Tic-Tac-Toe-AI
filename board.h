#pragma once

#include <vector>
#include "move.h"

class Board{

    std::vector<char> board;
    char winner;
    bool finished;

    void init();

    public:
        Board();
        
        void print();
        void applyMove(Move*);
        void trialMove(Move*);
        void undoMove(Move*);
        bool isMoveValid(Move*);
        bool checkWin(Move*);
        std::vector<char>* getBoard();     
        bool isFinished();
        char getWinner();   

};