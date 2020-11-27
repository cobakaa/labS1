#include <stdio.h>
#include <stdlib.h>

int sign(int x) {
    if (x == 0) {
        return 0;
    }
    return x / abs(x);
}


int main() {

    int x;
    scanf("%d", &x);

    printf("%d\n", sign(x));

    return 0;
}