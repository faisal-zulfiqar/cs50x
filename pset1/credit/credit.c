#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long original = number;
    int sum = 0, i = 0, digit;
    
    while (number)
    {
        if (i)
        {
            digit = number % 10;
            int doubled = digit * 2;
            if (doubled > 9)
            {
                sum += doubled % 10;
                doubled /= 10;
                sum += doubled % 10;
            }
            else
            {
                sum += doubled;
            }
        }
        else
        {
            digit = number % 10;
            sum += digit;
        }
        number /= 10;
        i = 1 - i;
    }
  
    if (sum % 10 == 0)
    {   
        if (original >= 5100000000000000 && original < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((original >= 4000000000000 && original < 5000000000000) || (original >= 4000000000000000 && original < 5000000000000000))
        {
            printf("VISA\n");
        }
        else if ((original >= 340000000000000 && original < 350000000000000) || (original >= 370000000000000 && original < 380000000000000))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }       
    }
    else
    {
        printf("INVALID\n");
    }
}
