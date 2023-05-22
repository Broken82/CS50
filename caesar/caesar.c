#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);


int main(int argc, string argv[])
{
    if (argc != 2)

    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    if (only_digits(argv[1]) != true)

    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    string plaintext = get_string("plaintext: ");
    int convert = atoi(argv[1]);
    printf("ciphertext: ");
    for(int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalnum(plaintext[i]))
        {
         int result = rotate(plaintext[i], convert);
         printf("%c", result);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}

bool only_digits(string s)
{
    int check = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            check = check + 1;
        }
        else
        {
            check = 0;
            break;
        }
    }

    if (check > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

char rotate(char c, int n)
{
    int formula = 0;

    if (islower(c))
    {
         c = c - 97;
         formula = (c + n) % 26;
         formula = formula + 97;
    }

    if (isupper(c))
    {
         c = c - 65;
         formula = (c + n) % 26;
         formula = formula + 65;
    }

    return formula;
}