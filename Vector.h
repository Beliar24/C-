#ifndef VECTOR_H
#define VECTOR_H

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
};



#endif //VECTOR_H
