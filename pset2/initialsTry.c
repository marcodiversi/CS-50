#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string input;
    input = GetString();  //Marco Diversi
    
    int inputLength;
    inputLength = strlen(input);
    
    for (int i = 0 , i<inputlength, ++i)
    {
        if (inputLength[i] == ' ')
        {
            printf("%c", input[0]);
        }
    }
    
}

