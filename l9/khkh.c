#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define C1X0 -10
#define C1Y0 -10
#define C1RAD 10

#define C2X0 -20
#define C2Y0 -20
#define C2RAD 10

double mode(double x, double y)
{
    return abs(x - floor(x / y) * y);
}
int max(int x, int y, int z)
{
    int max;
    max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    return max;
}
int min(int x, int y, int z)
{
    int min;
    min = x;
    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }
    return min;
}
int in_circle(double x, double y, double x0, double y0, double radius)
{
    return (x - x0) * (x - x0) + (y - y0) *(y - y0) <= radius * radius;
}
int in_area(int x, int y)
{
    return in_circle(x, y, C1X0, C1Y0,C1RAD) && in_circle(x, y, C2X0, C2Y0, C2RAD);
}
int compute_i(int i, int j, int l, int k)
{
    return mode(i * i * i - j * j * j + l * l* l - k, 20);
}
int compute_j(int i, int j, int l, int k)
{
    return mode(min(i * j * j - k, i * i * l - k, j * l * l - k), 30);
}
int compute_l(int i, int j, int l, int k)
{
    return mode(max(i * j * j - k, i * i * l - k, j * l * l - k), 30);
}
int main(void)
{
    int i, j, l, k, i1, j1, l1; 
    scanf("%d %d %d", &i, &j, &l);

    for (k = 0; ! in_area(i, j) && k < 50; ++k) {
        i1 = compute_i(i, j, l, k);
        j1 = compute_j(i, j, l, k);
        l1 = compute_l(i, j, l, k);

        i = i1;
        j = j1;
        l = l1;
    }
    printf(in_area(i, j) ? "Yes\n" : "No\n");

    printf("%d %d %d %d\n", i, j, l, k);
    return 0;
}