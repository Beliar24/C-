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
            if (a != 0) {
                return a / b;
            } else {
                cout << "a = 0, you can't divide";
                return 0;
            }
        default:
            cout << "Wrong operator";
    }
    return 0;
}

int main() {

    cout << calculate(0, 5, '/');

    return 0;
}