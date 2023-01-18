#include <iostream>

int main(){
    // fill() = Fills a range of elements with a specified value
    //          fill(begin, end, value)

    std::string foods[100];

    fill(foods, foods + 100, "pizza");

    for(std::string food : foods){
        std::cout << food << '\n';
    }

    return 0;
}