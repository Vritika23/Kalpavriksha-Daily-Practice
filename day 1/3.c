// 3. [M] Reverse an array in place with two pointers (no indexing), then Rotate Array by k using three reversals. Pattern: two pointers. C focus: pointer arithmetic, p++ and *p.

#include <stdio.h>
#include <stdlib.h>

void reverse(int *start, int *end)
{
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void rotate(int *arr, int n, int k)
{
    k = k % n;
    if (k == 0)
        return;

    reverse(arr, arr + n - 1);
    reverse(arr, arr + k - 1);
    reverse(arr + k, arr + n - 1);
}

void printArray(int *arr, int n)
{
    for (int *p = arr; p < arr + n; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
}

int main()
{
    int n = 0, k = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid size\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int *p = arr; p < arr + n; p++)
    {
        scanf("%d", p);
    }

    reverse(arr, arr + n - 1);
    printf("Reversed: ");
    printArray(arr, n);

    // reverse back to original
    reverse(arr, arr + n - 1);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 0)
    {
        printf("Invalid k\n");
        free(arr);
        return 0;
    }

    rotate(arr, n, k);
    printf("Rotated: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
