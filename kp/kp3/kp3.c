#include <stdio.h>
#include <math.h>

void print_table_top(void)
{
    char c1[] = "X";
	char c2[] = "Teylor sum";
	char c3[] = "Value of function";

    printf("┏");
	for (int i = 0; i < 10; i++) printf("━");
	printf("┯");
	for (int i = 0; i < 30; i++) printf("━");
	printf("┯");
	for (int i = 0; i < 30; i++) printf("━");
	printf("┯");
	for (int i = 0; i < 5; i++) printf("━");
	printf("┓\n");
	printf("┃");
	printf("%-*s", 10, c1);
	printf("│");
	printf("%-*s", 30, c2);
	printf("│");
	printf("%-*s", 30, c3);
	printf("│");
	printf("Iter.");
	printf("┃\n");
}

void print_table_str(float x, float res_function, float res_teylor, int n)
{
    printf("┠");
	for (int i = 0; i < 10; i++) printf("─");
	printf("┼");
	for (int i = 0; i < 30; i++) printf("─");
	printf("┼");
	for (int i = 0; i < 30; i++) printf("─");
	printf("┼");
	for (int i = 0; i < 5; i++) printf("─");
	printf("┨\n");
	printf("┃");
	printf("%-*g", 10, x);
	printf("│");
	
    if (x < 0) {
	    printf("%0.9f%-*s", res_teylor, 18, " ");
	    printf("│");
	    printf("%0.9f%-*s", res_function, 18, " ");
	    printf("│");
	    printf("%-*d", 5, n);
	    printf("┃\n");
	} else {
	    printf("%0.9f%-*s", res_teylor, 19, " ");
	    printf("│");
	    printf("%0.9f%-*s", res_function, 19, " ");
	    printf("│");
	    printf("%-*d", 5, n);
	    printf("┃\n");
	}
}

void print_table_bot(void)
{
    printf("┗");
	for (int i = 0; i < 10; i++) printf("━");
	printf("┷");
	for (int i = 0; i < 30; i++) printf("━");
	printf("┷");
	for (int i = 0; i < 30; i++) printf("━");
	printf("┷");
	for (int i = 0; i < 5; i++) printf("━");
	printf("┛\n");
}

float f(float x)
{
	return logf(1 + x - 2 * x * x);
}

float m_round(float x, int n)
{
	n = pow(10, n);
	float res = roundf(x * n) / n; 
	return (res == -0.0f) ? 0.0 : res;
}

int nums(int x)
{
	int res = 0;
	while(x != 0) {
		x /= 10;
		res++;
	}
	return res;
}

float epsilon(void)
{
	float eps = 1.0f;
	while (eps / 2.0f + 1.0f > 1.0f) {
		eps /= 2.0f;
	}
	return eps;
}

int main(void)
{
	float eps = epsilon();

	int steps;
	float k;
	const float a = -0.2, b = 0.3;

	printf("Machine epsilon for type float in system = %0.9f\n", eps);
	printf("Enter number of steps and parameter k: ");
	scanf("%d %f", &steps, &k);
	printf("k = %g", k);
	printf("\n");
	printf("Table of values for the Taylor series and standard function f(x) = ln(1 + x - 2x^2)\n");

	float delta = (b - a) / steps;
	int n = 0;

	print_table_top();

	float x = a;
	for (int i = 0; i <= steps; ++i) {

		float res_teylor = 0, res_function = f(x);
	    float summand = 0;
	    
        do {
            float bin_degree = 2, xnew = x;
            ++n;

            for (int j = 1; j < n; ++j) {
                xnew *= x;
				bin_degree *= 2;
            }

            if ((n + 1) % 2 != 0) bin_degree = -bin_degree;
			summand = ((bin_degree - 1) / n) * xnew;
            res_teylor += summand;

	    } while ((fabsf(res_function - res_teylor) > eps * k) && (n < 100));
	  
        print_table_str(x, res_function, res_teylor, n);

	    x = m_round(a + delta * (i + 1), nums(steps) + 1);
	    n = 0;
	    res_teylor = 0;
	}
	
    print_table_bot();

	return 0;
}
