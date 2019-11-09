/**************************************
 *     program to resize BMPs
 *
 * author : Mohamed Abo Raia
 * on     : 29 / 10 / 2019
 *
 * *************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int string_to_int(char *string) ;



int main(int argc, char *argv[])
{

    int n ;     // the value that will use for resizing


    n = string_to_int(argv[1]) ;

    // Check the valid or not
    if (argc != 4)
    {
        return 1;
    }

    // check the value of first input it must be <= 100
    if ((n > 100) || (n <= 0))
    {
        return 2;
    }

    // open the input file
    FILE *input_file = fopen(argv[2], "r");
    // check if the exist
    if (input_file == NULL)
    {
        printf(" File Does not Exsit\n");
        return 3;
    }
    // open the output file
    FILE *output_file = fopen(argv[3], "w");
    // check the can be opened or not
    if (output_file == NULL)
    {
        printf(" File could not open\n");
        return 4;
    }

    // create a buffer to the bit map file header
    BITMAPFILEHEADER buffer_file_14 ;
    // create buffer for bit map info header
    BITMAPINFOHEADER buffer_info_40 ;

    // read the first 14 byte that represent the the file header
    fread(&buffer_file_14, sizeof(BITMAPFILEHEADER), 1, input_file);
    // read the next 40 byte the represent the info header
    fread(&buffer_info_40, sizeof(BITMAPINFOHEADER), 1, input_file);



    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (buffer_file_14.bfType != 0x4d42 || buffer_file_14.bfOffBits != 54 || buffer_info_40.biSize != 40 ||
        buffer_info_40.biBitCount != 24 || buffer_info_40.biCompression != 0)
    {
        fclose(output_file);
        fclose(input_file);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;

    }

    // determine number of padding in bytes for scanlines
    int padding2 = (4 - (buffer_info_40.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;



     int count22 = buffer_info_40.biWidth ;
    // change the value of the width
    buffer_info_40.biWidth *= n;
    // change the value of height
    buffer_info_40.biHeight *= n;

    // determine padding for scanlines
    int padding = (4 - (buffer_info_40.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // change the value of the image size
    buffer_info_40.biSizeImage = (buffer_info_40.biWidth * sizeof(RGBTRIPLE) +  padding) * abs(buffer_info_40.biHeight);

    // change the value of file size
    buffer_file_14.bfSize = buffer_info_40.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) ;

    // write outfile's BITMAPFILEHEADER
    fwrite(&buffer_file_14, sizeof(BITMAPFILEHEADER), 1, output_file);

    // write outfile's BITMAPINFOHEADER
    fwrite(&buffer_info_40, sizeof(BITMAPINFOHEADER), 1, output_file);


    // iterate over input_file's scanlines
    for (int i = 0, temp = abs(buffer_info_40.biHeight); i < (temp / n); i++)
    {
        // write the row n times
        for (int a = 0; a < n ; a++)
        {
            // iterate over input_file's pixels
            for (int j = 0; j < (buffer_info_40.biWidth / n); j++)
            {
                // allocate location for pixel
                RGBTRIPLE pixel_location ;

                // read pixel from the input file
                fread(&pixel_location, sizeof(RGBTRIPLE), 1, input_file);

                // write the value of pixel n times in the outputfile
                for (int m = 0; m < n; m++)
                {
                    // write pixel in the output file
                    fwrite(&pixel_location, sizeof(RGBTRIPLE), 1, output_file);
                }
            }

            // write the padding
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, output_file);
            }


            // Return pointer to the begining of the row
            fseek(input_file, -1 * count22 * 3, SEEK_CUR);
        }


        // return the pointer to the end of file
        fseek(input_file, count22 * 3, SEEK_CUR);
        // skip over padding, if any
        fseek(input_file, padding2, SEEK_CUR);



    }


    // close input file
    fclose(input_file);

    // close output file
    fclose(output_file);

    // success
    return 0;

}

// convert your string to integer value
int string_to_int(char  *string)
{
    int result ;          // hold the final integer value
    int string_length  ;
    int temp  ;            // hold the value of tens
    int count = 0 ;

    string_length =  strlen(string);

    // value of one location
    result = string[string_length - 1]  - 48;

    // calculate the value of other locations
    for (int j = string_length - 1; j > 0; j--)
    {
        temp  = 1;
        for (int i = 0; i < j; i++)
        {
            temp *= 10;
        }

        result += temp * (string[count] - 48);
        count++ ;

    }


    return result ;

}
