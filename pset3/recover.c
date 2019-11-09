#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool check_if_JPEG(unsigned char *block);

int main(int argc, char *argv[])
{

    FILE *input ;
    unsigned char block[512] ;
    int num_of_elements ;
    int count = -1;

    // check if the number of number of arguments is right
    if (argc != 2)
    {
        fprintf(stderr, "enter the right number of arguments\n");
        return 1;
    }

    // open the input file
    input = fopen(argv[1], "r");

    // check if the file could be opened
    if (input == NULL)
    {
        fprintf(stderr, "file could not be opened\n");
        return 2;
    }

    // read the first block
    num_of_elements = fread(&block, 1, 512, input);


    // create a string for name of file
    char filename[8]  ;


    // create file to pointer
    FILE  *img  = NULL;



    // read until you found  a block smaller then 512 bytes which is EOF
    while (num_of_elements == 512)
    {

        // if you found the start of JPEG
        if (check_if_JPEG(block) == true)
        {
            //fclose(img);
            count++;

            // create new file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");


        }
        // start writing if you found a JPEG
        if (count > -1)
        {
            // write to output file
            fwrite(&block, 1, 512, img);

        }

        // read the next block
        num_of_elements = fread(&block, 1, 512, input);

    }

    // close files
    for (int i = 0; i <= count; i++)
    {
        sprintf(filename, "%03i.jpg", i);
        img = fopen(filename, "r");
        fclose(img);
    }




    // success
    return 0;

}

// function to check the beginning of JPEG
bool check_if_JPEG(unsigned char *block)
{
    if ((block[0] == 0xff) && (block[1] == 0xd8) && (block[2] == 0xff) && ((block[3] & 0xf0) == 0xe0))
    {
        return true;
    }
    else
    {
        return false;
    }

}





