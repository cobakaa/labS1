#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int i, j, l, a, b, pl, mn, max, min, k, k0, div, div1;
    scanf("%d", &i);
    scanf("%d", &j);
    scanf("%d", &l);
    a = 0; k0 = 0; mn = 0; pl = 0;
    if ((i >= 5) && (i <= 15) && (j >= -15) && (j <= -5)) {
        printf("Yes\n");
        printf("%d ", i);
        printf("%d ", j);
        printf("%d ", l);
        printf("%d\n", 0);
        b = 1;
    }
    for (k = 1; k <= 50; ++k) {
        int i1 = i;
        int j1 = j;
        int l1 = l;
        k0 = k - 1;
        if (i1 > 0) {
            pl = 1;
        }
        if (i1 == 0) {
            pl = 0;
        }
        if (i1 < 0) {
            pl = -1;
        }
        if (j1 > 0) {
            mn = 1;
        }
        if (j1 == 0) {
            mn = 0;
        }
        if (j1 < 0) {
            mn = -1;
        }
        if (((i1 + k0) * (j1 - k0) * (l1 + k0)) >= 0) {
            div = (i1 + k0) * (j1 - k0) * (l1 + k0) / 25;
        }
        if (((i1 + k0) * (j1 - k0) * (l1 + k0) < 0) && ((i1 + k0) * (j1 - k0) * (l1 + k0) % 25 != 0)) {
            div = ((i1 + k0) * (j1 - k0) * (l1 + k0) / 25) - 1;
        }
        if (((i1 + k0) * (j1 - k0) * (l1 + k0)) % 25 == 0) {
            div = (((i1 + k0) * (j1 - k0) * (l1 + k0)) / 25);
        }
        i = (i1 + k0) * (j1 - k0) * (l1 + k0) - (div * 25);
        if ((j1 - k0) > (l1 - k0)) {
            max = j1 - k0;
        } else {
            max = l1 - k0;
        }
        if ((i1 + k0) < max) {
            min = i1 + k0;
        } else {
            min = max;
        }
        if (min >= 0) {
            div1 = min / 30;
        }
        if ((min < 0) && (min % 30 != 0)) {
            div1 = min / 30 - 1;
        }
        if (min % 30 == 0) {
            div1 = min / 30;
        }
        j = min - div1 * 30;
        l = abs(j1 - l1) * pl - abs(i1 - l1) * mn;
        if ((i >= 5) && (i <= 15) && (j >= -15) && (j <= -5) && (b != 1)) {
            printf("Yes\n");
            printf("%d ", i);
            printf("%d ", j);
            printf("%d ", l);
            printf("%d\n", k);
            a = 1;
            break;
        }
    }
    if ((a == 0) && (b != 1)) {
        printf("No\n");
        printf("%d ", i);
        printf("%d ", j);
        printf("%d ", l);
        printf("%d\n", 50);
    }
    return 0;
}
            
