#include <stdio.h>
#include <cs50.h>


bool valid_triangle(int a, int b, int c);

int main(void)
{

    int x = get_int(" Give me the first value: \n");
    int y = get_int("Give me the second value: \n");
    int z = get_int(" Give me the third value: \n");

    bool result = valid_triangle(x, y, z);

    printf("%d\n", result);



}


bool valid_triangle(int a, int b, int c)
{
    int sum = a + b;

    if ( (a + b <= c) || ( b + c <= a) || ( a + c <= b) )
    {
        return false;
    }


    if (a < 0 || b < 0 || c < 0)
    {

        return false;
    }

   return true;
}