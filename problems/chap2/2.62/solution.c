#include <stdio.h>

unsigned int int_shifts_are_arithmetic()
{
    int w = sizeof(int) << 3;
    int val = (1 << w) - 1;

    return (val >> 1) == val;
}

int main()
{
    printf(int_shifts_are_arithmetic() ? "arith\n" : "logic\n");
    return 0;
}