#include <assert.h>
#include <stdio.h>

int any_odd_one(unsigned x)
{
    return (x & 0x55555555) && 1;
}

int main()
{
    assert(any_odd_one(0x1));
    assert(any_odd_one(0x5));
    assert(any_odd_one(0x11));
    assert(any_odd_one(0x55));

    assert(!any_odd_one(0x0));
    assert(!any_odd_one(0x2));
    assert(!any_odd_one(0x22));
}