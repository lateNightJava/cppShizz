#include <iostream>
#include <vector>

class Person1 {
private:
    std::string name;
    int age;

public:
    Person1(): name(""), age(0) {};
    Person1(std::string name, int age): name(name), age(age) {};
    void print() {
        std::cout << "{ Name: " << name << ", Age: " << age << " }" << std::endl;
    }
    bool operator<(const Person1 &other) const {
        if (name == other.name) {
            return age < other.age;
        }

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
    void print() {
        std::cout << "{ Name: " << name << ", Age: " << age << " }" << std::endl;
    }
    // need friend so private variables are accessible
    friend bool comparePeople(const Person2 &a, const Person2 &b);
};

bool comparePeople(const Person2 &a, const Person2 &b) {
    if (a.name == b.name) {
        return a.age < b.age;
    }

    return a.name < b.name;
}

int main() {
    std::vector<Person1> people1;
    people1.push_back(Person1("Emilia", 1));
    people1.push_back(Person1("Jorge", 34));
    people1.push_back(Person1("Carlos", 2));
    people1.push_back(Person1("Carla", 99));
    people1.push_back(Person1("Emilia", 25));
    people1.push_back(Person1("Yessy", 45));
    people1.push_back(Person1("Emilia", 23));

    // sorting using operator overload
    std::sort(people1.begin(), people1.end());
    std::cout << "Iterated print of people1" << std::endl;
    for (std::vector<Person1>::iterator itr = people1.begin(); itr != people1.end(); itr++) {
        itr->print();
    }
    std::cout << std::endl;

    std::vector<Person2> people2;
    people2.push_back(Person2("Emilia", 1));
    people2.push_back(Person2("Jorge", 34));
    people2.push_back(Person2("Carlos", 2));
    people2.push_back(Person2("Carla", 99));
    people2.push_back(Person2("Emilia", 25));
    people2.push_back(Person2("Yessy", 45));
    people2.push_back(Person2("Emilia", 23));

    // sorting using friend function
    std::sort(people2.begin(), people2.end(), comparePeople);
    std::cout << "Iterated print of people2" << std::endl;
    for (std::vector<Person2>::iterator itr = people2.begin(); itr != people2.end(); itr++) {
        itr->print();
    }

    return 0;
}