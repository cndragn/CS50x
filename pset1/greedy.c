#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)


{
    float n;
    int i;
    
    do 
    {
        printf("O hai! How much change is owed?\n");
        n = get_float();
    }
    while ( n < 0 ); 
    
    n = roundf(n * 100);
    i = 0;
    
    
     while (n >= 25) {
        n = n - 25;
        i = i + 1;
        
    };
     while (n >= 10) {
        n = n - 10;
        i = i + 1;
        
    };
     while (n >= 5) {
        n = n - 5;
        i = i + 1;
        
    };
    while (n >= 1) {
        n = n - 1;
        i = i + 1;
        
    };
    
    
    printf("%i\n", i);
   
}
