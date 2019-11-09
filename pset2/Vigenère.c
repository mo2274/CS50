// Vigenère’s cipher

#include <cs50.h>
#include <stdio.h>

int character_capital_or_small(char c);
int valid_input(int count, char *ptr);
void vigenere(char *ptr);
void rotate(int temp, int index, char *message, int *ptr);

int main(int argc, string argv[])
{
	
    // Check the input is valid or not
    if (valid_input(argc, argv[1]) == -1)
    {
        printf("Usage: %s keyword\n", argv[0]);
        return 1;
    }
    else
    {
        // If the user input valid generate the code
        vigenere(argv[1]);
    }
}

// Check The letter is upper case or lower case .
int character_capital_or_small(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        return 1;
    }
    else if ((c >= 'a') && (c <= 'z'))
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

// Check The Input Is valid or not
int valid_input(int count, char *ptr)
{

    if (count != 2)
    {
        return -1;
    }

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (character_capital_or_small(ptr[i]) == -1)
        {
            return -1;
        }

    }

    return 1;

}

// Take message and code it acording to Vigenère’s cipher
void vigenere(char *ptr)
{
    string message = get_string("plaintext:  ");
    int index = 0;
    int temp;

    while (message[index])
    {
        for (int  i = 0; (ptr[i] != 0) && (message[index] != 0);)
        {
            // Check the character of key capital or small
            if (character_capital_or_small(ptr[i]))
            {
                temp = ptr[i] % 65;

                rotate(temp, index, message, &i);

            }
            else
            {
                temp = ptr[i] % 97;
                rotate(temp, index, message, &i);
               
            }
            
            index++;

        }
           

    }
    printf("ciphertext: %s\n", message);

}

// Rotate Character by specific value
void rotate(int temp, int index, char *message, int *ptr)
{
    if (character_capital_or_small(message[index]) == 1)
    {
        if (temp <= ('Z' - message[index]))
        {
            message[index] += temp ;
            (*ptr)++;
        }
        else
        {
            message[index] = 'A' + temp  - ('Z' -  message[index]) - 1 ;
            (*ptr)++;

        }

    }
    else if (character_capital_or_small(message[index]) == 0)
    {
        if (temp <= ('z' - message[index]))
        {
            message[index] += temp ;
            (*ptr)++;

        }
        else
        {
            message[index] = 'a' + temp  - ('z' -  message[index]) - 1 ;
            (*ptr)++;

        }

    }



}
