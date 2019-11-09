#include <stdio.h>
#include <string.h>
#include <cs50.h>
int valid_input(int count, char *ptr);
int character_capital(char c);
void caesar(int x);
int character_lower(char c);
int stringtointeger(char *string);


int main(int argc, string argv[])
{
    int x ;

    x = valid_input(argc, argv[1]);
    
    printf("%d\n", x);

    if (x == -1)
    {
        printf("Usage: %s key\n", argv[0]);

    }
    else
    {
        caesar(x);
    }





    return 0;
}

// Check The Input Is valid or not
int valid_input(int count, char *ptr)
{
    int result;
    
    if (count != 2)
    {
        return -1; 
    }
    else
    {
        for (int i = 0; ptr[i] != '\0'; i++)
        {
            if ((ptr[i] < '0') || (ptr[i] > '9'))
            {
                return -1;

            }
        }
    }
    
    result = stringtointeger(ptr);

    return result;

}

// Check the character is capital or not
int character_capital(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// Check The character is small or not 
int character_lower(char c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// Encrypt  the message with key x
void caesar(int x)
{
    char *code = get_string("plaintext:  ");
    int i = 0;
    
    
    
    while (code[i])
    {
        // Check the character is capital or not
        if (character_capital(code[i]))
        {
            if (x < ('Z' - code[i]))
            {
                code[i] = code[i] + x ;
            }
            else
            {
                if (x > 26)
                {
                    x %= 26;
                }
                if (x < ('Z' - code[i]))
                {
                    code[i] = code[i] + x ;
                }
                else
                {
                    code[i] = 'A' + x  - ('Z' - code[i]) - 1 ;  
                }
                
                
            }


        }
        // Check The character is small or not
        else  if (character_lower(code[i]))
        {
            if (x < ('z' - code[i]))
            {
                code[i] = code[i] + x ;
            }
            else
            { 
                if (x > 26)
                {
                    x %= 26;
                }
                
                if (x < ('z' - code[i]))
                {
                    code[i] = code[i] + x ; 
                }
                else
                {
                    code[i] = 'a' + x  - ('z' - code[i]) - 1 ;
                }
               
            }


        }

        i++;

    }

    printf("ciphertext: %s\n", code);


}
int stringtointeger(char *string)
{
    unsigned int result ;
    int temp ;

    int size = strlen(string);

    int temp2 = size ;

    result = string[size - 1] - 48 ;

    for (int i = 0; i < size - 1; i++)
    {
        temp = 1;

        for (int j = 0 ; j < temp2 - 1; j++)
        {
            temp *= 10 ;
        }
        temp2-- ;

        result += temp * (string[i] - 48);

    }
    return result ;

}

