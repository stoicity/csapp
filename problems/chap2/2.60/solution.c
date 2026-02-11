/* 
    Problem 2.60:
 
    Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1
    (most significant). Write code for the following C function, which will return an
    unsigned value in which byte i of argument x has been replaced by byte b:
    unsigned replace_byte (unsigned x, int i, unsigned char b);

    Here are some examples showing how the function should work:
    replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
    replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

#include <assert.h>
#include <stdio.h>

typedef unsigned char* byte_pointer;

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    assert(i < sizeof(x));
    return (x & ~(0xff << 8*i)) | (b << 8*i);
}

/*
2nd solution : only work on little-endian machine (reverse for big-endian)

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    assert(i < sizeof(x));
    byte_pointer p = (byte_pointer)&x;
    p[i] = b;
    return x;
}
*/

int main()
{
    printf("0x%08x\n", replace_byte(0x12345678, 0, 0xAB)); // --> 0x123456AB
    printf("0x%08x\n", replace_byte(0x12345678, 1, 0xAB)); // --> 0x123456AB
    printf("0x%08x\n", replace_byte(0x12345678, 2, 0xAB)); // --> 0x12AB5678
    printf("0x%08x\n", replace_byte(0x12345678, 3, 0xAB)); // --> 0x12AB5678
    return 0;
}