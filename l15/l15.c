#include <stdio.h>


int max(int x, int y)
{
    return (x > y) ? x : y;
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

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
        
        if (m_size % 2 == 1) {
            int col = m_size / 2;
            
            int sum = 0, str = m_size - 1 - col;
            int i_sum = str, j_sum = col;
            while (min(j_sum, i_sum) > 0) {
                i_sum--;
                j_sum--;
            }

            while (max(i_sum, j_sum) < m_size) {
                sum += matrix[i_sum][j_sum];
                i_sum++;
                j_sum++;
            }
            matrix[str][col] = sum;
            col++;
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