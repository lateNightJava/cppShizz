#include <iostream>
#include <fstream>

#pragma pack(push, 1)

struct Person {
    char name[50];
    // int order;
    int age;
    double height;
};

#pragma pack(pop)

int main() {
    std::string fileName = "test.bin";

    // // first way to open file
    // std::fstream outputFile;
    // outputFile.open(fileName, std::ios::binary|std::ios::out);
    std::ofstream outputFile;
    outputFile.open(fileName, std::ios::binary);

    if (outputFile.is_open()) {
        // for (int i = 0; i < 3; i++) {
        //     int age = 10 * i + 1;
        //     int height = i + 0.1;
        //     Person someone = { "Person", i, age, height };

        //     if (i < 2) {
        //         // new way
        //         outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        //     } else {
        //         // old way
        //         outputFile.write((char *)&someone, sizeof(Person));
        //     }            
        // }

        Person someone = { "Person", 33, 0.9 };

        // // old way
        // outputFile.write((char *)&someone, sizeof(Person));  
        // new way
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
                    
        outputFile.close();
    } else {
        std::cout << "Unable to open: " << fileName << std::endl;
    }

    // // old way
    // std::fstream inputFile;
    // inputFile.open(fileName, std::ios::binary|std::ios::in);
    std::ifstream inputFile;
    inputFile.open(fileName, std::ios::binary);

    if (inputFile.is_open()) {
        Person someoneElse = {};
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

        std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;

        inputFile.close();
    } else {
        std::cout << "Unable to open " << fileName <<std::endl;
    }
    
    return 0;
}