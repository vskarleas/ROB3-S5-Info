#include <stdio.h>

void fct(int x)
{
    x = x + 2;
}
int main()
{
    int a = 3;
    fct(a);
    printf("\n a = %d\n", a);
    return (0);
}