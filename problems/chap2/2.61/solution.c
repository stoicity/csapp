/*
    Problem 2.61:

    Write C expressions that evaluate to 1 when the following conditions are true and
    to 0 when they are false. Assume x is of type int.
        A. Any bit of x equals 1.
        B. Any bit of x equals 0.
        C. Any bit in the least significant byte of x equals 1.
        D. Any bit in the most significant byte of x equals 0.

    Your code should follow the bit-level integer coding rules (page 164), with the
    additional restriction that you may not use equality (==) or inequality (!=) tests
*/

#include <stdio.h>

// A. Any bit of x equals 1.
unsigned any_bit_1(int x)
{
    return x && 1;
}

// B. Any bit of x equals 0.
unsigned any_bit_0(int x)
{
    return ~(x ^ 0) && 1;
}

// C. Any bit in the least significant byte of x equals 1.
unsigned any_bit_lsb_1(int x)
{
    return (x & 0xFF) && 1;
}

// D. Any bit in the most significant byte of x equals 0.
unsigned any_bit_msb_0(int x)
{
    int shift_val = (sizeof(int)-1) << 3;
    int msb = (x >> shift_val) & 0xFF;
    return ~(msb ^ 0) && 1;
}


int main()
{
    printf("Test A (any_bit_1):\n");
    printf("* 0x%08x -> %d\n", 0x0, any_bit_1(0x0));
    printf("* 0x%08x -> %d\n", 0x97, any_bit_1(0x97));
    printf("* 0x%08x -> %d\n", 0xFFFFFFFF, any_bit_1(0xFFFFFFFF));

    printf("Test B (any_bit_0):\n");
    printf("* 0x%08x -> %d\n", 0x0, any_bit_0(0x0));
    printf("* 0x%08x -> %d\n", 0x97, any_bit_0(0x97));
    printf("* 0x%08x -> %d\n", 0xFFFFFFFF, any_bit_0(0xFFFFFFFF));

    printf("Test C (any_bit_lsb_1):\n");
    printf("* 0x%08x -> %d\n", 0x0, any_bit_lsb_1(0x0));
    printf("* 0x%08x -> %d\n", 0xFF00, any_bit_lsb_1(0xFF00));
    printf("* 0x%08x -> %d\n", 0x00FF, any_bit_lsb_1(0x00FF));
    printf("* 0x%08x -> %d\n", 0x97, any_bit_lsb_1(0x97));
    printf("* 0x%08x -> %d\n", 0xFFFFFFFF, any_bit_lsb_1(0xFFFFFFFF));

    printf("Test D (any_bit_msb_0):\n");
    printf("* 0x%08x -> %d\n", 0x0, any_bit_msb_0(0x0));
    printf("* 0x%08x -> %d\n", 0xFF000000, any_bit_msb_0(0xFF000000));
    printf("* 0x%08x -> %d\n", 0x000000FF, any_bit_msb_0(0x000000FF));
    printf("* 0x%08x -> %d\n", 0x97000000, any_bit_msb_0(0x97000000));
    printf("* 0x%08x -> %d\n", 0x97FFFFFF, any_bit_msb_0(0x97FFFFFF));
    printf("* 0x%08x -> %d\n", 0xFFFFFFFF, any_bit_msb_0(0xFFFFFFFF));

    return 0;
}