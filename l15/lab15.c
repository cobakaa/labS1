#include <stdio.h>

int main(void)
{
    int t, n;
    scanf("%d%d", &t, &n);

    int matrix[n][n];

    for (int ti = 0; ti < t; ++ti) {
        int m_size;
        scanf("%d", &m_size);

        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int i = 0; i < m_size; ++i) { // matrix[m_size - 1 - col][col]
            int sum = 0;
            int i_sum = i, j_sum = i;
            while (i_sum > 0 && j_sum < m_size - 1) {
                i_sum--;
                j_sum++;
            }

            while (i_sum < m_size && j_sum >= 0) {
                sum += matrix[i_sum][j_sum];
                i_sum++;
                j_sum--;
            }
            matrix[i][i] = sum;
        }

        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}