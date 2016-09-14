#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string input;
    input = GetString();
    
    int inputLenght;
    inputLenght = strlen(input);
    
    printf("%c", toupper(input[0]));
    
    for (int i = 0; i<inputLenght;++i)
    {
        if (input[i-1] == ' '){
            printf("%c", toupper(input[i]));
        }
    }

    printf("\n");
}

