#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        printf("Minutes: ");
        n = get_int();
        
        printf("Bottles: %i\n", n * 12);
        
    }
    while ( n < 0);
    
    
    
}


