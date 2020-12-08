#include <stdio.h>
void bin(unsigned n, int l, int y)
{
    unsigned i;
    int x;
    for (i = 1 << (l - 1); i > 0; i = i / 2)
    {
        x = y;

        if (i == 1 << (l / 2))
        {
            while (x != 0)
            {
                x = x - 1;
                printf("0");
            }
        }
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}

int main(void)
{
    int a, a1, a2, kd, k, k1, d;

    while (scanf("%d", &a) == 1)
    {
        if (a == 0)
        {
            printf("0000000000");
        }
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
            bin(a2, kd, k1);
        }

        if (a < 0)
        {
            a = -a;
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
            printf("-");
            bin(a2, kd, k1);
        }
    }
}