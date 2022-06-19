#include <stdio.h>
#include <time.h>

int main(){
    time_t seconds;
    seconds = time(NULL);
    printf("%i", (seconds/60/60/24/30/12)+1969);
}
