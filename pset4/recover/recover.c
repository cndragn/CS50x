#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//data type
typedef uint8_t  BYTE;

//buffer size
#define BUFFERSIZE 512

//JFIFHEAD
typedef struct _JFIFHeader
{
  BYTE SOI[2];          /* 00h  Start of Image Marker     */
  BYTE APP0[2];         /* 02h  Application Use Marker    */
  BYTE Length[2];       /* 04h  Length of APP0 Field      */
  BYTE Identifier[5];   /* 06h  "JFIF" (zero terminated) Id String */
  BYTE Version[2];      /* 07h  JFIF Format Revision      */
  BYTE Units;           /* 09h  Units used for Resolution */
  BYTE Xdensity[2];     /* 0Ah  Horizontal Resolution     */
  BYTE Ydensity[2];     /* 0Ch  Vertical Resolution       */
  BYTE XThumbnail;      /* 0Eh  Horizontal Pixel Count    */
  BYTE YThumbnail;      /* 0Fh  Vertical Pixel Count      */
} JFIFHEAD;

int main(int argc, char *argv[]) 
{
    //accept only one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    //filename to recover
    char *infile = argv[1];
    
    //open input file
    FILE *inptr = fopen(infile, "r");
    
    //declare outfile file
    FILE *newjpg;
    
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s. \n", infile);
        return 2;
    }
    
    //create buffer
    unsigned char buffer[BUFFERSIZE] = {};
    
    //counter for filenames
    int counter = 0; // to increment file names
    int writing = 0; //false, not currently writing
    
    //for length of card, read 512 bytes into a buffer
    //JFIFHEAD buffer;
    while(fread(buffer, 1, BUFFERSIZE, inptr) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            
            if(writing == 1) {
                //printf("start a new file! %i", counter);
                fclose(newjpg);
            }
            
            //MAKE AND OPEN NEW JPG
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
            newjpg = fopen(filename,"a");
            counter++;
            writing = 1;
            
            //WRITE 512 BYTES
            fwrite(buffer, 1, BUFFERSIZE, newjpg);
            //MOVE ON TO NEXT BLOCK
        }
        else
        //keep writing to curently open jpg
        {
            if (newjpg != NULL)
            fwrite(buffer, 1, BUFFERSIZE, newjpg);
        }
        
    }
    
    fclose(inptr);
    fclose(newjpg);
    
   return 0;
}
