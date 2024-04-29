#include <iostream>
#include "game/HumanPlayer.cpp"
#include "game/BotPlayer.cpp"
#include "game/Game.cpp"

using namespace std;

int main() {
    HumanPlayer player1;
    HumanPlayer player2;
    BotPlayer player3;

    Game *game = new Game(&player1, &player3);

    game -> play();

    Game *game2 = new Game(&player1, &player2);

    game2 -> play();

    delete game2;
    delete game;

    return 0;
}

