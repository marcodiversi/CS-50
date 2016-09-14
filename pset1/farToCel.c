#include <cs50.h>
#include <stdio.h>

int main (void){
    printf("give me the temperature in fareneith: \n");
    float f = GetFloat();
    float c = (f-32.0)*5.0/9.0;
    printf("the temperature of %.2f degrees fareneith in celsius is %.2f \n",f,c);
}