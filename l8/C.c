#include <stdio.h>

int main(void)
{
    int n = 0, sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a = 0;
        scanf("%d", &a);
        if (a >= 10) {
            sum += a;
        }
    }

    printf("%d\n", sum);

    return 0;
}