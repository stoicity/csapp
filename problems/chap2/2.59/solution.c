/* 
    Problem 2.59:

    Write a C expression that will yield a word consisting of the least significant byte of
    x and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210,
    this would give 0x765432EF.
*/

#include <stdio.h>

/*
    Expression: (x & 0xff) | (y & ~0xff)
*/

unsigned yield(unsigned x, unsigned y)
{
    return (x & 0xff) | (y & ~0xff);
}

int main()
{
    printf("0x%08x\n", yield(0x89ABCDEF, 0x76543210)); // --> For operands x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.
    return 0;
}
