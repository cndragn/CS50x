/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int n; // resize by size

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    
    //define n and make it an integer
   n = atoi(argv[1]);
    
    if (n < 1 || n > 100) {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    //BITMAPFILEHEADER for resize
    BITMAPFILEHEADER newBf;
    newBf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    //BITMAPINFOHEADER for resize
    BITMAPINFOHEADER newBi;
    newBi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //height and width times n value to enlarge by
   newBi.biWidth = bi.biWidth * n;
   newBi.biHeight = bi.biHeight * n;
   
   // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //padding for new height / width
    int newPadding = (4 - (newBi.biWidth * sizeof(RGBTRIPLE)) % 4) %4;
   
  //new file size 
   newBf.bfSize = 54 + (newBi.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(newBi.biHeight);
   newBi.biSizeImage = newBf.bfSize - 54;
    

    // write outfile's BITMAPFILEHEADER
    fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
    
        //copy each row n times
        int rowntimes = 0;
        
        while (rowntimes < n)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                //printf("j is %i and bi.biWidth is %i\n", j, bi.biWidth);
                
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                //For Resize - print each pixel n times
                int pcounter = 0;
                
                //repeat til done copyingng n times
                while (pcounter < n) 
                {
                
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    pcounter++;
                
                }
                
                
            }
            // skip over padding, if any
            
            
            // then add it back (to demonstrate how)
            for (int k = 0; k < newPadding; k++)

            fputc(0x00, outptr);
            
            if (rowntimes < (n - 1))
            fseek(inptr, -(long int)(bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
            
            rowntimes++;
        }
        
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
