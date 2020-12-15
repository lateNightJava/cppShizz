#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "stats.txt";

    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return 1;
    }

    while (file) {
        std::string line;
        std::getline(file, line, ':'); 

        int population;
        file >> population;

        // clears out the extra white space, not ideal because more white space can exist
        // file.get();
        // c++ 11 version of clearing out white space
        file >> std::ws;

        // if the file has ended leave
        if (!file) {
            break;
        }

        std::cout << line << " -- " << population << std::endl;
    }

    file.close();

    return 0;
}