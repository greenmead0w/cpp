#include <iostream>
#include "Data.h"
#include "Serializer.h"

int main() {
    Data original;

    std::cout << "Original Data:\n";
    std::cout << "ID: " << original.id << "\n";
    std::cout << "Name: " << original.name << "\n";
    std::cout << "Address: " << &original << "\n";
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value (uintptr_t): " << raw << "\n";
    std::cout << "------------------------------\n";

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored Data:\n";
    std::cout << "ID: " << restored->id << "\n";
    std::cout << "Name: " << restored->name << "\n";
    std::cout << "Address: " << restored << "\n";

    if (restored == &original) {
        std::cout << "\n--------Pointers match--------\n\n";
    } else {
        std::cout << "\n--------Pointers do not match--------\n\n";
    }
    
    // Data* ptr = NULL;
    // uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    // std::cout << raw << std::endl; 


    return 0;
}
