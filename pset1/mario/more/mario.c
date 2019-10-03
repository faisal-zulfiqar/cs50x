#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++)
    {
        int j;
        for (j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        
        for (; j < height; j++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
