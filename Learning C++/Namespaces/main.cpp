#include <iostream>

namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}

int main(){
    // Provides a solution for preventing name conflicts
    // in large prjects. Each entity needs a unique name.
    // A namespace allows for identically named entities
    // as long as the namespaces are different.

    /*
    int x = 0;

    std::cout << x;
    std::cout << first::x;
    std::cout << second::x;
    */

   using namespace first;

   std::cout << x;

    return 0;
}