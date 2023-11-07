#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
int i ;
int *ptr= &i; //stroing the address of the variable i

int *kr;
kr = &i; //kr παίρνει την διεύθυνση του i
*kr = 10; //value διευθυνσης kr γινεται ισο με 10 δηλαδή η μεταβλητή i γίνεται ίση με 10

printf("%d\n", *ptr);

printf("%p\n", kr); //αυτό κάνουμε συνήθως
printf("%p\n", &i);

printf("%d\n", i);
printf("%d\n", *kr);
}