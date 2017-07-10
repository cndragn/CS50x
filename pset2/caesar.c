#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// get key
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //convert argv to integer
        string num = argv[1];
        int k = atoi(num);
        //printf("%i\n", k);
        
        //get plain text
        printf("plaintext: ");
        string p = get_string();
        //printf("%s\n", p);
        
        //encipher plain text
        //iterate over the characters in plain text one character at a time
        
         printf("ciphertext: ");
         
        for (int i = 0, n = strlen(p); i < n; i++) {
            
            //if alphabetic apply key
            if (isalpha(p[i])) 
            
            {
                if (isupper(p[i]))
                {
                    // c = (p + k) % 26 - convert to alpha index
                    int a = p[i] - 65;
                    int c = (a + k)%26;
                    //printf("%i ", c);
                    printf("%c", 'A' + c);
                    //printf(" - %c\n", (p[i]));
                }
                else if (islower(p[i]))
                {
                    int a = p[i] - 97;
                    int c = (a + k)%26;
                    printf("%c", 'a' + c);
                }
            }
            else
            
            // else print number or symbol as is
            {
                printf("%c", p[i]);
            }
            
        }
        printf("\n");
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    return 0;

}
