#include <iostream>

using namespace std;


class Calculator {
private:
    double current = 0.0;

public:

    Calculator& calculate(const int &a, const char &s) {
        switch (s) {
            case SUBTRACT:
                 current -= a;
                break;
            case ADD:
                 current += a;
                break;
            case MULTIPLY:
                current *= a;
                break;
            case DIVIDE:
                if (a != 0) {
                    current /= a;
                } else {
                    cout << "a = 0, you can't divide";
                    return *this;
                }
            default:
                cout << "Wrong operator";
        }
        return *this;
    }

    [[nodiscard]] double getResult() const {
        return current;
    }

    void refresh() {
        current = 0.0;
    }

    static const char ADD = '+';
    static const char SUBTRACT = '-';
    static const char MULTIPLY = '*';
    static const char DIVIDE = '/';

};


int main() {

    Calculator calc;

    calc.calculate(5, Calculator::ADD).calculate(10, Calculator::ADD);

    cout << calc.getResult() << endl;

    calc.refresh();

    cout << calc.getResult() << endl;

    return 0;
}