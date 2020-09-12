#include "board.h"
#include <iostream>
#include <algorithm>

Board::Board() {
    init();
}

void Board::init() {
    for (int i = 0; i < 9; i++) {
        board.push_back('-');
    }
}

void Board::print() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            std::cout << board.at(y*3+x) << ' ';
        }
        std::cout << std::endl;
    }
}

void Board::applyMove(Move *move) {

    unsigned int index = move->y * 3 + move->x;

    if (index > 9 || board.at(index) != '-') {
        return;
    }

    board.at(index) = move->player;

}

void Board::undoMove(Move *move) {
    unsigned int index = move->y * 3 + move->x;

    if (index > 9) {
        return;
    }

    board.at(index) = '-';
}

bool Board::isMoveValid(Move *m) {
    int index = m->y * 3 + m->x;

    if (index < 0 || index > 9) {
        return false;
    }

    return board.at(index) == '-';
}

bool Board::checkWin(Move *move) {

    //check horizontal wins
    bool winning = true;

    for (int x = 0; x < 3; x++) {
        if (board.at(move->y * 3 + x) != move->player) {
            winning = false;
            break;
        }
    }

    if (winning) return true;

    //check vertical wins
    winning = true;

    for (int y = 0; y < 3; y++) {
        if (board.at(y * 3 + move->x) != move->player) {
            winning = false;
            break;
        }
    }

    if (winning) return true;

    //check diagonal wins
    if (move->x == move->y) {

        winning = true;

        for (int i = 0; i < 3; i++) {
            if (board.at(4 * i) != move->player) {
                winning = false;
                break;
            }
        }

        if (winning) return true;
    }

    //check anti-diagonal wins
    if (2 - move->x == move->y) {

        winning = true;

        for (int i = 0; i < 3; i++) {
            if (board.at(2*i+2) != move->player) {
                winning = false;
                break;
            }
        }

        if (winning) return true;
    }

    //no wins found
    return false;
}

bool Board::isDraw() {
    return std::count(board.begin(), board.end(), '-') == 0;
}

std::vector<char>* Board::getBoard() {
    return &board;
}