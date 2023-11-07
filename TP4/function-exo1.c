#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int incremente(int *a, int *b , int i)
{
    /*
    More specifically a and b as parameters include the addresses of a and b that have been initialise din another section of the program
    (into tthe main in our case here). By doing **a and **b we can access the value of a and b addresses on the memory.

    When sending a and b as parameters to the function, actually we are sending the memort addreses by using the syntax &a and &b.
    This means that we point the original a and b on the memory to the function via a pointers treatment by taking their addreses and
    treating the addreses content directly on this specific memory location !!!
    */
    *a = *a + i;
    *b = *b + i;

    if (i == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
    
}