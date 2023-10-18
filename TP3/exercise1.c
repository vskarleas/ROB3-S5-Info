#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int inverser_entier(int number)
{
    if (number == 0)
    {
        return 0;
    }

    if(number<0)
    {
        printf("%c", '-');
        number = -number;
    }

    int id, reversed;
    reversed = 0;
    id = number % 10; //Taking every single digit of the number
    reversed = reversed * 10 + id;


    printf("%d", reversed);
    return inverser_entier(number /= 10); // Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        printf("You need to pass the number as an argument to the program.\n");
        printf("Please TRY AGAIN \n");
        return -1;
    }
    printf("%s\n", argv[1]);

    int x;
    x = atoi(argv[1]);
    inverser_entier(x);

    return 0;
}