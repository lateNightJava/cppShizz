#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;

    numbers.insert(23);
    numbers.insert(45);
    numbers.insert(1);
    numbers.insert(345);
    numbers.insert(234);
    // note inserting already existing value does not do anything
    numbers.insert(45);

    std::set<int>::iterator endItr = numbers.end();
    std::cout << "endItr = " << *endItr << std::endl;

    std::cout << "Iterated print" << std::endl;
    for (std::set<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        std::cout << "Value: " << *itr << std::endl;
    }
    std::cout << std::endl;

    // this removes value from set, logarithmic 
    numbers.erase(234);
    // this also removes based on itr position, amortized constant
    std::set<int>::iterator eraseItr = numbers.find(345);
    numbers.erase(eraseItr);

    std::cout << "Iterated print after erase()" << std::endl;
    for (std::set<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        std::cout << "Value: " << *itr << std::endl;
    }
    std::cout << std::endl;

    return 0;
}