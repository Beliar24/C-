#include <iostream>
#include <vector>

using namespace std;


class Calculator {
private:
    double current = 0.0;
    vector<char> history;

public:
    static const char ADD = '+';
    static const char SUBTRACT = '-';
    static const char MULTIPLY = '*';
    static const char DIVIDE = '/';

    Calculator& calculate(const int &a, const char &s) {
        history.push_back(s);
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

    void calculate(const int &a, const int &b, const char &s) {
        history.clear();
        history.push_back(s);
        switch (s) {
            case SUBTRACT:
                current = a - b;
                break;
            case ADD:
                current = a + b;
                break;
            case MULTIPLY:
                current = a * b;
                break;
            case DIVIDE:
                if (a != 0) {
                    current = a / b;
                    break;
                } else {
                    cout << "a = 0, you can't divide";
                }
            default:
                cout << "Wrong operator";
        }
    }

    [[nodiscard]] double getResult() const {
        return current;
    }

    void refresh() {
        current = 0.0;
    }

    vector<char> getHistory() {
        return history;
    }

};


const char Calculator::ADD;
const char Calculator::SUBTRACT;
const char Calculator::MULTIPLY;
const char Calculator::DIVIDE;


int main() {

    Calculator calc;

    calc.calculate(5, Calculator::ADD).calculate(10, Calculator::ADD);

    cout << calc.getResult() << endl;

    for (char c : calc.getHistory()) {
        cout << c << endl;
    }

    calc.refresh();

    cout << calc.getResult() << endl;

    calc.calculate(5, 5, Calculator::MULTIPLY);

    cout << calc.getResult() << endl;

    for (char c : calc.getHistory()) {
        cout << c << endl;
    }

    return 0;
}