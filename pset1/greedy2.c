#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float f;
    
    do {
    printf("How much changed is owed?\n");  
    f = GetFloat();                         //get a float that is positive
    }  while (f <= 0);
    
    int n = (round(f * 100));               //convert it to cents
    
    //printf("%d", n);
    
    int q = (n / 25);                       // get the number of quarters, pass the remainder to the dimes
    int remq = (n % 25);
    
    int d = (remq / 10);                    // get the number of dimes, pass the remainder to the nickels
    int remd = (remq % 10);
    
    int ni = (remd / 5);                    // get the number of nickels, the remainder is pennies
    int p = (remd % 5);
    
    int total = (q + d + ni + p);           // the total coins
    
    printf("%d\n", total);
}