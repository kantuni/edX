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
    // draw two half-pyramids
    for (int i = 0; i < n; i++)
    {
        // print spaces for left pyramid
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // print hashes for left pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // print gap
        printf("  ");
        // print hashes for right pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }
    return 0;
}
