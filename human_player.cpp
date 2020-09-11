#include "human_player.h"
#include <iostream>

HumanPlayer::HumanPlayer(char symbol) {
    this->symbol = symbol;
}

Move HumanPlayer::getNextMove(Board *board) {
    bool validMove = false;
    Move m;

    while (!validMove) {
        std::cout << "Player " << symbol << ", enter your move:" << std::endl;
        unsigned int code;
        std::cin >> code;
        code--;
        m = {code % 3, code / 3, symbol};
        validMove = board->isMoveValid(&m);
        if (!validMove) {
            std::cout << "Invalid move, try again" << std::endl;
        }
    }
    
    return m;
}