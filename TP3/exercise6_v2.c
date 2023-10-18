#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//version optimized in comparison to v1
void sous_chaine(char *s1, char *s2)
{
    int len = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    bool ok = true;

    while(ok)
    {
        char *res = strstr(&s1[i], s2); //finds the first occurrence of the substring needle in the string haystack

        /* in case that we don't find the program, we retrun directly */
        if (res == NULL)
        {
            return;
        }

        //found the s2 logic
        int locator = res - s1;

        for ( int j = locator; j <= len - len2; j++)
        {
            //jump to the section after the sub string
            s1[j] = s1[j + len2];
        }

        len = len - len2; 
        
        //saw s2 last location
        i = locator; 
        if (i >= len)
        {
            /* Means that we have bypased our length of the original string and now it is time to stop the program  */
            ok = false;
        }
    }

}



int main(int argc, char **argv)
{
    printf("Before: \n");
    char s1[200] = "Hello world! This is  full of opportunities. Welcome to the world !";
    printf("%s \n\n", s1);

    printf("The phrase to be removed: \n");

    char s2[100] = "world";
    printf("%s \n\n", s2);
    printf("After: \n");

    sous_chaine(s1, s2); //function is modofying s1
    
    //printing is done in the function
    printf("%s\n", s1);
    return 0;
}