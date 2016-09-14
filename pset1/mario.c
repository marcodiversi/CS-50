#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	
	int pyramid_height;
	do 
	{
	    printf ("give me the pyramid heigh : \n");
	    pyramid_height = GetInt();
	}
	while (pyramid_height < 0 || pyramid_height > 23);
	
	for (int i = 0; i < pyramid_height; i++ )
	{ 
	
	for (int s = 0; s < pyramid_height- i -1; s++)
	{
	    printf(" ");
	} 
	for (int h= 0; h < i+2 ; h++){
	        printf("#");
	
	}
	printf("\n");
	}
	return 0;
}


// i +2  - hashes     
// -i - 1    - spaces 
// per pyramid_height = 8   i = 0
// s = 8 -0 -1 =7
// h = 0 + 2 = 2



//......##
//.....###
//....####
//...#####
//..######
//.#######

// i < pyramid-height