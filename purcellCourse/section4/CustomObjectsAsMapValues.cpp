#include <iostream>
#include <map>

class Person1 {
private:
    std::string name;
    int age;

public:
    Person1(): name(""), age(0) {
        std::cout << "Running Person1 empty constructor" << std::endl;
    };
    Person1(std::string name, int age): name(name), age(age) {
        std::cout << "Running Person1 constructor" << std::endl;
    };
    void print() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    };
};

class Person2 {
private:
    std::string name;
    double weight;

public:
    Person2(): name(""), weight(0) {
        std::cout << "Running Person2 empty constructor" << std::endl;
    };
    Person2(std::string name, double weight): name(name), weight(weight) {
        std::cout << "Running Person2 constructor" << std::endl;
    };
    Person2(const Person2 &other): name(other.name), weight(other.weight) {
        std::cout << "Running Person2 copy constructor" << std::endl;
        // name = other.name;
        // weight = other.weight;
    };
    void print() {
        std::cout << "Name: " << name << ", Weight: " << weight << std::endl;
    };
};

int main() {
    std::map<int, Person1> people1;
    // what is happening here?
    // the "=" operator is doing a shallow copy of right value to left value
    // meaning people1[34] is initiated through default empty constructor
    people1[34] = Person1("P1", 34);
    people1[2] = Person1("P2", 11);
    people1[6] = Person1("P3", 89);
    // this line is here to prove that the empty Person1 constructor runs
    people1[28];

    std::cout << "Iterated print for Person1 map" << std::endl;
    for (std::map<int, Person1>::iterator itr = people1.begin(); itr != people1.end(); itr++) {
        std::cout << "Key: " << itr->first << ", Value: " << std::flush;
        itr->second.print();
    }
    std::cout << std::endl;

    // seeing what happens with custom copy constructor
    std::map<int, Person2> people2;

    people2[34] = Person2("P6", 34.23);
    people2[2] = Person2("P7", 11.20);
    people2[6] = Person2("P8", 89.04);
    people2[45];
    // copy constructor is invoked by insert
    people2.insert(std::make_pair(24, Person2("P9", 233.45)));

    std::cout << "Iterated print for Person2 map" << std::endl;
    for (std::map<int, Person2>::iterator itr = people2.begin(); itr != people2.end(); itr++) {
        if (itr->first == 45) {
            // this does not invoke the copy constructor
            std::cout << "Copy constructor was not invoked" << std::endl;
            std::cout << "Key: " << itr->first << ", Value: " << std::flush;
            itr->second.print();
        } else {
            // this invokes the copy constructor
            std::pair<int, Person2> value = *itr;
            std::cout << "Key = " << value.first << ", Value = " << std::flush;
            value.second.print();
        }

    }
    std::cout << std::endl;

    return 0;
}