#include "game.h"
#include <iostream>

Game::Game(Player *p1, Player *p2) {
    player1 = p1, player2 = p2;
}

void Game::run() {

    bool p1 = true;
    while (!board.isFinished()) {
        std::cout << std::endl;
        board.print();
        Player *currentPlayer = p1 ? player1 : player2;
        Move m = currentPlayer->getNextMove(&board);
        board.applyMove(&m);
        p1 = !p1;
    }

    board.print();
    char winner = board.getWinner();
    if (winner == '-'){
        std::cout << "The game is a draw" << std::endl;
    } else {
        std::cout << "Player " << winner << " wins" << std::endl;
    }
}