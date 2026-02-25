/*
    Problem 2.70:
    Write code for the function with the following prototype:

    int fits_bits(int x, int n);

    Your function should follow the bit-level integer coding rules (page 164).
*/

/*
    * Return 1 when x can be represented as an n-bit, 2’s-complement
    * number; 0 otherwise
    * Assume 1 <= n <= w
*/
#include <assert.h>

int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int msk = (unsigned)-1 >> (w - n);

    return !(~msk & x);
}

int main()
{
    assert(fits_bits(0x1, 1));
    assert(!fits_bits(0x3, 1));
    assert(fits_bits(0x3, 2));
    assert(fits_bits(0xF, 4));
    assert(!fits_bits(0xF, 3));
    assert(fits_bits(-1, sizeof(int) << 3));
    assert(!fits_bits(-1, 1));
    return 0;
}