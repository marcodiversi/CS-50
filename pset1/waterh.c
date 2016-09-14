#include <cs50.h>
#include <stdio.h>

int main (void){
    int n;
    do {
    printf("What's the lenght of you shower in minutes? : \n");
    n = GetInt();
    }
    while (n<1);
    int bottles = (192 *n )/16;
    printf("For a shower of %i minutes\n",n);
    printf("It's like you are using %i bottles of water \n", bottles); 
}