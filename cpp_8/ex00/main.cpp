#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        for (int i = 1; i <= 5; ++i)
            vec.push_back(i * 10);  // 10, 20, 30, 40, 50

        std::vector<int>::const_iterator itVec = easyfind(vec, 30);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::list<int>::const_iterator itList = easyfind(lst, 15);
        std::cout << "Found in list: " << *itList << std::endl;

        easyfind(vec, 99);

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
