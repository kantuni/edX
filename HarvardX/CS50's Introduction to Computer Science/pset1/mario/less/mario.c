#include <stdio.h>
#include <cs50.h>

int main()
{
    // Prompt and validate user input.
    // The height of the half-pyramid should be a
    // non-negative integer no greater than 23.
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);
    // Draw the half-pyramid.
    for (int i = 0; i < n; i++)
    {
        // Print spaces.
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Print hashes.
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        // Print the new line.
        printf("\n");
    }
    return 0;
}
