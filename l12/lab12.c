#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


const int MIN_INT = -2147483648;

int main(void)
{
    int num = 0;
    while (scanf("%d", &num) == 1) {
        bool answer = true;
        if (num == MIN_INT) {
            num++;
        }
        num = abs(num);
        while (num > 9) {
            int last = num % 10;
            num /= 10;
            if (last < num % 10) {
                answer = false;
                break;
            }
        }
        printf(answer ? "True\n" : "False\n");
    }

    return 0;
}