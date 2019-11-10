/*************************
 *      crack program
 * author : Mohamed Abo Raia
 * on : 27 / 10 / 2019
 *  
 * This program will crack passwords consists of one or two or three or five characters
 * the program works on lowercase characters only .
 *
 * The program will take a hash and compare it with a generated hash from cyrpt function 
 * using one or two or three or five characters words and loop until he found the right password
 *
 * The program accept one command line argument only which is the hash unless he will generate an error message .
 *  
 **************************/

#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void  crack(char *hash);

int main(int argc, char *argv[])
{
   
    // Check the input is valid or not
    if (argc != 2)
    {
        printf("Usage: %s hash\n", argv[0]); 
        return 1;
    }
    
    // crack and print the password
    crack(argv[1]);
    
	// success
    return 0;
}

// Crack function 
void crack(char *hash)
{
    char arr1[2] = {'\0', '\0'};                                      // one letter word
    char arr2[3] = {'\0', '\0', '\0'};                                // two letters word
    char arr3[4] = {'\0', '\0', '\0', '\0'};                          // three leters word
    char arr4[5] = {'\0', '\0', '\0', '\0', '\0'};                    // four letters word
    char arr5[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};              // five letters word  
    char *hash2 ;
    char salt[3] ;
    int x = 1 ;


    // Extacting the salt number 
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    

    
    

    // using srand function to make rand generate random numbers
    srand(time(NULL)) ;

    // loop untile you find a match
    while (1)
    {
        // create a one letter word
        for (int i = 0; i < 1; i++)
        {
            // changing lower case letters
            arr1[i] = rand() % 26 + 'a';
        }
        // generate new hash
        hash2 = crypt(arr1, salt);
        // compare the two hashes
        x = strcmp(hash, hash2);
        // if you found your word stop
        if (x == 0)
        {
            printf("%s\n", arr1);
            break;
        }

        // create a two letter word
        for (int i = 0; i < 2; i++)
        {
            // changing lower case letters
            arr2[i] = rand() % 26 + 'a';
        }
        // generate new hash
        hash2 = crypt(arr2, salt);
        // compare the two hashes
        x = strcmp(hash, hash2);
        // if you found your word stop
        if (x == 0)
        {
            printf("%s\n", arr2);
            break;
        }

        // create a three letter word
        for (int i = 0; i < 3; i++)
        {
            // changing lower case letters
            arr3[i] = rand() % 26 + 'a';
        }
        // generate new hash
        hash2 = crypt(arr3, salt);
        // compare the two hashes
        x = strcmp(hash, hash2);
        // if you found your word stop
        if (x == 0)
        {
            printf("%s\n", arr3);
            break;
        }

        // create a four letter word
        for (int i = 0; i < 4; i++)
        {
            // changing lower case letters
            arr4[i] = rand() % 26 + 'a';
        }
        // generate new hash
        hash2 = crypt(arr4, salt);
        // compare the two hashes
        x = strcmp(hash, hash2);
        // if you found your word stop
        if (x == 0)
        {
            printf("%s\n", arr4);
            break;
        }

        // create a five letter word
        for (int i = 0; i < 5; i++)
        {
            // changing lower case letters
            arr5[i] = rand() % 26 + 'a';
        }
        // generate new hash
        hash2 = crypt(arr5, salt);
        // compare the two hashes
        x = strcmp(hash, hash2);
        // if you found your word stop
        if (x == 0)
        {
            printf("%s\n", arr5);
            break;
        }
    }
}


