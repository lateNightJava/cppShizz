#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "text.txt";

    // // first way of doing this
    // std::ofstream file;
    // file.open(fileName);

    // second way
    std::fstream file;
    file.open(fileName, std::ios::out);

    if (file.is_open()) {
        file << "Testing, testing" << std::endl;
        file << 123 << std::endl;

        for (int i = 1; i <= 10; i++) {
            file << i << ". testing" << std::endl;
        }
        
        file.close();
    } else {
        std::cout << "Unable to open: " << fileName << std::endl;
    }
    return 0;
};

