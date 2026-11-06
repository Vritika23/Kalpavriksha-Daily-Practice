// 1. [E] Write functions to set, clear, toggle and test bit n of an integer, and count the set bits of a number with a loop. Pattern: bit masks. C focus: <<, &, |, ^, ~.

#include <stdio.h>

// make bit n as 1
int setBit(int num, int n)
{
    return num | (1 << n);
}

// make bit n as 0
int clearBit(int num, int n)
{
    return num & ~(1 << n);
}

// flip bit n (0 -> 1, 1 -> 0)
int toggleBit(int num, int n)
{
    return num ^ (1 << n);
}

// returns 1 if bit n is set otherwise 0
int testBit(int num, int n)
{
    if (num & (1 << n))
        return 1;
    return 0;
}

// counting set bits by checking last bit and shifting right
int countSetBits(unsigned int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1)
            count++;
        num = num >> 1;
    }
    return count;
}

void printBinary(int num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", testBit(num, i));
    }
}

int main()
{
    int num, n;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter bit position (0 to 30): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 30)
    {
        printf("Invalid bit position\n");
        return 1;
    }

    printf("\nNumber      : %d (", num);
    printBinary(num);
    printf(")\n");

    int res = setBit(num, n);
    printf("After set   : %d (", res);
    printBinary(res);
    printf(")\n");

    res = clearBit(num, n);
    printf("After clear : %d (", res);
    printBinary(res);
    printf(")\n");

    res = toggleBit(num, n);
    printf("After toggle: %d (", res);
    printBinary(res);
    printf(")\n");

    if (testBit(num, n))
        printf("Bit %d is SET\n", n);
    else
        printf("Bit %d is NOT set\n", n);

    printf("Number of set bits in %d = %d\n", num, countSetBits((unsigned int)num));

    return 0;
}
