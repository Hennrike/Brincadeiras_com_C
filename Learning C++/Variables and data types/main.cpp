#include <iostream>

int main(){

    // Integer (accepts only integer numbers)

    /*
    int x; // declaration
    x = 5; // assingment
    */

    int x =5;
    int y = 6;
    int sum = x + y;

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << sum << '\n';

    // Double has more bytes and precision than float (both accept integer and decimals)
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 25.1;

    std::cout << price << '\n';

    // Single Character
    char grade = 'A';
    char initial = 'B';

    std::cout << initial << '\n';

    // Boolean (true or false)
    bool student = true;
    bool power = false;
    bool forSale = false;

    // String (objects that represents a sequence of text)
    std::string name = "Henrique";
    std::string day = "Friday";
    std::string food = "pizza";

    std::cout << name;

    return 0;
}