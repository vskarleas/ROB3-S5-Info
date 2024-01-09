#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {


int i ;
int* ptr= &i; //stroing the address of the variable i

int* kr;
kr = &i; //kr παίρνει την διεύθυνση του i
*kr = 10; //value διευθυνσης kr γινεται ισο με 10 δηλαδή η μεταβλητή i γίνεται ίση με 10

printf("%p\n", & *ptr);

printf("%p\n", kr); //αυτό κάνουμε συνήθως
printf("%p\n", &i);

printf("%d\n", *kr);
printf("%d\n", i);

char string[10];
printf("Input a string: ");
fgets(string, sizeof(string), stdin);

int ln = strlen (string);
if ((ln > 0) && (string[ln-1] == '\n'))
    string[ln-1] = '\0';

printf("I read this: %s\n", string);
if (strcmp(string, "hello") == 0)
{
    printf("The same\n");
}
else{
    printf("Not the same\n");
}
}


//ΠΡΟΣΟΧΗ: tab[i] = *(tab + i) και &tab[i] = tab + i SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS