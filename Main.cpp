#include "homework/MyList.cpp"

int main() {
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.push_front(-1);

    std::cout << "List size: " << list.get_size() << std::endl;

    list.pop_back();
    list.pop_front();

    std::cout << "List size after pop operations: " << list.get_size() << std::endl;

    return 0;
}