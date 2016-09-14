#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    float change =0;
        do{
        printf("what's the change ? \n");
        change = GetFloat();
    }while (change<=0.0);
;
    
    /*transform change to int */
    
    int changed = (round(change *100 ));
    
    int quarters = (changed /25);
    int lq = (changed % 25 );
    int dimes = ( lq /10 );
    int ld = (lq % 10 );
    int nickels = (ld /5);
    int ln = ( ld % 5 );

    //printf("you need %i quarters \n",quarters);
    //printf("you need %i dimes \n",dimes);
    //printf("you need %i  nickels \n",nickels);
    //printf("you need %i penny \n\n",ln);
    
    int ncoins = quarters + dimes + nickels + ln;
    
    printf("%d\n",ncoins);
    
    return 0;
}


// for 6.67
// 26
// 1
// 1
// 2

