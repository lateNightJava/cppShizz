#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    std::cout << "Iterated print:" << std::endl;
    for (std::list<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        std::cout << *itr << std::endl;
    }
    std::cout << std::endl;

    // list insert()
    std::list<int>::iterator insertItr = numbers.begin();
    std::cout << "Element start: " << *insertItr << std::endl;
    insertItr++;
    std::cout << "Element after insertItr++: " << *insertItr << std::endl;
    // insert adds element before current node
    std::list<int>::iterator insertItr2 = numbers.insert(insertItr, 100);
    std::cout << "Element after insert() (note points to same node): " << *insertItr << std::endl;
    std::cout << "Inserted node element: " << *insertItr2 << std::endl;
    insertItr++;
    insertItr2++;
    std::cout << "Element after insertItr++: " << *insertItr << std::endl;
    std::cout << "Element after insertItr2++ (note same node where insert happened): " << *insertItr2 << std::endl;


    std::cout << "Iterated print after insert():" << std::endl;
    for (std::list<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        std::cout << *itr << std::endl;
    }
    std::cout << std::endl;

    // list erase()
    std::list<int>::iterator eraseItr = numbers.begin();
    std::cout << "Element start: " << *eraseItr << std::endl;
    eraseItr++;
    std::cout << "Element after eraseItr++: " << *eraseItr << std::endl;
    // erase removes the current node
    std::list<int>::iterator eraseItr2 = numbers.erase(eraseItr);
    std::cout << "Element after erase() (note INCORRECT REF because points to same node): " << *eraseItr << std::endl;
    std::cout << "Next node element (note CORRECT REF, points to next node): " << *eraseItr2 << std::endl;
    eraseItr++;
    eraseItr2++;
    std::cout << "Element after eraseItr++ (note INCORRECT): " << *eraseItr << std::endl;
    std::cout << "Element after eraseItr2++ (note CORRECT): " << *eraseItr2 << std::endl;

    std::cout << "Iterated print after erase():" << std::endl;
    for (std::list<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        std::cout << *itr << std::endl;
    }
    std::cout << std::endl;

    return 0;
}