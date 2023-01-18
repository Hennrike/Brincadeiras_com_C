#include <iostream>

int main(){
    // Ternary operator ?: =replacement to an if/else statement
    // condition ? expression1 : expression2

    //int grade = 50;
    //grade >= 60 ? std::cout << "You pass!" : std::cout << "You fail!";

    //int number = 8;
    //number % 2 == 1 ? std::cout << "ODD" : std::cout << "EVEN";

    bool hungry = false;
    //hungry ? std::cout << "You are hungry" : std::cout << "You are full";
    std::cout << (hungry ? "You are hungry" : "You are full");

    return 0;
}