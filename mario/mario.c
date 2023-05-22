#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int n = get_int("Size: \n");
    //rows
    for (int i = 0; i < n; i++ )
    {
        //pushing the left side
        for( int k = 0; k < n  - 1- i; k++)
        {
            printf(" ");
        }
        //printing the left side
        for (int j = 0; j < i + 1; j++)
        {

            printf("#");

        }
        //space between
        printf(" ");

        //right side
        for (int l = 0; l < i + 1; l++)
        {

            printf("#");

        }

        //prints new line
        printf("\n");
    }
}