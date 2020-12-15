#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "test.txt";

    // first way to do this
    std::ifstream file;
    file.open(fileName);
    // // second way to do this
    // std::fstream file;
    // file.open(fileName, std::ios::in);

    if (file.is_open()) {
        std::string firstWord;
        file >> firstWord;
        std::cout << "First word from file: " << firstWord << std::endl;
        
        // clear is safety to make sure eof hasn't been flagged
        file.clear();
        // moves back to beginning of file
        file.seekg(0, std::ios::beg);

        std::string line;
        int i = 1;
        // while (file) { // this also works due to bool operator overloading
        while (!file.eof()) {
           std::getline(file, line);
           std::cout << i << ") " << line << std::endl;
           i++;
        }

        file.close();
    } else {
        std::cout << "Unable to open: " << fileName << std::endl;
    }

    return 0;
};