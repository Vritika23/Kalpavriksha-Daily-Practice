# Day 1 (6 Nov) - Bits, pointers, loops

## Questions

1. [E] Write functions to set, clear, toggle and test bit n of an integer, and count the set bits of a number with a loop.
2. [M] Print Pascal's triangle for n rows using a single 1D array updated from right to left.
3. [M] Reverse an array in place with two pointers (no indexing), then rotate array by k using three reversals.
4. [M] Find the second largest and second smallest in one pass and return both through pointer parameters. Handle duplicates and arrays with fewer than two distinct values.
5. [H] Read N non-negative numbers into a dynamic array where every number appears twice except two numbers that appear only once. Find those two numbers using XOR (no extra array). Then sort the array by number of set bits (if same, smaller number first) using pointers and print each number with its binary form.

## Solutions

### Q1 - set, clear, toggle, test bit + count set bits

Approach:
- made a mask using 1 << n
- set = num | mask, clear = num & ~mask, toggle = num ^ mask, test = num & mask
- for counting set bits, check last bit with num & 1 and right shift till num is 0

#### Pseudocode
```
mask = 1 << n
set    -> num | mask
clear  -> num & ~mask
toggle -> num ^ mask
test   -> (num & mask) != 0

count = 0
while num > 0
    if num & 1 then count++
    num = num >> 1
```

### Q2 - Pascal's triangle

Approach:
- used only one array of size n (malloc)
- every row last element is 1, then arr[j] = arr[j] + arr[j-1]
- loop goes right to left because if i go left to right, arr[j-1] already gets changed for the new row and the answer becomes wrong

#### Pseudocode
```
arr = malloc(n)
for i = 0 to n-1
    arr[i] = 1
    for j = i-1 down to 1
        arr[j] = arr[j] + arr[j-1]
    print arr[0] to arr[i]
free(arr)
```

### Q3 - reverse and rotate array

Approach:
- reverse: start pointer at first, end pointer at last, swap and move both inside
- rotate: k = k % n, then reverse full array, reverse first k, reverse rest
- eg. 1 2 3 4 5 and k = 2
  - 5 4 3 2 1
  - 4 5 3 2 1
  - 4 5 1 2 3

#### Pseudocode
```
reverse(start, end)
    while start < end
        swap *start and *end
        start++, end--

rotate(arr, n, k)
    k = k % n
    if k == 0 return
    reverse(arr, arr+n-1)
    reverse(arr, arr+k-1)
    reverse(arr+k, arr+n-1)
```

### Q4 - second largest and second smallest

Approach:
- large and small both start from first element
- if number > large, then old large becomes second large
- else if number < large and > second large, update second large
- same thing for small side just opposite
- used strict < and > so duplicates dont get counted again
- found flag is to check if there are atleast 2 different values, otherwise print message
- answers are sent back using pointers (call by address)

#### Pseudocode
```
large = small = arr[0]
found = 0
for each x (from 2nd element)
    if x > large
        secLarge = large, large = x
    else if x < large and (found == 0 or x > secLarge)
        secLarge = x

    if x < small
        secSmall = small, small = x
    else if x > small and (found == 0 or x < secSmall)
        secSmall = x

    if x != arr[0] then found = 1
```

### Q5 - two single numbers + sort by set bits

Approach:
- xor of all numbers = a ^ b, because same numbers cancel (x ^ x = 0)
- a and b are different so atleast one bit is 1 in a ^ b, took lowest set bit using xor & (~xor + 1)
- divided numbers in 2 groups using that bit and xor each group, one gives a and other gives b
- if total xor is 0 then there are no two single numbers
- for sorting used bubble sort with pointers, first compare set bits, if same then compare number
- for binary, mask starts from highest set bit and goes till bit 0

#### Pseudocode
```
xor = 0
for each x: xor = xor ^ x
if xor == 0: print "No two single numbers"

bit = xor & (~xor + 1)
a = 0, b = 0
for each x
    if x & bit: a = a ^ x
    else: b = b ^ x

bubble sort:
    swap *p and *(p+1) if
    bits(*p) > bits(*(p+1)) or (bits same and *p > *(p+1))
```
