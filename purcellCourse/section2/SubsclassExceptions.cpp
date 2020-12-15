#include <iostream>
#include <exception> // note technically this isn't needed because <iostream> already includes it

void goesWrong() {
    bool error1 = false;
    bool error2 = true;

    if (error1) {
        throw std::bad_alloc();
    } else if (error2) {
        throw std::exception();
    }
};

int main() { 
    // // this falsely works when bad_alloc error is through
    // // the reason is because bad_alloc is a subclass of exception
    // try {
    //     goesWrong();
    // } catch(std::exception &e) {
    //     std::cout << "Catching Exception: " << e.what() << std::endl;
    // } catch(std::bad_alloc &e) {
    //     std::cout << "Catching bad_alloc: " << e.what() << std::endl;
    // }

    // Instead do this
    try {
        goesWrong();
    } catch(std::bad_alloc &e) {
        std::cout << "Catching bad_alloc: " << e.what() << std::endl;
    } catch(std::exception &e) {
        std::cout << "Catching exception: " << e.what() << std::endl;
    } 

    return 0;
};