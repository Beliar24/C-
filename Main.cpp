#include "Vector.cpp"

int main() {
    Vector<int> v1;
    cout << "v1 size: " << v1.getSize() << endl;

    Vector<double> v2(40);
    cout << "v2 size: " << v2.getSize() << endl;
    for (int i = 0; i < 50; ++i) {
        v2.push_back(i);
    }

    Vector v3(v2);
    cout << "v3 size: " << v3.getSize() << endl;

    Vector v4 = v2;
    cout << "v4 size: " << v4.getSize() << endl;

    for (size_t i = 0; i < v4.getSize(); ++i) {
        cout << v4[i] << " ";
    }
    cout << endl;
}