#include <iostream>

void happyBirthday(std::string name){
    std::cout << "Happy Birthday to " << name << '\n';
    std::cout << "Happy Birthday to " << name << '\n';
    std::cout << "Happy Birthday dear " << name << '\n';
    std::cout << "Happy Birthday to " << name << '\n';
}

int main(){
    std::string name = "Henrique";

    happyBirthday(name);

    return 0;
}