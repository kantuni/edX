#include <stdio.h>
#include <cs50.h>

int main()
{
    // prompt and validate user input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);
    // draw the half-pyramid
    for (int i = 0; i < n; i++)
    {
        // print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // print hashes
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }
    return 0;
}
