#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.0);
    
    int coins = round(dollars * 100);
    int arr[] = {25, 10, 5, 1};
    int num_of_coins = 0, i = 0;
    
    while (coins != 0)
    {
        if (coins - arr[i] >= 0)
        {
            coins -= arr[i];
            num_of_coins++;
        }
        else
        {
            i++;
        }
    }
    
    printf("%i\n", num_of_coins);
}
