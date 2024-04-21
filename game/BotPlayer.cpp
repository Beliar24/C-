#include <iostream>
#include <random>
#include "Player.h"

using namespace std;

class BotPlayer: public Player {

    int choseYourAction() override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 3);

        return dis(gen);
    }
};