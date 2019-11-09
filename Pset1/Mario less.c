// Mario Pyramid

#include <cs50.h>
#include <stdio.h>
 
int get_value1_8(void);

void pyramid(int height);

int main(void)
{
    int x;
    
    // Get Value From User
    x = get_value1_8();
    
    // Draw Pyramid
    pyramid(x); 

}

//Function To Get Value From User Between 1----8
int get_value1_8(void)
{
    int result = 0;
    
    do
    {
            
        result = get_int("Height: ");
            
    }
    while ((result < 1) || (result > 8));
    
    return result;
    
}

//Function To Draw Pyramid
void pyramid(int height)
{
    int count = height - 1;
    
    for (int i = 1; i <= height; i++)
    {
        for (int j = count; j > 0; j--)
        {
            printf(" ");
        }
        count--;
        
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");

    }
}
