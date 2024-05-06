#include <iostream>
#include <cstring>

using namespace std;

class Vector {
private:
    int* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    Vector() = default;

    explicit Vector(size_t capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
        memset(data, 0, sizeof(int) * capacity);
    }

    Vector(const Vector& other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new int[other.capacity];
        memcpy(this->data, other.data, sizeof(int) * other.size);
    }

    ~Vector() {
        delete[] data;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            this->capacity = other.capacity;
            this->size = other.size;
            this->data = new int[other.capacity];
            memcpy(this->data, other.data, sizeof(int) * other.size);
        }
        return *this;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    void push_back(const int& item) {
        if (size < capacity) {
            data[size++] = item;
        } else {
            cout << "Vector is full, cannot add more elements." << endl;
        }
    }

    [[nodiscard]] size_t getSize() const {
        return size;
    }
};

int main() {
    Vector v1;
    cout << "v1 size: " << v1.getSize() << endl;

    Vector v2(40);
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

    return 0;
}
