#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test constructor with size
        Array<int> intArray(5);
        std::cout << "intArray size: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

        // Modify and test copy constructor
        intArray[0] = 42;
        Array<int> copyArray(intArray);
        copyArray[1] = 99;

        std::cout << "Original array[0]: " << intArray[0] << std::endl;
        std::cout << "Copied array[0]: " << copyArray[0] << std::endl;
        std::cout << "Copied array[1]: " << copyArray[1] << std::endl;
        std::cout << "Original array[0]: " << intArray[1] << std::endl;

        // Test assignment operator
        Array<int> assignArray;
        assignArray = intArray;
        assignArray[2] = 123;
        std::cout << "Assigned array[2]: " << assignArray[2] << std::endl;
        std::cout << "Original array[2]: " << intArray[2] << std::endl;

        // Test exception on out-of-bounds
        std::cout << "Trying out-of-bounds access..." << std::endl;
        std::cout << intArray[10] << std::endl; // This should throw
    }
    catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
