#include <stdio.h>
typedef enum
{
    S1,
    S2,
    S3
} State;
int is_alphanumeric(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
int main(void)
{
    State state = S1;
    int symbol;
    int sum = 0;
    while ((symbol = getchar()) != EOF)
    {
        switch (state)
        {
        case S1:
            if ((symbol != ' ') && (symbol != '\n'))
            {
                sum = sum % 255 + symbol;
                state = S1;
            };
            if (symbol == ' ')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d ", sum);
                } else printf(" ");
                sum = 0;
                state = S2;
            };
            if (symbol == '\n')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d\n", sum);
                } else printf("\n");
                sum = 0;
                state = S3;
            };
            break;
        case S2:
            if ((symbol != ' ') && (symbol != '\n'))
            {
                sum = sum % 255 + symbol;
                state = S1;
            };
            if (symbol == ' ')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d ", sum);
                } else printf(" ");
                sum = 0;
                state = S2;
            };
            if (symbol == '\n')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d\n", sum);
                } else printf("\n");
                sum = 0;
                state = S3;
            };
            state = S1;
            break;
        case S3:
            if ((symbol != ' ') && (symbol != '\n'))
            {
                sum = sum % 255 + symbol;
                state = S1;
            };
            if (symbol == ' ')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d ", sum);
                } else printf(" ");
                sum = 0;
                state = S2;
            };
            if (symbol == '\n')
            {
                sum = sum % 255;
                if (sum > 0)
                {
                    printf("%d\n", sum);
                } else printf("\n");
                sum = 0;
                state = S3;
            };
            break;
        }
    }
    if (sum > 0)
    {
        printf("%d\n", sum % 255);
    }
    return 0;
}