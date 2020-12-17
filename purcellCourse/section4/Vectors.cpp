#include <iostream>
#include <vector>

int main() {
    // creates a dynamic array of strings starting with length 5
    std::vector<std::string> strings1(5);

    strings1.push_back("one");
    strings1.push_back("two");
    strings1.push_back("three");

    strings1[3] = "hello";

    for (int i = 0; i < strings1.size(); i++) {
        std::cout << "strings1[" << i << "] = " << strings1[i] << std::endl;
    }

    for(std::vector<std::string>::iterator itr1 = strings1.begin(); itr1 != strings1.end(); itr1++) {
        std::cout << "current *itr = " << *itr1 << std::endl;
    }
    std::cout << "strings1.size() = " << strings1.size() << std::endl << std::endl;

    // creates a dynamic array of strings, unsized
    std::vector<std::string> strings2;

    strings2.push_back("one");
    strings2.push_back("two");
    strings2.push_back("three");

    std::vector<std::string>::iterator it = strings2.begin();
    std::cout << "dereferenced 'it' = " << *it << std::endl;
    it++;
    std::cout << "dereferenced 'it++' = " << *it << std::endl;

    // loop with iterator, loops while the itr (address) does not equal the end address
    std::vector<std::string>::iterator itr2 = strings2.begin();
    while (itr2 != strings2.end()) {
        std::cout << "current *itr2 = " << *itr2 << std::endl;
        itr2++;
    }

    return 0;
}