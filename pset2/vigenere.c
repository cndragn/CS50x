#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// get key
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //store key as string and get length
        string k = argv[1];
        int kl = strlen(k);
        
        //printf("key: %s\n", k);
        //printf("length: %i\n", kl);
        
        //check if key is a word
        for (int j = 0; j < kl; j++)
        {
            if (!isalpha(k[j]))
            {
                printf("Usage: %s\n", argv[0]);
                return 1; 
            }
        }
        
        //get plain text
        printf("plaintext: ");
        string p = get_string();
        //printf("print: %s\n", p);
                
        //encipher plain text
        //iterate over the characters in plain text one character at a time
        
        printf("ciphertext: ");
         
        for (int i = 0, j = 0, n = strlen(p); i < n; i++) {
            
            //if alphabetic apply key
            if (isalpha(p[i])) 
            {
                //convert key to lower and alpha index
                //[j] = tolower(k[j]);
               //int ak = k[j] - 97;
                //int kc = k[j % kl];
                
                int kc = tolower(k[j % kl]) - 'a';
                
                //printf("%i",ak);
                //printf(" - %c",k[j]);
                
                //printf("%i",kc);
                
                if (isupper(p[i]))
                {
                    // c = (p + k) % 26 - convert to alpha index
                    int a = p[i] - 65;
                    int c = (a + kc)%26;
                    
                    printf("%c", 'A' + c);
                    //printf(" - %i ", c);
                    //printf(" - %c\n", (p[i]));
                    
                    j++;
                }
                else if (islower(p[i]))
                {
                    int a = p[i] - 97;
                    int c = (a + kc)%26;
                    printf("%c", 'a' + c);
                    
                    j++;
                }
            }
            else
            
            // else print number or symbol as is
            {
                printf("%c", p[i]);
            }
            
        }

         
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;   
    }

}
