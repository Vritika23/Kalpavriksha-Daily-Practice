// 4. [M] Find the second largest and second smallest in one pass and return both through pointer parameters. Handle duplicates and arrays with fewer than two distinct values. Pattern: tracking extremes. C focus: call by address.

#include <stdio.h>
#include <stdlib.h>

// returns 1 if found, 0 if less than two distinct values
int findSecond(int *arr, int n, int *secLarge, int *secSmall)
{
    int large = *arr, small = *arr;
    int found = 0;

    for (int *p = arr + 1; p < arr + n; p++)
    {
        if (*p > large)
        {
            *secLarge = large;
            large = *p;
        }
        else if (*p < large && (!found || *p > *secLarge))
        {
            *secLarge = *p;
        }

        if (*p < small)
        {
            *secSmall = small;
            small = *p;
        }
        else if (*p > small && (!found || *p < *secSmall))
        {
            *secSmall = *p;
        }

        if (*p != *arr)
            found = 1;
    }

    return found;
}

int main()
{
    int n = 0;
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

    int secLarge, secSmall;
    if (findSecond(arr, n, &secLarge, &secSmall))
    {
        printf("Second largest: %d\n", secLarge);
        printf("Second smallest: %d\n", secSmall);
    }
    else
    {
        printf("Not enough distinct values\n");
    }

    free(arr);
    return 0;
}
