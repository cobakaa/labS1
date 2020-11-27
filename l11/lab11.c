#include <stdio.h>
#include <stdbool.h>

typedef enum {
    ALPH, SPACE, LF
} Cond;

bool is_space(int c)
{
    return c == ' ' || c == '\t';
}

char decode(char c, int n)
{
    if (c >= '0' && c <= '9') {
        n %= 10;
        return (c - '0' < n) ? '9' - (n - (c - '0')) + 1 : c - n;
    }

    if (c >= 'a' && c <= 'z') {
        n %= 26;
        return (c - 'a' < n) ? 'z' - (n - (c - 'a')) + 1 : c - n;
    }

    if (c >= 'A' && c <= 'Z') {
        n %= 26;
        return (c - 'A' < n) ? 'Z' - (n - (c - 'A')) + 1 : c - n;
    }

    return c;

}

bool is_alph(int c)
{
    return !is_space(c) && c != '\n';
}

int main(void)
{
    int c = 0;
    Cond cond = LF;
    int word_num = 0;
    while ((c = getchar()) != EOF) {
        switch (cond) {
            case ALPH:
                if (is_alph(c)) {
                    cond = ALPH;
                    putchar(decode(c, word_num));
                } else if (is_space(c)) {
                    cond = SPACE;
                    word_num++;
                    putchar(c);
                } else {
                    cond = LF;
                    putchar('\n');
                }
                break;

            case SPACE:
                if (is_space(c)) {
                    cond = SPACE;
                    putchar(c);
                } else if (is_alph(c)) {
                    cond = ALPH;
                    putchar(decode(c, word_num));
                } else if (c == '\n') {
                    cond = LF;
                    putchar('\n');
                }
                break;
            
            case LF:
                if (is_alph(c)) {
                    cond = ALPH;
                    word_num = 0;
                    putchar(decode(c, word_num));
                } else if (is_space(c)) {
                    cond = SPACE;
                    word_num = 0;
                    putchar(c);
                } else {
                    cond = LF;
                    putchar('\n');
                }
                break;
        }
    }
    return 0;
}