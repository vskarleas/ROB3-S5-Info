#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nbDeChiffre(int number)
{
    int counter = 0;
    int temp_number = number;
    while (temp_number != 0)
    {
        counter++;

        temp_number /= 10;
    }

    return counter;
}

int extraitNombre(int x, int n, int lg)
{
    if (x < 0)
    {
        return -100;
    }

    int length = nbDeChiffre(x);

    int len_test = length - n;
    if (len_test >= 0)
    {
        if (len_test < lg)
        {
            return -1;
        }
        else
        {
            // programs main logic goes here
            char numberStr[512];
            sprintf(numberStr, "%d", x); // itoa(x, numberStr, 10) HERE
            numberStr[len_test] = '\0';  // changed the string of which we are going to take the final number out of it
            int len_str = strlen(numberStr);

            // finals string initialisation
            char final_numberStr[512];
            int counter = 0;

            for (int i = len_str - lg; i <= len_str; i++)
            {
                final_numberStr[counter] = numberStr[i];
                counter ++;
            }

            int final_number = atoi(final_numberStr);

            return final_number;
        }
    }
    else
    {
        return -1;
    }
}

int estPair(int number)
{
    int x = nbDeChiffre(number);

    if (x % 2 == 0)
    {
        // is even number
        return 1;
    }
    else
    {
        // is odd number
        return 0;
    }
}

int sommeDesChiffres(int number)
{
    int temp_number = number;
    int sum = 0;

    while (temp_number != 0)
    {
        sum += temp_number % 10;

        temp_number /= 10; // temp_number = temp_number / 10;
    }

    return sum;
}

bool estCouicable(int number)
{
    int pair = estPair(number);
    if (pair == 1)
    {
                // logic of Couicable
        int length = nbDeChiffre(number);
        int index = length / 2;

        int res_1 = extraitNombre(number, index, index);
        res_1 = sommeDesChiffres(res_1);

        int res_2 = extraitNombre(number, 0, index);
        res_2 = sommeDesChiffres(res_2);

        if (res_2 == res_1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        return false;
    }
}

// MAIN PRGRAM
int main(int argc, char **argv)
{
    bool repeater = true;
    int x, n, lg, res;


    printf("=================== Test 1 ==================\n");
    printf("=============================================\n");
    printf("\n");
    printf("Give a number : ");
    scanf("%d", &x);
    res = nbDeChiffre(x);
    printf("The number %d has %d digit/s \n\n", x, res);
    

    printf("=================== Test 2 ==================\n");
    printf("=============================================\n");

    while (repeater)
    {
        printf("\n");
        printf("Give a positive number : ");
        scanf("%d", &x);
        printf("\n");
        printf("Set the n-ieme number : ");
        scanf("%d", &n);
        printf("\n");
        printf("Set the length of your desired number : ");
        scanf("%d", &lg);
        printf("\n");

            res = extraitNombre(x, n, lg);

        if (res != -100)
        {
            repeater = false;
        }
        if (x < 0)
        {
            printf("WE NEED A POSITIVE NUMBER. TRY AGAIN \n");
        }
    }

    printf("Your result: %d\n\n", res);
    

    printf("=================== Test 3 ==================\n");
    printf("=============================================\n");
    printf("\n");
    printf("Give a number : ");
    scanf("%d", &x);
    printf("\n");
    res =  estPair(x);
    if (res == 0)
    {
        printf("The number of digits of %d is an ODD number.\n", x);
    }
    else
    {
        printf("The number of digits of %d is an EVEN number.\n\n", x);
    }

    

    printf("=================== Test 4 ==================\n");
    printf("=============================================\n");
    printf("\n");
    printf("Give a number : ");
    scanf("%d", &x);
    printf("\n");
    res =  sommeDesChiffres(x);
    printf("Somme of number %d is : %d\n\n", x, res);

    printf("=================== Test 5 ==================\n");
    printf("=============================================\n");
    printf("\n");
    printf("Give a number : ");
    scanf("%d", &x);
    printf("\n");
    bool response = estCouicable(x);
    if (response == true)
    {
        printf("%d is Couicable\n", x);
    }
    else
    {
        printf("%d is not Couicable\n", x);
    }


    


    return 0;
}