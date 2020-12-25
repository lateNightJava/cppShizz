#include <iostream>
#include <vector>

int main() {
    // double vector
    std::vector<double> numbers1(20);
    std::cout << "numbers1.size() = " << numbers1.size() << std::endl;

    int numbers1Capacity = numbers1.capacity();
    std::cout << "numbers1 initial capacity = " << numbers1Capacity << std::endl;

    for (int i = 0; i < 10000; i++) {
        if (numbers1.capacity() != numbers1Capacity) {
            numbers1Capacity = numbers1.capacity();
            std::cout << "numbers1 updated capacity = " << numbers1Capacity << std::endl;
        }

        numbers1.push_back(i);
    }

    numbers1.clear();
    std::cout << "numbers1 size after clear() = " << numbers1.size() << std::endl;
    std::cout << "numbers1 capacity after clear() = " << numbers1.capacity() << std::endl;
    std::cout << "numbers1[0] = " << numbers1[0] << std::endl;
    std::cout << "numbers1[1] = " << numbers1[1] << std::endl << std::endl;
    
    // integer vector 
    std::vector<int> integers1(0);
    std::cout << "integers1.size() = " << integers1.size() << std::endl;

    int integers1Capacity = integers1.capacity();
    std::cout << "integers1 initial capacity = " << integers1Capacity << std::endl;

    for (int i = 0; i < 10000; i++) {
        if (integers1.capacity() != integers1Capacity) {
            integers1Capacity = integers1.capacity();
            std::cout << "integers1 current size = " << integers1.size() << std::endl;
            std::cout << "integers1 updated capacity = " << integers1Capacity << std::endl;
        }

        integers1.push_back(i);
    }

    integers1.resize(100);
    std::cout << "integers1 size after resize(100) = " << integers1.size() << std::endl;
    std::cout << "integers1 capacity after resize(100) = " << integers1.capacity() << std::endl;
    std::cout << "integers1[0] = " << integers1[0] << std::endl;
    std::cout << "integers1[99] = " << integers1[99] << std::endl;
    std::cout << "integers1[100] = " << integers1[100] << std::endl;
    std::cout << "integers1[101] = " << integers1[101] << std::endl << std::endl;

    integers1.reserve(100000);
    std::cout << "integers1 size after reserve(100000) = " << integers1.size() << std::endl;
    std::cout << "integers1 capacity after reserve(100000) = " << integers1.capacity() << std::endl;
    std::cout << "integers1[0] = " << integers1[0] << std::endl;
    std::cout << "integers1[99] = " << integers1[99] << std::endl;
    std::cout << "integers1[100] = " << integers1[100] << std::endl;
    std::cout << "integers1[101] = " << integers1[101] << std::endl << std::endl;
    
    return 0;
}