#include <iostream>
#include <map>

class Person1 {
private:
    std::string name;
    int age;

public:
    Person1(): name(""), age(0) {};
    Person1(std::string name, int age): name(name), age(age) {};
    Person1(const Person1 &other): name(other.name), age(other.age) {};
    // making the function const means it can't change the instance variables
    void print() const {
        // this is prevented due to the const function
        // age = 23;
        std::cout << "{ Name: " << name << ", Age: " << age << " }" << std::flush;
    };
    bool operator<(const Person1 &other) const {
        return name < other.name;
    };
};

class Person2 {
private:
    std::string name;
    int age;

public:
    Person2(): name(""), age(0) {};
    Person2(std::string name, int age): name(name), age(age) {};
    Person2(const Person2 &other): name(other.name), age(other.age) {};
    void print() const {
        std::cout << "{ Name: " << name << ", Age: " << age << " }" << std::flush;
    };
    bool operator<(const Person2 &other) const {
        if (name == other.name) {
            return age < other.age;
        }

        return name < other.name;
    };
};


int main() {
    std::map<Person1, int> people1;

    people1[Person1("Person1", 23)] = 23;
    people1[Person1("Person2", 94)] = 94;
    people1[Person1("Person3", 2)] = 2;
    // this creates a key mappped to 0
    people1[Person1("Person4", 88)];

    std::cout << "Iterated print of people1" << std::endl;
    for (std::map<Person1, int>::iterator itr = people1.begin(); itr != people1.end(); itr++) {
        std::cout << "Key = " << std::flush;
        itr->first.print();
        std::cout << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // if you do this it considers it as same key so just reassigns map value
    people1[Person1("Person2", 94)] = 34;
    // if you do this it still considers it as existing key because operator<() is only comparing strings
    people1[Person1("Person3", 324)] = 55;

    std::cout << "Iterated print of people1 after reassignments" << std::endl;
    for (std::map<Person1, int>::iterator itr = people1.begin(); itr != people1.end(); itr++) {
        std::cout << "Key = " << std::flush;
        itr->first.print();
        std::cout << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // keys that includes age check for operator<
    std::map<Person2, int> people2;

    people2[Person2("Person8", 33)] = 33;
    people2[Person2("Person6", 45)] = 45;
    people2[Person2("Person7", 56)] = 56;

    std::cout << "Iterated print of people2" << std::endl;
    for (std::map<Person2, int>::iterator itr = people2.begin(); itr != people2.end(); itr++) {
        std::pair<Person2, int> person = *itr;
        std::cout << "Key = " << std::flush;
        person.first.print();
        std::cout << ", Value = " << person.second << std::endl;
    }
    std::cout << std::endl;

    // if you do this it considers it as same key so just reassigns map value
    people2[Person2("Person6", 45)] = 1022;
    // if you do this it now considers it do be different key due to check on age
    people2[Person2("Person7", 1)] = 2033;

    std::cout << "Iterated print of people2 after reassignments" << std::endl;
    for (std::map<Person2, int>::iterator itr = people2.begin(); itr != people2.end(); itr++) {
        std::pair<Person2, int> person = *itr;
        std::cout << "Key = " << std::flush;
        person.first.print();
        std::cout << ", Value = " << person.second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}