// 5. [H] Read N non-negative numbers into a dynamic array where every number appears twice except two numbers that appear only once. Find those two numbers using XOR (no extra array). Then sort the array by number of set bits (if same, smaller number first) using pointers and print each number with its binary form. Pattern: bit manipulation. C focus: malloc, pointers, &, ^, >>.

#include <stdio.h>
#include <stdlib.h>

int countSetBits(unsigned int num)
{
    int count = 0;

    while (num != 0)
    {
        if (num & 1)
            count++;

        num = num >> 1;
    }

    return count;
}

void printBinary(unsigned int num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }

    unsigned int mask = 1U << 31;
    
    while ((num & mask) == 0)
        mask = mask >> 1;

    while (mask != 0)
    {
        printf("%d", (num & mask) ? 1 : 0);
        mask = mask >> 1;
    }
}

void findTwoSingle(unsigned int *arr, int n)
{
    unsigned int xor = 0;

    // XOR of all elements gives the two unique numbers
    for (unsigned int *p = arr; p < arr + n; p++)
        xor = xor ^ *p;

    if (xor == 0)
    {
        printf("No two single numbers\n");
        return;
    }

    unsigned int bit = xor & (~xor + 1);

    unsigned int a = 0, b = 0;

    for (unsigned int *p = arr; p < arr + n; p++)
    {
        if (*p & bit)
            a = a ^ *p;
        else
            b = b ^ *p;
    }

    if (a > b)
    {
        unsigned int temp = a;
        a = b;
        b = temp;
    }

    printf("Single numbers: %u %u\n", a, b);
}

void sortByBits(unsigned int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (unsigned int *p = arr; p < arr + n - 1 - i; p++)
        {
            int bits1 = countSetBits(*p);
            int bits2 = countSetBits(*(p + 1));

            if (bits1 > bits2 || (bits1 == bits2 && *p > *(p + 1)))
            {
                unsigned int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter size: ");

    if (scanf("%d", &n) != 1 || n < 2 || n % 2 != 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    unsigned int *arr = malloc(n * sizeof(unsigned int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements: ");

    for (unsigned int *p = arr; p < arr + n; p++)
    {
        if (scanf("%u", p) != 1)
        {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    findTwoSingle(arr, n);

    sortByBits(arr, n);

    printf("\nSorted array:\n");

    for (unsigned int *p = arr; p < arr + n; p++)
    {
        printf("%u -> ", *p);
        printBinary(*p);
        printf(" (%d set bits)\n", countSetBits(*p));
    }

    free(arr);

    return 0;
}
