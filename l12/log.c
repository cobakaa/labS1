#include <stdio.h>
#include <math.h>

void bin(int x, int s, int h) {
    
    if (x == 0) {
        return;
    }
    bin(x / 2, s - 1, h);

    if (s == 0) {
        for (int i = 0; i < h; ++i) {
            printf("0");
        }
    }

    printf((x % 2) ? "1" : "0");
    
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

    bin(a, length / 2, 10 - h);

    printf("\n");
    //printf("%d\n", length);

    return 0;
}