#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;

    ages["Person 1"] = 20;
    ages["Person 2"] = 30;
    ages["Person 3"] = 40;

    std::cout << "Iterated print" << std::endl;
    for (std::map<std::string, int>::iterator itr = ages.begin(); itr != ages.end(); itr++) {
        std::cout << itr->first << ": " << itr->second << std::endl;
        // this is what the -> does
        // std::cout << (*itr).first << ": " << (*itr).second << std::endl;
    } 
    std::cout << std::endl;

    ages["Person 2"] = 60;
    std::cout << "Iterated print after reassigning Person 2 (using std::pair)" << std::endl;
    for (std::map<std::string, int>::iterator itr = ages.begin(); itr != ages.end(); itr++) {
        std::pair<std::string, int> age = *itr;
        std::cout << age.first << ": " << age.second << std::endl;
    }
    std::cout << std::endl;

    // naive, incorrect way of checking if a value exists
    if (ages["Person 4"]) {
        std::cout << "Person 4 found." << std::endl;
    } else {
        std::cout << "Person 4 not found but now it exists in map with value 0" << std::endl;
    }

    std::cout << "Iterated print after incorrectly looking if value exists" << std::endl;
    for (std::map<std::string, int>::iterator itr = ages.begin(); itr != ages.end(); itr++) {
        std::cout << itr->first << ": " << itr->second << std::endl;
    } 
    std::cout << std::endl;

    // correct way of checking if value exists
    if (ages.find("Person 5") != ages.end()) {
        std::cout << "Person 5 found." << std::endl;
    } else {
        std::cout << "Person 5 not found, and correctly does not add value to map." << std::endl;
    }

    std::cout << "Iterated print after correctly checking if Person 5 exists (using std::pair)" << std::endl;
    for (std::map<std::string, int>::iterator itr = ages.begin(); itr != ages.end(); itr++) {
        std::pair<std::string, int> age = *itr;
        std::cout << age.first << ": " << age.second << std::endl;
    }
    std::cout << std::endl;

    // adding a pair with insert()
    std::pair<std::string, int> addToMap("Person 6", 58);
    ages.insert(addToMap);
    ages.insert(std::pair<std::string, int>("Person 7", 44));
    ages.insert(std::make_pair("Person 8", 29));
    std::cout << "Iterated print after using inserting pairs" << std::endl;
    for (std::map<std::string, int>::iterator itr = ages.begin(); itr != ages.end(); itr++) {
        std::cout << itr->first << ": " << itr->second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}