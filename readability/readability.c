#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Input string: \n");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float index = 0.0588 * letters/words * 100 - 0.296 * sentences/words * 100 - 15.8;
    int rounding = round(index);

    if (rounding < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounding > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounding);
    }



}

int count_letters(string text)
{
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }

    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}