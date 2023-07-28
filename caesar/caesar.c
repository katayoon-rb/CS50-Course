#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plain = get_string("plaintext:  ");
    int key = atoi(argv[1]);

    char co;
    int mn = strlen(plain);
    char cipher[mn];

    for (int j = 0; j < mn; j++)
    {
        int c = plain[j];

        if (isalpha(c))
        {
            co = c + key % 26;
            if (!(islower(co) || isupper(co)))
            {
                co -= 26;
            }
        }
        else
        {
            co = c;
        }
        cipher[j] = co;
    }

    printf("ciphertext: %s\n", cipher);
    return 0;
}