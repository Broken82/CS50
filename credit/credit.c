#include <cs50.h>
#include <stdio.h>

int main(void)
{
int n;
do
{
    n = get_int("Podaj numer: ");
}
while (n < 0 || n > 8);



    long number;
    do
    {
        number = get_long("Credit number: ");
    }
    while (number < 0);
    //every other digit, staring with the second to last digit
    int card1, card2, card3, card4, card5, card6, card7, card8;

    card1 = ((number % 100) / 10 * 2);
    card2 = ((number % 10000) / 1000 * 2);
    card3 = ((number % 1000000) / 100000 * 2);
    card4 = ((number % 100000000) / 10000000 * 2);
    card5 = ((number % 10000000000) / 1000000000 * 2);
    card6 = ((number % 1000000000000) / 100000000000 * 2);
    card7 = ((number % 100000000000000) / 10000000000000 * 2);
    card8 = ((number % 10000000000000000) / 1000000000000000 * 2);

    //adding individual digits
    card1 = (card1 % 10) + (card1 / 10);
    card2 = (card2 % 10) + (card2 / 10);
    card3 = (card3 % 10) + (card3 / 10);
    card4 = (card4 % 10) + (card4 / 10);
    card5 = (card5 % 10) + (card5 / 10);
    card6 = (card6 % 10) + (card6 / 10);
    card7 = (card7 % 10) + (card7 / 10);
    card8 = (card8 % 10) + (card8 / 10);

    //sum of the every other digits starting from the second to last digit
    int sum1 = card1 + card2 + card3 + card4 + card5 + card6+ card7+ card8;

    //rest of the digits
    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9  = (number % 10);
    card10 = ((number % 1000) / 100);
    card11 = ((number % 100000) / 10000);
    card12 = ((number % 10000000) / 1000000);
    card13 = ((number % 1000000000) / 100000000);
    card14 = ((number % 100000000000) / 10000000000);
    card15 = ((number % 10000000000000) / 1000000000000);
    card16 = ((number % 1000000000000000) / 100000000000000);

    //sum of the evey other digits starting from the very last digit
    int sum2 = card9 + card10 + card11 + card12 + card13+ card14 + card15+ card16;

    //checksum

    int sum3 = sum1 + sum2;
    //for mastercard and visa, a lot of things to do, of course im doing this not the effecient way :D!



    //checking if it's a valid card
    long number1 = number;
    long AMEX = number1;
    long MASTERCARD = number1 / 100000000000000;
    long VISA = number1;


    if (sum3 % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    //checking length

    int length = 0;
    while (number > 0)
    {
        number = number/10;
        length++;
    }




    // length and starting digits
    if (length == 15 && (AMEX / 10000000000000  == 37 || AMEX  / 10000000000000 == 34))
    for(int i = 0; i < n; i++)
    {
        printf("AMEX\n");
        for(int j = -1; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    else if (length == 16 && (MASTERCARD  == 51 || MASTERCARD  == 52 || MASTERCARD  == 53 || MASTERCARD  == 54 || MASTERCARD  == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 16 || length == 13)&&(VISA / 1000000000000000 == 4 || VISA / 1000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }


    printf("\n");



}