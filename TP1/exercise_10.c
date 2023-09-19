#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* There is also another version for the same exercise
under the name exercise_10_v2 (calls a function instead
of having the code on the main program). Check it out!*/
int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    }

    int a, n1, n2, temp;

    bool repeat = true;
    while (repeat)
    {
        printf("=====================\n");
        printf("\n");

        printf("Give a postive number : ");
        scanf("%d", &a);

        if ((a >= 0))
        {
            //main program below
            repeat = false;

            n1 = 0;
            n2 = 1;

            if (a > 0)
            {
                for (int i = 1; i<=a-1; i++)
                {
                    temp = n1 + n2;
                    n1 = n2;
                    n2 = temp;
                }
                printf("F(n) = %d\n", temp);
            }
            else if ((a==0) || (a==1))
            {
                printf("F(n) = 1\n");
            }

        }
        else
        {
            printf("=====================\n");
            printf("We need one positive number. Try again!\n");
        }
    }
    

    return 0;
}