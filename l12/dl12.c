#include <stdio.h>
void bin(unsigned n, unsigned l, unsigned y) // a, длина, число 0
{
    unsigned i;
    int x;

    for (i = 1 << (l - 1); i > 0; i = i / 2)
    {
        x = y;
        //printf("x = %d \n", x);
        if (i == 1 << (l / 2))
        {
            while (x != 0)
            {
                x = x - 1;
               // printf("x = %d \n", x);
                printf("0");
            }
        }
        (n & i) ? printf("1") : printf("0");
    }
}

int main(void)
{
    int a, a1, a2, kd, kd1, k, k1, d;

    scanf("%d", &a);
    if ((a != ' ') && (a != EOF))
    {
        if (a > 0)
        {
            k = 0;
            a1 = a;
            a2 = a;
            while (a != 0)
            {
                a = a / 10;
                k = k + 1;
            }
            k1 = 10 - k;
            d = 1;
            kd = 0;
            while (a1 >= d)
            {
                d = d * 2;
                kd = kd + 1;
            }
            kd1 = kd / 2;

            bin(a2, kd, k1);
            printf("\n");
        }
    }
}