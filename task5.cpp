#include <iostream>

using namespace std;

int calculate(int a, int b, char s) {
    switch (s) {
        case '-':
            return a - b;
        case '+':
            return a + b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            cout << "Wrong operator";
    }
    return 1;
}

int main() {

    cout << calculate(10, 5, '+');

    return 0;
}