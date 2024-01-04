#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int u1, u2, v = 3;
    int *p1;
    int *p2;
    u1 = 2 * (v + 5);
    p1 = &v;
    p2 = p1;
    *p2 = 5;
    p2 = &u1;
    u2 = 2*(*p1 + 5);
    *p2 = *p2 + 1;
    printf("\nu1=%d u2=%d v=%d", u1, u2, v);
    return (0);
}