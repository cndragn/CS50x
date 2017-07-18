#include <stdio.h>

int main(int argc, char *argv[]) 
{
    //accept only one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    //remember filename to recover
    char *infile = argv[1];
    
    //open input file
    FILE *inptr = fopen(infile, "r");
    
    if(inptr == NULL)
    {
        fprintf(stderr, "Could note open %s. \n", infile);
        return 2;
    }
}
