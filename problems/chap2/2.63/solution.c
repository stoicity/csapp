#include <assert.h>
#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    if (k == 0)
        return x;

    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) * 8;

    return xsra & ((1 << (w-k)) - 1);  
}

int sra(int x, int k)
{
    if (k == 0)
        return x;

    /* Perform shitf logically */
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) * 8;

    /* Get most significant bit */
    int msb = x & (1 << (w-1));

    /* Generate 1..1 pattern from word size */
    int pattern = (1L << w) - 1;
    return msb ? xsrl | (pattern << (w-k)) : xsrl; 
}

int main()
{
    printf("srl:\n");
    for (int k=0; k < sizeof(int)*8; k++)
    {
        printf("0x%08x >> %d = 0x%08x\n", 0xFFFFFFFF, k, srl(0xFFFFFFFF, k));
        assert(srl(0xFFFFFFFF, k) == (unsigned)0xFFFFFFFF >> k);
    }

    printf("sra (0x80000000):\n");
    for (int k=0; k < sizeof(int)*8; k++)
    {
        printf("0x%08x >> %d = 0x%08x\n", 0x80000000, k, sra(0x80000000, k));
        assert(sra(0x80000000, k) == (int)0x80000000 >> k);
    }

    printf("sra (0x4FFFFFFF):\n");
    for (int k=0; k < sizeof(int)*8; k++)
    {
        printf("0x%08x >> %d = 0x%08x\n", 0x4FFFFFFF, k, sra(0x4FFFFFFF, k));
        assert(sra(0x4FFFFFFF, k) == (int)0x4FFFFFFF >> k);
    }
    return 0;
}