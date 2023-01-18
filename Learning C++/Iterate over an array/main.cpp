#include <iostream>

int main(){
    std::string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};

    for(int i = 0;i<(sizeof(students)/sizeof(std::string));i++){
        std::cout << students[i] << '\n';
    }

    return 0;
}