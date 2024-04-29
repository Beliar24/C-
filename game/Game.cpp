#include <iostream>
#include "Player.h"

using namespace std;

class Game {

public:
    Game(Player* p1, Player* p2): player1(p1), player2(p2) {}

    void play() {
        int playerMove = player1 -> choseYourAction();
        int botMove = player2 -> choseYourAction();

        if (playerMove == 1 && botMove == 2) {
            cout << "The first player lose -> rock was covered by paper";
        } else if (playerMove == 1 && botMove == 3) {
            cout << "The first player win -> rock broke scissors";
        } else if (playerMove == 2 && botMove == 1) {
            cout << "The first player win -> paper cover rock";
        } else if (playerMove == 1 && botMove == 1 || playerMove == 2 && botMove == 2 || playerMove == 3 && botMove == 3) {
            cout << draw << endl;
        } else if (playerMove == 2 && botMove == 3) {
            cout << "The first player lose -> paper was cut by scissor";
        } else if (playerMove == 3 && botMove == 1) {
            cout << "The first player lose -> scissor was broken by rock";
        } else if (playerMove == 3 && botMove == 2) {
            cout << "The first player win -> scissor cut paper";
        }
    }

private:
    Player* player1;
    Player* player2;
    const char *draw = "Draw, try again";
};