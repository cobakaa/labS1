#include <stdio.h>
#include <math.h>

void d(int x, int s, int h) {
    
    if (x == 0) {
        return;
    }
    d(x / 2, s - 1, h);

    if (s == 0) {
        for (int i = 0; i < h; ++i) {
            printf("0");
        }
    }

    if (x % 2 == 1) {
        printf("1");
    } else {
        printf("0");
    }

    
}

int main() {

    int a = 1234567;

    int b = 1;
    int length = 0;

    while (b < a) {
        b *= 2;
        length++;
    }

    int h = 0;
    int copy = a;
    while (copy > 0) {
        copy /= 10;
        h++;
    }

    d(a, length / 2, 10 - h);

    printf("\n");
    //printf("%d\n", length);

    return 0;
}