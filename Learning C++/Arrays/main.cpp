#include <iostream>

int main(){
    // Array =  a data structure that can hold multiple values
    //          values are accessed by an index number
    //          "kind of like a variable that holds multiple values"

    std::string cars[] = {"Corvette", "Mustang", "Camry"};

    std::cout << cars[0];
    std::cout << cars[1];
    std::cout << cars[2];

    return 0;
}