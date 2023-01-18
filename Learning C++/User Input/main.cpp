#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)

int main(){
    std::string name;
    int age;

    /*
    std::cout << "What's your full name?: ";
    std::getline(std::cin, name);

    std::cout << "What's your age?: ";
    std::cin >> age;
    */ 

    // However, if we accept some user input with cin followed by getline,
    // the getline function picks the newline character that is ignored by the cin.
    // That is, after cin, the \n character remains within the input buffer.
    std::cout << "What's your age?: ";
    std::cin >> age;

    // To solve this problem, we can use std::ws to remove any whitespaces before use input.
    std::cout << "What's your full name?: ";
    std::getline(std::cin >> std::ws, name); // As shown here

    std::cout << "Hello " << name << '\n';
    std::cout << "You are  " << age << " years old";

    return 0;
}