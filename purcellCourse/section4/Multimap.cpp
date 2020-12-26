#include <iostream>
#include <map>

int main() {
    // multimap allows duplicate keys
    std::multimap<int, std::string> lookup;

    lookup.insert(std::make_pair(30, "Person 1"));
    lookup.insert(std::make_pair(10, "Person 2"));
    lookup.insert(std::make_pair(20, "Person 3"));
    lookup.insert(std::make_pair(30, "Person 4"));

    std::cout << "Iterated print" << std::endl;
    for (std::multimap<int, std::string>::iterator itr = lookup.begin(); itr != lookup.end(); itr++) {
        std::cout << "Key = " << itr->first << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Iterated print starting from 20" << std::endl;
    // find() returns the itr for key found otherwise return iterator that points to end
    for (std::multimap<int, std::string>::iterator itr = lookup.find(20); itr != lookup.end(); itr++) {
        std::cout << "Key = " << itr->first << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // creating a pair of iterators
    // equal_range returns first and second
    // first is iterator pointing to found value or end
    // second is iterator pointing to end
    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> itrs = 
        lookup.equal_range(30);
    std::cout << "Iterated print using range 30" << std::endl;
    for (std::multimap<int, std::string>::iterator itr = itrs.first; itr != itrs.second; itr++) {
        std::cout << "Key = " << itr->first << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> itrs2 =
        lookup.equal_range(20);
    std::cout << "Iterated print using range 20" << std::endl;
    for (std::multimap<int, std::string>::iterator itr = itrs2.first; itr != itrs2.second; itr++) {
        std::cout << "Key = " << itr->first << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // c++ 11 version which auto types the pair
    auto itrs3 = lookup.equal_range(30);
    std::cout << "Iterated print using range 30 with auto for itrs3" << std::endl;
    for (std::multimap<int, std::string>::iterator itr = itrs3.first; itr != itrs3.second; itr++) {
        std::cout << "Key = " << itr->first << ", Value = " << itr->second << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}