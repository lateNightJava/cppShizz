#include <iostream>
#include <queue>

class Test {
private:
    std::string name;

public:
    Test(): name("") {};
    Test(std::string name): name(name) {};
    ~Test() {
        std::cout << "Deconstructor ran" << std::endl;
    };
    void print() {
        std::cout << "Name: " << name << std::endl;
    };
};

int main() {
    // queue are FIFO
    std::queue<Test> tests;

    // if you uncomment deconstructor you can see the deconstructor runs for each push
    // this means the object is actually being shallow copied over
    tests.push(Test("Person 1"));
    tests.push(Test("Person 2"));
    tests.push(Test("Person 3"));
    tests.push(Test("Person 4"));
    tests.push(Test("Person 5"));

    std::cout << std::endl;

    // note this is a shallow copy, so at this point 6 objects exist in memory
    Test test1 = tests.front();
    test1.print();
    // note pop does not actually return anything, but it does destroy the object
    tests.pop();
    std::cout << std::endl;


    /***** BAD IDEA 
     * It's tempting to use the reference (&test2) to skip a shallow copy however when tests.pop() runs
     * it destroys the object meaning technically the reference no longer is referencing the expected object
     * this can cause intermitent bugs 
     * It's not a bad idea to use the reference but be aware it no longer exists once pop() is called
     * 
     * Test &test2 = tests.top();
     * tests.pop();
     * test2.print();
     * ******/

    // queues do not use iterators
    std::cout << "Printing of queue, but leaves 1" << std::endl;
    while (tests.size() > 0) {
        Test &test = tests.front();
        test.print();

        // forced break on size 1 so we can see the deconstructor run at end of function
        if (tests.size() == 1) {
            break;
        } else {
            tests.pop();
        }
    }

    std::cout << std::endl << "Line before return" << std::endl;
    // note if at this point all object have not been destroyed the deconstructor runs to clean up memory
    return 0;
}