   
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"


const int HAY_MAX = 65536;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return 1;
    }


    int needle = atoi(argv[1]);


    int size;
    int haystack[HAY_MAX];
    for (size = 0; size < HAY_MAX; size++)
    {
 
        printf("\nhaystack[%i] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
            break;
        

        haystack[size] = straw;
    }
    printf("\n");

    sort(haystack, size);


    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
}
