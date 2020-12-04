#include <iostream>

void throwAnError() {
    // modify to test different cases
    bool error = false, error2 = true, error3 = true;

    if (error) {
        throw 8;
    } else if (error2) {
        throw "Char array error";
    } else if (error3) {
        throw std::string("String error");
    }
}

void useThrowAnError() {
    throwAnError();
}

int main() {

    try {
        // throwAnError();
        useThrowAnError();
    } catch(int e) {
        std::cout << "Int err: " << e << std::endl;
    } catch(char const * e) {
        std::cout << "Char Arr err: " << e << std:: endl;
    } catch(std::string e) {
        std::cout << "String err: " << e << std:: endl;
    }

    std::cout << "main func ending..." << std::endl;
    
    return 0;
}