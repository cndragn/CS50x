#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();

    // as long as input is not empty
    if (s != NULL)
    {
        //print first letter in upper case
        printf("%c", toupper(s[0]));
        
        //interate over the charachters in s one at a time
        for (int i = 0, n = strlen(s); i < n ; i++)
        {
            
            //check if theres a space and print the next character
            if (isspace(s[i]))
            {
                i++;
                printf("%c", toupper(s[i]));
                //eprintf("Test %c\n", s[0]);
            }
           
        }
        printf("\n");
    }
}
