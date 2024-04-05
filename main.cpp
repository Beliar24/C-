#include <iostream>

using namespace std;

size_t returnSize(int a) {
    return sizeof(a);
}

size_t returnSize(float a) {
    return sizeof(a);
}

size_t returnSize(bool a) {
    return sizeof(a);
}

size_t returnSize(const int *a) {
    return sizeof(a);
}


int main() {
    int n = 12;
    float f = 1.4;
    bool almost = true;
    int *a;

    cout << returnSize(n) << endl;
    cout << returnSize(f) << endl;
    cout << returnSize(almost) << endl;
    cout << returnSize(a) << endl;
    return 0;
}

