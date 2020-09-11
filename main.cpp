#include "game.h"
#include "human_player.h"
#include "ai_player.h"

int main() {
    HumanPlayer p1('x');
    AIPlayer p2('o');

    Game g(&p2, &p1);
    g.run();

}