#include "game.h"
#include <iostream>

Game::Game(Player *p1, Player *p2) {
    player1 = p1, player2 = p2;
}

void Game::run() {

    bool p1 = true;
    bool running = true;
    while (running) {
        std::cout << std::endl;
        board.print();
        Player *currentPlayer = p1 ? player1 : player2;
        Move m = currentPlayer->getNextMove(&board);
        board.applyMove(&m);
        p1 = !p1;

        if (board.checkWin(&m)) {
            board.print();
             std::cout << "Player " << currentPlayer->getSymbol() << " wins" << std::endl;
             running = false;
        } else if (board.isDraw()) {
            board.print();
            std::cout << "The game is a draw" << std::endl;
            running = false;
        }

        //if (std::count(board.begin(), board.end(), '-') == 0) finished = true;
    }
}