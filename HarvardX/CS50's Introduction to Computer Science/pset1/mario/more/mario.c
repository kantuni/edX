#include <stdio.h>
#include <cs50.h>

int main()
{
    // Prompt and validate user input.
    // The height of the half-pyramids should be a
    // non-negative integer no greater than 23.
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);
    // Draw two half-pyramids.
    for (int i = 0; i < n; i++)
    {
        // Print spaces for the left pyramid.
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Print hashes for the left pyramid.
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Print the gap.
        printf("  ");
        // Print hashes for the right pyramid.
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Move the cursor to the next line.
        printf("\n");
    }
    return 0;
}
