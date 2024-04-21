#include <iostream>
#include "Player.h"

using namespace std;


class HumanPlayer: public Player {

    int choseYourAction() override {
        int choice;
        std::cout << "Enter your move (1 - Rock, 2 - Paper, 3 - Scissors): ";
        std::cin >> choice;
        return choice;
    }

};