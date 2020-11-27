#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int main(void)
{
    int i,j,l,a=0,result1,result2,max,min,k0;
    int ik = i, jk = j, lk = l;
    scanf("%d",&i);
    scanf("%d",&j);
    scanf("%d",&l);
    k0 = 0;
    for (int k = 1; k < 51; ++k) {
        k0 = k-1;
        if (i > 0) {
            result1 = 1;
        }
        if (i == 0) {
            result1 = 0;
        }
        if (i < 0) {
            result1 = -1;
        }
        if (j > 0) {
            result2 = 1;
        }
        if (j == 0) {
            result2 = 0;
        }
        if (j < 0) {
            result2 = -1;
        }
        ik=mod((i + k0)*(j - k0)*(l + k0), 25);
        if ((j - k0) > (l - k0)) {
            max = j - k0;
        }
        else {
            max = l - k0;
        }
        if ((i + k0) < max) {
            min = i + k0;
        }
        else {
            min = max;
        }
        jk = mod(min, 30);
        lk = abs(j - l)*result1-abs(i - l)*result2;

        i = ik;
        j = jk;
        l = lk;

        if ((i >= 5) && ( i <= 15) && (j >= -15) && (j <= -5)) {
            printf("Yes\n");
            printf("%d ",i);
            printf("%d ",j);
            printf("%d ",l);
            printf("%d\n",k);
        }
        if ((i >= 5) && ( i <= 15) && (j >= -15) && (j <= -5)) {
            a = 1;
            break;
        }
    }
    if (a == 0) {
    printf("No\n");
    printf("%d ",i);
    printf("%d ",j);
    printf("%d ",l);
    printf("%d\n",k0 + 1);
    }
return 0;
}
            
