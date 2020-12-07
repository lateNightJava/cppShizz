#include <iostream>

class SomethingWrong {
public:
    SomethingWrong() {
        // char *pMemory = new char[999];
        char *pMemory = new char[999999999999999999];
        delete[] pMemory;
    }
};

int main() {
    try {
        SomethingWrong();
    }
    catch(std::bad_alloc &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Still running..." << std::endl;

    return 0;
};