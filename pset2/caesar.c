#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
                        
int main(int argc, string argv[])
{
    int key = 0;
    if (argc != 2)
    {
        printf("put the key into the command line \n\n");
        return 1;
    }else{
         key = atoi (argv[1]);
    }

string input = GetString();
int inputLength = strlen(input);

for (int i = 0; i<inputLength; i++)
{
    
    if (isalpha(input[i]))
    {
        if (islower(input[i])) 
        {
            printf("%c", ((((input[i] - 97)+key)%26)+97));             //printf("%c", ((((text[i] - 97)+key)%26)+97));
        }
        else 
        {
            printf("%c", ((((input[i]- 65 )+key)%26)+65));            //printf("%c", ((((text[i] - 65)+key)%26)+65));
    }
    }
    else   
    {
            printf("%c", input[i]);
    }
    }
  printf("\n");
return 0; 
}

/*

for (int i = 0, n = strlen(p); i < n; i++)
{
    printf("%c", p[i]);
}  


ci = (pi + k) % 26
*/

