#include <stdio.h>
#include <string.h>


void chaine_miroir(char *chaine)
{
    int lg = strlen(chaine);
    char miroir[lg];
    int j = 0;

    for (int i = lg-1; i >= 0; i--)
    {
        miroir[j] = chaine[i];        
        j++;
    } 
    miroir[lg] = '\0';
    printf("%s\n", miroir);

    return ;
}

int main()
{
    //QUESTION 1
    char chaine[] = "Hello";
    chaine_miroir(chaine);

    //QUESTION2 

}