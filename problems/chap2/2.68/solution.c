/*
    Write code for a function with the following prototype:

    Mask with least signficant n bits set to 1
    Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
    Assume 1 <= n <= w

    int lower_one_mask(int n);

    Your function should follow the bit-level integer coding rules (page 164). Be
    careful of the case n = w.
*/
#include <assert.h>


int lower_one_mask(int n)
{
    int w = sizeof(int) << 3;

    return (unsigned)-1 >> (w - n);
}

// int lower_one_mask(int n)
// {
//     /* Left shilft amount */
//     int shl = n - 1;

//     int msk = (1 << shl) - 1;
//     return (msk << 1) | 1;
// }

int main()
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(1) == 0x1);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}