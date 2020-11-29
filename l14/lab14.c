#include <stdio.h>

int main(void)
{
    int tests_num, n_max;
    scanf("%d%d", &tests_num, &n_max);
    int matrix[n_max][n_max];
    for (int t = 0; t < tests_num; ++t) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int lhs = 0;
        while (lhs < m) {
            for (int i = lhs; i <= m - 1; ++i) {
                printf("%d ", matrix[i][m - 1]);
            }
            for (int j = m - 2; j >= lhs; --j) {
                printf("%d ", matrix[m - 1][j]);
            }
            for (int i = m - 2; i >= lhs; --i) {
                printf("%d ", matrix[i][lhs]);
            }
            for (int j = lhs + 1; j <= m - 2; ++j) {
                printf("%d ", matrix[lhs][j]);
            }
            --m;
            ++lhs;
        }
        printf("\n");
    }

    return 0;
}