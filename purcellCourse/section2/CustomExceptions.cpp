#include <iostream>
#include <exception>

// inherits from standard exception class
class MyException: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Custom error...";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

int main() {
    Test test;

    try {
        test.goesWrong();
    } catch (MyException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}