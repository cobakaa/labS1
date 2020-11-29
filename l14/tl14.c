#include <stdio.h>
int main()
{
	int m[7][7], n;
	while (printf("Enter size: ") && scanf("%d", &n) != EOF)
	{
		printf("Enter m:\n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				scanf("%d", &m[i][j]);
		}
		printf("Entered m: \n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				printf("%5d", m[i][j]);
			printf("\n");
		}
		printf("Answer:\n");
		int i = 0, j = 0, k = 0;
		do
		{
			++k;
			printf("%d ", m[i][j]);
			if (i != 0 && j != n-1) 
			{
				--i;
				++j;
			}
			else if (j != n-1)
			{
				i = i + j + 1;
				j = 0;
			}
			else 
			{
				j = n - j + i;
				i = n-1;
			}
		}
		while (k != n*n);
		printf("\n");
	}
	printf("\n");
	return 0;
}
