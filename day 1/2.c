// 2. [M] Print Pascal's triangle for n rows using a single 1D array updated from right to left. Pattern: in-place update. C focus: loops, array bounds.

#include <stdio.h>
#include <stdlib.h>

void printPascal(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = 1;

        // right to left so old value is not lost
        for (int j = i - 1; j > 0; j--)
        {
            *(arr + j) = *(arr + j) + *(arr + j - 1);
        }

        for (int j = 0; j <= i; j++)
        {
            printf("%d ", *(arr + j));
        }
        printf("\n");
    }
}

int main()
{
    int n = 0;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid rows\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }

    printPascal(arr, n);

    free(arr);
    return 0;
}
