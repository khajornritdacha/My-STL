#include <iostream>
#include "vector.h"

template<typename T>
void print(JO::Vector<T> const &vec) {
    std::cout << vec.size() << "\n";
    for (size_t i = 0; i < vec.size(); i++) {
        std:: cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    JO::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    print(v1);

    JO::Vector<int> v2;
    v2 = v1;

    v2[3] = 10;
    print(v2);

    // JO::Vector<int> v3(5, 1);
    // print(v3);

    // JO::Vector<int> v4(7);
    // std::cout << v4.size() << "\n";
    // print(v4);
}
