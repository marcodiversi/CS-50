#include <cs50.h>
#include <stdio.h>

int main (void)
{
        printf("What's the lenght of you shower in minutes? : \n");
        int x = GetInt();
        int bottles = (192 * x ) / 16;
        printf("For a shower of %i minutes \n",x);
        printf("It's like you are using %i bottles of water \n", bottles);
}