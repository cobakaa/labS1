#include <stdio.h>
typedef enum { S1, S2, S3 } State;
int is_alphanumeric(char c) {
    return(c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9');
}
int main(void)
{
    State state = S1;
    int symbol;
    int sum = 0;
    while (( symbol = getchar()) != EOF ) {
        switch (state) {
            case S1:
                if (is_alphanumeric(symbol)) {
                    sum = (sum + (symbol % 255)) % 255;
                    state = S1;
                }
                if (symbol == ' ') {
                    printf("%d ", sum);
                    sum = 0;
                    state = S2;
                }
                if (symbol == '\n') {
                    printf("%d\n", sum);
                    sum = 0;
                    state = S3;
                }
                break;
            case S2:
                if (is_alphanumeric(symbol)) {
                    sum = (sum + (symbol % 255)) % 255;
                    state = S1;
                }
                if (symbol == ' ') {
                    if (sum != 0) {
                        printf("%d ", sum);
                        sum = 0;
                    }
                    state = S2;
                }
                if (symbol == '\n') {
                    if (sum != 0) {
                        printf("%d\n", sum);
                        sum = 0;
                    }
                    state = S3;
                }
                break;
            case S3:
                if (is_alphanumeric(symbol)) {
                    sum = (sum + (symbol % 255)) % 255;
                    state = S1;
                }
                if (symbol == ' ') {
                    if (sum != 0) {
                        printf("%d ", sum);
                        sum = 0;
                    }
                    state = S2;
                }
                if (symbol == '\n') {
                    if (sum != 0) {
                        printf("%d\n", sum);
                        sum = 0;
                    }
                    state = S3;
                }
                break;
        }
    }
    if (sum != 0) {
        printf("%d", sum);
    }
    return 0;
}