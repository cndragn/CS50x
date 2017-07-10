#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
    do 
    {
        printf("Height: ");
        n = get_int();
    }
    while ( n < 0 || n > 23); 
    
   for (int i= n; i > 0 ; i--) {
       
        for (int s= 2; s <= i; s++)
       
      printf(" ");
       
       for (int p=n + 1; p >= i; p--)
       
      printf("#");
      printf("\n");

       }

   
}
