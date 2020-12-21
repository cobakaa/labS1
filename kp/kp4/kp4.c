#include <stdio.h>
#include <math.h>

const float k = 10;

float epsilon()
{
	float eps = 1;
	while (eps/2 + 1 > 1) eps /= 2;
	return eps;
}

float f3(float x)
{
	return 1 - x + sinf(x) - logf(1 + x);
}

float f4(float x)
{
	return 3 * x - 14 + expf(x) - expf(-x);
}

float dichotomy(float a, float b, float (*f)(float))
{
    float eps = epsilon();
	do {
		if (f(a) * f((a + b) / 2) > 0) a = (a + b) / 2;
		if (f(b) * f((a + b) / 2) > 0) b = (a + b) / 2;
	} while (fabsf(a - b) > k * eps);
	return (a + b) / 2;
}

float fx3(float x)
{
	return 1 + sinf(x) - logf(1 + x);
}

float fx4(float x)
{
	return  logf(-3 * x + 14 + expf(-x));
}

float iteration(float a, float b, float (*f)(float))
{
	float x1, x = (a + b) / 2;
    float eps = epsilon();
	do {
		x1 = x;
		x = f(x1);
	} while (fabsf(x - x1) > k * eps);
	return x;
}

float lim(float x, float (*f)(float))
{
	return (f(x + (float)0.001) - f(x)) / (float)0.001;
}

float newton(float a, float b, float (*f)(float))
{
	float x1, x = (a + b) / 2;
    float eps = epsilon();
	do {
		x1 = x;
		x = x1 - f(x1) / lim(x1, f);
	} while(fabsf(x - x1) > k * eps);
	return x;
}

void print_table_top(void)
{
    char c1[] = "Equation";
    char c2[] = "a";
    char c3[] = "b";
    char c4[] = "dichotomy";
    char c5[] = "iterations";
    char c6[] = "Newton's method";

    printf("┏");
    for (int i = 0; i < 30; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 15; i++) printf("━");
    printf("┓\n");
    printf("┃");
    printf("%-*s", 30, c1);
    printf("│");
    printf("%-*s", 5, c2);
    printf("│");
    printf("%-*s", 5, c3);
    printf("│");
    printf("%-*s", 10, c4);
    printf("│");
    printf("%-*s", 10, c5);
    printf("│");
    printf("%-*s", 15, c6);
    printf("┃\n");

    printf("┠");
    for (int i = 0; i < 30; i++) printf("─");
    printf("┼");
    for (int i = 0; i < 5; i++) printf("─");
    printf("┼");
    for (int i = 0; i < 5; i++) printf("─");
    printf("┼");
    for (int i = 0; i < 10; i++) printf("─");
    printf("┼");
    for (int i = 0; i < 10; i++) printf("─");
    printf("┼");
    for (int i = 0; i < 15; i++) printf("─");
    printf("┨\n");

}

void print_table_bot(void)
{
    printf("┗");
    for (int i = 0; i < 30; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 15; i++) printf("━");
    printf("┛\n");
}

void print_table_str(char* c, float a, float b, float (*f)(float), float (*fx)(float))
{

    printf("┃");
    printf("%-*s", 30, c);
    printf("│");
    printf("2%-*s", 4, " ");
    printf("│");
    printf("3%-*s", 4, " ");
    printf("│");
    printf("%0.7f%-*s", dichotomy(a, b, f), 1, " ");
    printf("│");
    printf("%0.7f%-*s", iteration(a, b, fx), 1, " ");
    printf("│");
    printf("%0.7f%-*s", newton(a, b, f), 6, " ");
    printf("┃");
    printf("\n");
    if (f == f4) {
        print_table_bot();
    } else {
        printf("┠");
        for (int i = 0; i < 30; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 5; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 5; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 10; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 10; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 15; i++) printf("─");
        printf("┨\n");
    }


}

int main(void)
{

    char c7[] = "1 - x + sin(x) - ln(1 + x) = 0";
    char c8[] = "3x - 14 + e^x - e^(-x) = 0";

    const float a3 = 1, b3 = 1.5;
    const float a4 = 1, b4 = 3;

    //printf("Machine epsilon for type float in system = %0.9f\n", epsilon());

    print_table_top();

    print_table_str(c7, a3, b3, f3, fx3);
    print_table_str(c8, a4, b4, f4, fx4);


	return 0;
}