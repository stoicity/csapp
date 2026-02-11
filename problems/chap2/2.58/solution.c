/* 
    Problem 2.58:
 
    Write a procedure is_little_endian that will return 1 when compiled and run
    on a little-endian machine, and will return 0 when compiled and run on a big-
    endian machine. This program should run on any machine, regardless of its word
    size.
*/

#include <stdio.h>

typedef unsigned char* byte_pointer;

int is_little_endian()
{
    unsigned int x = 1;
    byte_pointer p = (byte_pointer)&x;
    return (p[0] == 1);
}

int main()
{
    printf(is_little_endian() ? "little" : "big");
    return 0;
}