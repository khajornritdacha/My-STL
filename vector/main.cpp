#include <iostream>
#include "vector.h"

int main() {
    JO::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    std::cout << v1.size() << "\n";
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";
}
