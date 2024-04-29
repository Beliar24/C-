#include <iostream>

using namespace std;

class Player {
public:
    [[nodiscard]] virtual int choseYourAction() const  = 0;

};