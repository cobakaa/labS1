#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <inttypes.h>

uint32_t f(uint32_t x)  // 110101 -> 001010 ~x & y  
{ 
    int n = 0;
    while((x | (1u << n)) == x) {
        n++;
    }
    return ~(1u << n);
}

int main()
{
    printf("%d\n", f(53));
    return 0;
}