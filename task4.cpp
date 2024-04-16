#include <iostream>

using namespace std;

void reverse(int arr[], int size) {
    int end = size;
    for (int i = 0; i <= size/2; ++i) {
        int tmp = arr[end];
        arr[end] = arr[i];
        arr[i] = tmp;
        end--;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[10] {1, 2, 3, 4, 5};

    reverse(arr, 4);

    print_array(arr, 5);

    return 0;
}