#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentences = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
        if (text[i] == 32)
        {
            words++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
