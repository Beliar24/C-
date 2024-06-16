#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Vector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    Vector() = default;

    explicit Vector(size_t capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new T[capacity];
        memset(data, 0, sizeof(T) * capacity);
    }

    [[maybe_unused]] Vector(size_t capacity, nothrow_t) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new (nothrow) T[capacity];
        if (this->data) {
            memset(data, 0, sizeof(T) * capacity);
        } else {
            this->capacity = 0;
        }
    }

    Vector(const Vector& other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new T[other.capacity];
        memcpy(this->data, other.data, sizeof(T) * other.size);
    }

    ~Vector() {
        delete[] data;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            this->capacity = other.capacity;
            this->size = other.size;
            this->data = new T[other.capacity];
            memcpy(this->data, other.data, sizeof(T) * other.size);
        }
        return *this;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    void push_back(const T& item) {
        if (size < capacity) {
            data[size++] = item;
        } else {
            cout << "Vector is full, cannot add more elements." << endl;
        }
    }

    [[nodiscard]] size_t getSize() const {
        return size;
    }

    void resize(size_t newSize, nothrow_t) {
        if (newSize <= capacity) {
            size = newSize;
            return;
        }

        T* newData = new (nothrow) T[newSize];
        if (!newData) {
            cout << "Failed to allocate memory." << endl;
            return;
        }

        memcpy(newData, data, sizeof(T) * size);
        delete[] data;

        data = newData;
        capacity = newSize;
        size = newSize;
    }
};

int main() {

    Vector<int> v1;
    cout << "v1 size: " << v1.getSize() << endl;

    Vector<double> v2(40);
    cout << "v2 size: " << v2.getSize() << endl;
    for (int i = 0; i < 50; ++i) {
        v2.push_back(i);
    }

    Vector<double> v3(v2);
    cout << "v3 size: " << v3.getSize() << endl;

    Vector<double> v4 = v2;
    cout << "v4 size: " << v4.getSize() << endl;

    for (size_t i = 0; i < v4.getSize(); ++i) {
        cout << v4[i] << " ";
    }
    cout << endl;

    cout << "Resizing v4 to 60 elements." << endl;
    v4.resize(60, std::nothrow);
    cout << "v4 size after resize: " << v4.getSize() << endl;


    return 0;
}

