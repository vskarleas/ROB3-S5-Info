#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ENOUGH 256

/*Here you will find main functions used from the main programs of the different exercises*/

/*on définit une variable de type entier u’on l’affiche.*/
void affichage_n(int n)
{
    printf("n = %d\n", n);
}

/*Calcule le pgcd de deux nombres. On prend on condition que les
 arguments sont strictements positives (verification fait 
 avant l'appel de la fonction)*/
int calculer_pgcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b==0)
    {
        return a;
    }
    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        return calculer_pgcd(a-b, b);

    }
    else{
        return calculer_pgcd(a, b-a);
    }
}

/* Calcle le plus petit commun multiple où  deux entiers non nuls a et b est le plus petit entier strictement positif qui soit multiple de ces deux nombres*/
int calculer_pcmm(int a, int b)
{
    int inf,sup,pcmm;
     if (a<b)
        {
        inf=a;
        sup=b;
        } 
        else 
        {
        inf=b;
        sup=a;
        }
     
        pcmm=sup;
        while (pcmm%inf!=0)
        {
        pcmm=pcmm+sup;
        }
      
        return (pcmm);
}

/*Inverse un entier passe en argument*/
int inverser_entier(int number)
{
    int id, reversed;
    reversed = 0;

    while(number != 0)
    {
        /*% (the modulo operator) and stored in id*/
        id = number % 10; //Taking every single digit of the number
        reversed = reversed * 10 + id;
        number /= 10; // Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand
    }
    return reversed;
}

/*Un eautre manier à faire l'inversion du nombre qui passe par une transformation au chaine de caracter*/
int inverser_entier_v2(int number)
{
    char str[ENOUGH];
    sprintf(str, "%d", number);

    //variables initailisation
    int i, length, temp, reversed;  
    reversed = 0;

    length = strlen(str);
      
    for (i = 0; i < length/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str[i];  
        str[i] = str[length - i - 1];  
        str[length - i - 1] = temp;  
    }  

    for (i=0; i<length; i++) 
    {
        switch (str[i])
        {
            case '1':
                reversed = reversed * 10 + 1;
                break;
            case '2':
                reversed = reversed * 10 + 2;
                break;
            case '3':
                reversed = reversed * 10 + 3;
                break;
            case '4':
                reversed = reversed * 10 + 4;
                break;
            case '5':
                reversed = reversed * 10 + 5;
                break;
            case '6':
                reversed = reversed * 10 + 6;
                break;
            case '7':
                reversed = reversed * 10 + 7;
                break;
            case '8':
                reversed = reversed * 10 + 9;
                break;
            case '9':
                reversed = reversed * 10 + 9;
                break;
            case '0':
                reversed = reversed * 10 + 0;
                break;
        }
    }
    return reversed;

}

/*Un eautre manier à faire l'inversion du nombre sans perdre le zero selon la methode de chaine des caracters*/
char* inverser_entier_v3(int number, char * str)
{
    sprintf(str, "%d", number);

    //variables initailisation
    int i, length, temp;  

    length = strlen(str);
      
    for (i = 0; i < length/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str[i];  
        str[i] = str[length - i - 1];  
        str[length - i - 1] = temp;  
    }  

    return str;

}

/* Verifie si un nombre passé en argumeng est un multiple d'un autre nombre passé en argument*/
bool mutliple_verification(int number, int multiple_of)
{
    if ((number % multiple_of) == 0) //It's a multiple of "multiple_of"
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

/*Verifies if a specific number given as an argument ends to specific number given as an argument as well*/
bool verification_ends_to(int number, int ends_to)
{
    char str[ENOUGH];
    sprintf(str, "%d", number);

    int length_of = strlen(str);

    switch (str[length_of-1])
        {
            case '3':
                if (ends_to == 3)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case '7':
                if (ends_to == 7)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
}

// Pour trouver le nième nombre de Fibonacci
int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    }
 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*Gives a rundom number between two values specified as arguments*/
int random_number(int min, int max)
{
    int step = 10;
    int our_random;

    for (int i = 0; i < step; i++)
    {
        our_random = (rand() % (max - min + 1)) + min;
    }

    return our_random;
}

/* Une autre version pour un random number qui prend le maximum 
qu'on veut qu'il prend et pas aussi le minimum comme à la 
fonction declaré ci-dessus*/
int random_number_v2(int P)
{
    int num;
    num = (rand() % P) + 1;
    return num;
}

/* Trouve le nombre de chiffres 1 contenu dans un entier */
int number_of_specified_number(int number, char *string)
{
    sprintf(string, "%d", number);

    int count = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == '1')
        {
            count ++;
        }
    }

    return count;
}

/* alcule le terme de rangnde la suite de l'exercise 14 du TP1*/
int suite_exercise_14(int n)
{
    int a, b, u0, u1, res;

    a = 5;
    b = 10;
    u0 = 1;
    u1 = 2;

    if (n == 0)
    {
        return u0;
    }
    else if (n == 1)
    {
        return u1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            res = a * u1 + b * u0;
            u0 = u1;
            u1 = res;
        }
    }

 
    return res;
}

/* Cacule de fractions egyptiens */
void egyptian_fraction(int n, int d)
{
    //THE IDEA: For any number of the form ‘n/d’ and d > n, firstly we find the greatest possible unit fraction, then recur for the remaining part
    if( n == 0 && d == 0 )
    {
        return;
    }
    if (d % n == 0)
    {
        printf("1/%d\n", d/n);
        return;
    }
    if (n % d == 0)
    {
        printf("%d/%d\n", n, d);
        return;
    }
    if (n > d)
    {
        printf("%d/%d +",n, d);
        egyptian_fraction(n % d,d);
        return;
    }
    int x = d / n + 1;
    printf("1/%d + ", x);
    egyptian_fraction(n *x - d,d * x);
}

/*Responds if a number is premier or not with a bool */
bool premier_number_or_not (int number)
{
    for (int i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return false; //break ce fait une fois qu'on retourne une valeur
        }
    }
    return true;
}