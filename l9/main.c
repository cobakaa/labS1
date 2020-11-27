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

int mod(int x, int y)
{
    return abs(x - my_div(x, y) * y);
}

int min(int x, int y)
{
    if (x <= y) {
        return x;
    }
    return y;
}

int max(int x, int y)
{
    if (x <= y) {
        return y;
    }
    return x;
}

int main(void)
{

    int i0 = 20, j0 = 0, l0 = 11;
    scanf("%d %d %d", &i0, &j0, &l0);
    int i = i0, j = j0, l = l0;
    int ik = i, jk = j, lk = l;
    int kk = 1, k = kk - 1;
    FILE *f;
    f = fopen("data.txt", "w");

    fprintf(f, "%d %d %d %d\n", i0, j0, l0, k);

    while (kk <= 50 && !(i - j + 10 < 0 && i + 10 > 0 && i + j - 10 < 0)) {
        
        ik = mod(((i - k) * max(j, l) + (j - k) * min(i, l) + (l - k) * max(i, j)), 23);
        jk = -mod(((i - k) * min(j, l) + (j - k) * max(i, l) + (l - k) * min(i, j)), 27);
        lk = abs(i + j - l - k) * sign(i - j + l - k);

        i = ik;
        j = jk;
        l = lk;
        k = kk;

        fprintf(f, "%d %d %d %d\n", i, j, l, k);

        kk += 1;
    }

    fclose(f);

    if (i - j + 10 < 0 && i + 10 > 0 && i + j - 10 < 0) {
        printf("Yes\n%d %d %d %d\n", i, j, l, k);
    } else {
        printf("No\n%d %d %d %d\n", i, j, l, k);
    }
    return 0;
}
