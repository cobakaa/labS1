#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int steps;
    scanf("%d", &steps);

    for (int i = 0; i < steps; ++i) {
        for (int j = n - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }
        arr[0] = 0;
        
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }

    if (steps == 0) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }

    return 0;
}