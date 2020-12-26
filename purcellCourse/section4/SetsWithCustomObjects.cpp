#include<iostream>
#include<set>

class Person {
private:
    int age;
    std::string name;

public:
    Person(): name(""), age(0) {};
    Person(std::string name, int age): name(name), age(age) {};
    Person(const Person &other): name(other.name), age(other.age) {};
    void print() const {
        std::cout << "{ Name: " << name << ", Age: " << age << " }" << std::flush;
    };
    // this is not needed, i guess the operator< is handling this?
    // bool operator==(const Person &other) const {
    //     std::cout << "Equality running" << std::endl;
    //     return name == other.name && age == other.age;
    // };
    bool operator<(const Person &other) const {
        if (name == other.name) {
            return age < other.age;
        }

        return name < other.name;
    };
};

int main() {
    std::set<Person> people;

    people.insert(Person("Person2", 34));
    people.insert(Person("Person45", 22));
    people.insert(Person("Person24", 2));
    people.insert(Person("Person4", 56));

    // note basic string comparison doesn't correctly handle numbers in check in the expected way
    std::cout << "Iterated print" << std::endl;
    for (std::set<Person>::iterator itr = people.begin(); itr != people.end(); itr++) {
        // naive way to do it
        // Person person = *itr;
        // std::cout << "Value = " << std::flush;
        // person.print();
        // std::cout << std::endl;

        // basically same as above but probably more common to use arrow
        std::cout << "Value = " << std::flush;
        itr->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // this does nothing because equality check comes back as exists
    people.insert(Person("Person2", 34));
    // this does insert a new object because ages are different
    people.insert(Person("Person45", 4));
    people.insert(Person("Person2", 239));

    std::cout << "Iterated print after insert" << std::endl;
    for (std::set<Person>::iterator itr = people.begin(); itr != people.end(); itr++) {
        std::cout << "Value = " << std::flush;
        itr->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}