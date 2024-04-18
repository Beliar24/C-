#include <iostream>

using namespace std;

class Calc {
private:
    double number = 0.0;

public:
     double getNumber() const {
        return number;
    }

    void clearNumber() {
         number = 0.0;
     }


    void calc(int a, int b, char s) {
        switch (s) {
            case '-':
                number =  a - b;
                break;
            case '+':
                number =  a + b;
                break;
            case '*':
                number =  a * b;
                break;
            case '/':
                if (a != 0) {
                    number = a / b;
                } else {
                    cout << "a = 0, you can't divide";
                }
                break;
            default:
                cout << "Wrong operator";
        }
    }

    void calculate(const double rightValue, const char operation) {
        switch (operation) {
            case '-':
                number -= rightValue;
                break;
            case '+':
                number += rightValue;
                break;
            case '*':
                number *= rightValue;
                break;
            case '/':
                if (rightValue != 0) {
                    number /= rightValue;
                } else {
                    cout << "a = 0, you can't divide";
                }
                break;
            default:
                cout << "Wrong operator";
        }
    }
};

int main() {
    Calc calculator;

    calculator.calc(5, 5, '+');

    cout << calculator.getNumber() << endl;

    calculator.calculate(4.6, '*');

    cout << calculator.getNumber() << endl;

    calculator.clearNumber();

    cout << calculator.getNumber();
    return 0;
}

