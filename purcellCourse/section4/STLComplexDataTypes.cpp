#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<std::string, std::vector<int> > people;

    people["Juan"].push_back(23);
    people["Emilia"].push_back(39);
    people["Juan"].push_back(45);
    people["Juan"].push_back(33);
    people["Emilia"].push_back(9);
    people["Chuy"].push_back(2);

    std::cout << "Printing scores" << std::endl;
    for (std::map<std::string, std::vector<int> >::iterator itr = people.begin(); itr != people.end(); itr++) {
        std::string name = itr->first;
        std::vector<int> scores = itr->second;

        std::cout << name << ": " << std::flush;
        for (int i = 0; i < scores.size(); i++) {
            std::cout << scores[i] << (i < scores.size() - 1 ? ", " : "") << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}