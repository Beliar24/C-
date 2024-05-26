#include <vector>
#include <iostream>
#include "homework/VectorUtils.h"

using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5, 3};

    cout << "vec1 has duplicates: " << (hasDuplicates(vec1) ? "Yes" : "No") << endl;
    cout << "vec2 has duplicates: " << (hasDuplicates(vec2) ? "Yes" : "No") << endl;

    int numberToFind = 3;
    cout << "vec1 contains " << numberToFind << ": " << (containsNumber(vec1, numberToFind) ? "Yes" : "No") << endl;
    cout << "vec2 contains " << numberToFind << ": " << (containsNumber(vec2, numberToFind) ? "Yes" : "No") << endl;

    return 0;

}