#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, nmax, i, j, d, flag, test;
    scanf("%d", &test);
    scanf("%d", &nmax);
    while (test != 0)
    {
        scanf("%d", &n);
        if (n > nmax)
        {
            break;
        }
        int a[n][n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        n = n - 1;
        j = 0;
        i = n;
        flag = 1; //flag == 1 когда мы под главной диагональю
        printf("%d ", a[i][j]);
        while ((j != n) || (i != 0))
        {
            //опускаемся
            if (flag == 2)
            {
                i = i - 1;
            }
            else
            {
                j = j + 1;
            }
            printf("%d ", a[i][j]);

            while ((j != 0) && (i != 0))
            {
                j = j - 1;
                i = i - 1;
                printf("%d ", a[i][j]);
            }

            if ((j == 0) && (i == 0))
            {
                flag = 2; //прошли главную диагональ
            }
            //поднимаемся
            if (flag == 2)
            {
                j = j + 1;
            }
            else
            {
                i = i - 1;
            }
            printf("%d ", a[i][j]);

            while ((j != n) && (i != n))
            {
                j = j + 1;
                i = i + 1;
                printf("%d ", a[i][j]);
            }
            if ((j == n) && (i == n))
            {
                flag = 2; // прошли главную диагональ
            }
        }
        test = test - 1;
        if (test != 0)
        {
            printf("\n");
        }
    }
    return 0;
}