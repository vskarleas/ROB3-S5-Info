#include <stdio.h>

int fct(int *x)
{
    int a=2;
    printf( "\n 2 ) a=%d , x=%d " , a , *x ) ; 
    *x += a;
    printf( "\n 3 ) a=%d , x=%d " , a , *x ) ; 
    return (*x); 
}
int main()
{
    int a=0, x=4;
    printf( "\n 1 ) a=%d , x=%d " , a , x ) ; 
    a = fct(&x);
    printf( "\n 4 ) a=%d , x=%d " , a , x ) ; 
    return (0);
}