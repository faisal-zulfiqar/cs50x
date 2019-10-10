#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool is_string(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || is_string(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, j = strlen(p), type; i < j; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        type = isupper(p[i]) ? 'A' : 'a';
        printf("%c", (((p[i] - type) + k) % 26) + type);
    }
    printf("\n");
    return 0;
}

bool is_string(string key)
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        if (isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}
