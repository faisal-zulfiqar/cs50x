#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char salt[2], key[5];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = 53;
    
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                for (int l = 0; l < len; l++)
                {
                    for (int m = 1; m < len; m++)
                    {
                        key[0] = letters[m];
                        key[1] = letters[l];
                        key[2] = letters[k];
                        key[3] = letters[j];
                        key[4] = letters[i];
                        
                        if (strcmp(argv[1], crypt(key, salt)) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    printf("Could not crack.\n");
    return 2;
}
