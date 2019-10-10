#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_num(string key);
int shift(char c);

int main(int argc, string argv[])
{
    if (argc != 2 || is_num(argv[1]))
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    string keyword = argv[1];
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, j = strlen(p), k, l = 0, m = strlen(keyword), type; i < j; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        type = isupper(p[i]) ? 'A' : 'a';
        l %= m;
        k = shift(keyword[l++]);
        printf("%c", (((p[i] - type) + k) % 26) + type);
    }
    printf("\n");
    return 0;
}

bool is_num(string key)
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        if (isdigit(key[i]))
        {
            return true;
        }
    }
    return false;
}

int shift(char c)
{
    return c - (isupper(c) ? 'A' : 'a');
}
