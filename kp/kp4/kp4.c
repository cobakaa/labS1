#include <stdio.h>
#include <math.h>

// float epsilon()
// {
// 	float eps = 1;
// 	while (eps/2 + 1 > 1) eps /= 2;
// 	return eps;
// }

float f3(float x)
{
	return 1 - x + sinf(x) - logf(1 + x);
}

float f4(float x)
{
	return 3 * x - 14 + expf(x) - expf(-x);
}

float dichotomy(float a, float b, float (*f)(float), float eps)
{
	do {
		if (f(a) * f((a + b) / 2) > 0) a = (a + b) / 2;
		if (f(b) * f((a + b) / 2) > 0) b = (a + b) / 2;
	} while (fabsf(a - b) > eps);
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

float iteration(float a, float b, float (*f)(float), float eps)
{
	float x1, x = (a + b) / 2;
	do {
		x1 = x;
		x = f(x1);
	} while (fabsf(x - x1) > eps);
	return x;
}

// float lim(float x, float (*f)(float))
// {
// 	return (f(x + 0.001f) - f(x)) / 0.001f;
// }

float f3dx(float x)
{
    return -1 + cosf(x) - 1 / (1 + x);
}

float f4dx(float x)
{
    return 3 + expf(x) + expf(-x);
}

float newton(float a, float b, float (*f)(float), float (*fdx)(float), float eps)
{
	float x1, x = (a + b) / 2;
	do {
		x1 = x;
		x = x1 - f(x1) / fdx(x1);
	} while(fabsf(x - x1) > eps);
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
    char c0[] = "approximate";

    printf("┏");
    for (int i = 0; i < 30; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 5; i++) printf("━");
    printf("┯");
    for (int i = 0; i < 11; i++) printf("━");
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
    printf("%-*s", 11, c0);
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
    for (int i = 0; i < 11; i++) printf("─");
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
    for (int i = 0; i < 11; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 10; i++) printf("━");
    printf("┷");
    for (int i = 0; i < 15; i++) printf("━");
    printf("┛\n");
}

void print_table_str(char* c, float a, float b, float av, float (*f)(float), float (*fx)(float), float (*fdx)(float), float eps)
{

    printf("┃");
    printf("%-*s", 30, c);
    printf("│");
    printf("2%-*s", 4, " ");
    printf("│");
    printf("3%-*s", 4, " ");
    printf("│");
    printf("%g%-*s", av, 5, " ");
    printf("│");
    printf("%0.7f%-*s", dichotomy(a, b, f, eps), 1, " ");
    printf("│");
    printf("%0.7f%-*s", iteration(a, b, fx, eps), 1, " ");
    printf("│");
    printf("%0.7f%-*s", newton(a, b, f, fdx, eps), 6, " ");
    printf("┃");
    printf("\n");
    if (f != f4) {

        printf("┠");
        for (int i = 0; i < 30; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 5; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 5; i++) printf("─");
        printf("┼");
        for (int i = 0; i < 11; i++) printf("─");
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

    const float av3 = 1.1474;
    const float av4 = 2.0692;

    const float a3 = 1, b3 = 1.5;
    const float a4 = 1, b4 = 3;

    float eps;
    printf("Enter epsilon (>= 1e-6): ");
    scanf("%f", &eps);
    printf("\n");

    //printf("Machine epsilon for type float in system = %0.9f\n", epsilon());

    print_table_top();

    print_table_str(c7, a3, b3, av3, f3, fx3, f3dx, eps);
    print_table_str(c8, a4, b4, av4, f4, fx4, f4dx, eps);

    print_table_bot();

	return 0;
}
