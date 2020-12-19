#include <stdio.h>
#include <math.h>
const float k = 10;
float ret(float eps)
{
	return eps;
}
float eps()
{
	float eps = 1;
	while (ret(eps/2 + 1) > 1) eps /= 2;
	return eps;
}
float f9(float x)
{
	return x*x - log(1 + x) - 3;
}
float f10(float x)
{
	return 2*x*sin(x) - cos(x);
}
float dih(float a, float b, float (*f)(float))
{
	do
	{
		if (f(a)*f((a + b)/2) > 0) a = (a + b)/2;
		if (f(b)*f((a + b)/2) > 0) b = (a + b)/2;
	}
	while (fabs(a - b) > k*eps());
	return (a + b)/2;
}
float fx9(float x)
{
	return sqrt(log(1 + x) + 3);
}
float fx10(float x)
{
	return x-x*sin(x)+cos(x)/2;
}
float iter(float a, float b, float (*f)(float))
{
	float x1, x = (a + b)/2;
	do
	{
		x1 = x;
		x = f(x1);
	}
	while (fabs(x - x1) > k*eps());
	return x;
}
float pr(float x, float (*f)(float))
{
	return (f(x + 0.001) - f(x))/0.001;
}
float new(float a, float b, float (*f)(float))
{
	float x1, x = (a + b)/2;
	do
	{
		x1 = x;
		x = x1 - f(x1)/pr(x1, f);
	}
	while(fabs(x - x1) > k*eps());
	return x;
}
int main()
{
	char c1[] = "Equation";
	char c2[] = "a";
	char c3[] = "b";
	char c4[] = "Dihotomy";
	char c5[] = "Iterations";
	char c6[] = "Newton's method";
	char c7[] = "x² - ln(1 + x) - 3 = 0";
	char c8[] = "2*x*sin(x) - cos(x) = 0";
	printf("┏");
	for (int i = 0; i < 25; i++) printf("━");
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
	printf("%-*s", 25, c1);
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
	for (int i = 0; i < 25; i++) printf("─");
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
	printf("┃");
	printf("%-*s", 26, c7);
	printf("│");
	printf("2%-*s", 4, " ");
	printf("│");
	printf("3%-*s", 4, " ");
	printf("│");
	printf("%0.7f%-*s", dih(2, 3, f9), 1, " ");
	printf("│");
	printf("%0.7f%-*s", iter(2, 3, fx9), 1, " ");
	printf("│");
	printf("%0.7f%-*s", new(2, 3, f9), 6, " ");
	printf("┃");
	printf("\n");
	printf("┠");
	for (int i = 0; i < 25; i++) printf("─");
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
	printf("┃");
	printf("%-*s", 25, c8);
	printf("│");
	printf("0.4%-*s", 2, " ");
	printf("│");
	printf("1%-*s", 4, " ");
	printf("│");
	printf("%0.7f%-*s", dih(0.4, 1, f10), 1, " ");
	printf("│");
	printf("%0.7f%-*s", iter(0.4, 1, fx10), 1, " ");
	printf("│");
	printf("%0.7f%-*s", new(0.4, 1, f10), 6, " ");
	printf("┃\n");
	printf("┗");
	for (int i = 0; i < 25; i++) printf("━");
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
	return 0;
}
