#include <iostream>

struct Person {
    int age;
    char name[50]; // uses char array because std::string would point to a specific memory location
    double weight;
};

#pragma pack(push, 1)
struct Person2 {
    int age;
    char name[50]; // uses char array because std::string would point to a specific memory location
    double weight;
};
#pragma pack(pop)

int main() {
    std::cout << "Size of Person (no pragma): " << sizeof(Person) << std::endl;
    std::cout << "Size of Person2 (with pragma): " << sizeof(Person2) << std::endl;

    return 0;
};