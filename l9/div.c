#include <stdio.h>
#include <stdlib.h>

int sign(int x)
{
    if (x == 0) {
        return 0;
    }
    return x / abs(x);
}

int my_div(int x, int y)
{
    if (x == 0 || y == 0) {
        return 0;
    }
    int res = 0;
    int x_sign = sign(x), y_sign = sign(y);
    x = abs(x);
    y = abs(y);
    while (x >= y) {
        x -= y;
        res++;
    }

    if (x_sign * y_sign < 0) {
        if (x != 0) {
            return -(res + 1);
        }
        return -res;
    }
    return res;
}

int main() {

    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", my_div(a, b));

    return 0;
}