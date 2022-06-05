#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint8_t random = 0b01101011;
    uint8_t mask = 0b11110000;
    uint8_t input = 0b10101101;

    random &= 0b00000000;
    input &= mask;

    printf("Your number is: %x", input);
}
