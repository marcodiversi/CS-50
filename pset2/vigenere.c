#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char enter, int key);

int main(int argc, string argv[]) {

    string keyword = "";
    string user_text = "";
    int user_text_length;
    int key_count = 0;

        if(argc != 2)
        {
            printf("You didn't enter the correct number of keywords.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    printf("Your input contains illegal characters.\n");
                    return 1;
                }
                else
                {

                    keyword = argv[1];
                }
            }
        }

    int keylength = strlen(keyword);
    int keycodes[keylength];

    for(int i = 0; i < keylength;i++)
    {
        keycodes[i] = toupper(keyword[i]) - 65;
    }


    user_text = GetString();
    user_text_length = strlen(user_text);

    for (int i = 0; i < user_text_length; i++)
    {
        if(!isalpha(user_text[i]))
        {
            printf("%c", user_text[i]);
        }

        else
        {
            printf("%c", caesar(user_text[i], keycodes[key_count]));

            if(key_count < keylength - 1)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }

    printf("\n");
    return 0;
}


char caesar(char enter, int key)
{
    if(islower(enter))
    {
        return ((((enter - 97)+key)%26)+97);
    }
    else
    {
        return ((((enter - 65)  +key)%26)+65);
    }
}