#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int my_abs(long long int x)
{
    return (x >= 0) ? x : -x;
}

int sign(long long int x)
{
    return (x == 0) ? 0 : x / my_abs(x);
}

int my_div(long long int x, long long int y)
{
    if (x == 0 || y == 0) {
        return 0;
    }
    int res = 0;
    int x_sign = sign(x), y_sign = sign(y);
    x = my_abs(x);
    y = my_abs(y);
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

int mod(long long int x, long long int y)
{
    return my_abs(x - my_div(x, y) * y);
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int max(int x, int y)
{
    return (x <= y) ? y : x;
}

bool is_inside(long long int x, long long int y)
{
    return x + 10 < y && x > -10 && x - 10 < -y;
}

int main(void)
{

    int i0 = 20, j0 = 0, l0 = 11;
    scanf("%d %d %d", &i0, &j0, &l0);
    int i = i0, j = j0, l = l0;
    int ik = i, jk = j, lk = l;
    int kk = 1, k = kk - 1;

    while (kk <= 50 && !is_inside(i, j)) {
        
        ik = mod((mod((i - k) * (max(j, l)), 23) + mod((j - k) * min(i, l), 23) + mod((l - k) * max(i, j), 23)), 23);
        jk = -mod(mod((i - k) * min(j, l), 27) + mod((j - k) * max(i, l), 27) + mod((l - k) * min(i, j), 27), 27);
        lk = my_abs(i + j - l - k) * sign(i - j + l - k);

        i = ik;
        j = jk;
        l = lk;
        k = kk;

        kk += 1;
    }

    if (is_inside(i, j)) {
        printf("Yes\n%d %d %d %d\n", i, j, l, k);
    } else {
        printf("No\n%d %d %d %d\n", i, j, l, k);
    }
    return 0;
}