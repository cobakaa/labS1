#include <stdio.h>
typedef enum {
    S0, S1, S2
} State;

int is_digit(char c)
{
    if (c <= '9' && c >= '0') {
        return 1;
    }
    return 0;
}
int is_alpha(char c)
{
    if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
        return 1;
    }
    return 0;
}

int main(void)
{
    char c;
    int a;
    int sum = 0;
    State state = S0;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case S0:
                if (c == '-' || c == '+') {
                    state = S0;
                } else if (is_digit(c)) {
                    a = c - '0';
                    if (a % 2 == 0) {
                        sum += a;
                    }
                    state = S1;
                } else if (is_alpha(c)) {
                    state = S2;
                    sum = 0;
                }
                break;
            case S1:
                if (is_digit(c)) {
                    a = c - '0';
                    if (a % 2 == 0) {
                        sum += a;
                    }
                    state = S1;
                } else if (is_alpha(c)) {
                    state = S2;
                    sum = 0;
                } else if (c == ' ' || c == '\n') {
                    state = S0;
                    
                    if (c == '\n') {
                        printf("%d\n", sum);
                    }
                    sum = 0;
                }
                break;
            case S2:
                if (is_alpha(c)) {
                    state = S2;
                } else if (c == ' ' || c == '\n') {
                    state = S0;
                    sum = 0;
                }
                break;

        }
    }
    return 0;
}

