// Credit

#include <stdio.h>
#include <cs50.h>

char *type_of_valid_credit(int *arr) ;
int *long_to_array(long long int x) ;
int Check_Valid_Or_not(int *arr) ;


int main(void)
{ 
    
    long long int credit_number ;
    int *arr ; 
    int y ; 
    char *result = "INVALID" ;
    
   
    // Get Credit Number From the user 
    credit_number = get_long("Number: ") ;
     
    //credit_number = 4003600000000014;
    
    // Convert The Number To Array
    arr = long_to_array(credit_number) ;

    
    // Check The Number Is Valid Or Not
    if (arr[0] == -1)
    {
        printf("%s\n", result) ;
    }
    else
    {
        y = Check_Valid_Or_not(arr) ;
            
        if (y == 0)
        {
            printf("%s\n", result) ;
        }
        else
        {
            result  = type_of_valid_credit(arr) ;
                
            printf("%s\n", result) ;
        }
         
        
    }
    

    
}

// Determine The Type Of Credit Card
char *type_of_valid_credit(int *arr)
{
    static char *credit ;
    int i;
    
    
    for (i = 15; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            break;
        }

    }

    // check the type of Credit Card
    if (arr[i] == 4)
    {
        credit = "VISA" ;
    }
    else if (((arr[i] == 3) && (arr[i - 1] == 4)) || ((arr[i] == 3) && (arr[i - 1] == 7)))
    {
        credit = "AMEX" ;
    }
    else if (((arr[i] == 5) && (arr[i - 1] == 1)) || ((arr[i] == 5) && (arr[i - 1] == 2)))
    {
        credit = "MASTERCARD" ;
    }
    else if (((arr[i] == 5) && (arr[i - 1] == 3)) || ((arr[i] == 5) && (arr[i - 1] == 4)))
    {
        credit = "MASTERCARD" ;
    }
    else if ((arr[i] == 5) && (arr[i - 1] == 5))
    {
        credit = "MASTERCARD" ;
    }
    else
    {
        credit = "INVALID" ; 
    }
    
    
    return credit ;
    
}

// Convert the number to array

int *long_to_array(long long int x)
{
    int i = 0 ;
    
    static int arr[16] = {0};
    int *ptr ;
    static int y = -1 ;
    ptr = &y ; 
    
    while (x > 0)
    {
        arr[i] = x % 10 ;
        x = x / 10 ;
        i++ ;
    }
    
    if (i < 13)
    {
        return ptr ;
    }
    else
    {
        return arr ;  
    }
   
    
}

// Check The Credit Is Valid Or Not
int Check_Valid_Or_not(int *arr)
{

    int count = 0 ;
    int i ;
    int temp ;

    for (i = 1; i < 16; i = i + 2)
    {

        temp = arr[i] * 2;

        while (temp > 0)
        {
            count += temp % 10;
            temp = temp / 10 ;
        }

    }
   
    for (i = 0; i < 16; i = i + 2)
    {

        count += arr[i]  ;

    }
 
    if ((count % 10) == 0)
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }

}


