#include <stdio.h>
#include <cs50.h>

int main()
{
    // Prompt user for an amount of change.
    // The amount should not be negative.
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    // Convert dollars into cents.
    int cents = n * 100 + 0.5;
    // Calculate the minimum number of coins.
    int ans = 0;
    // Calculate the number of quarters used.
    ans += cents / 25;
    cents %= 25;
    // Calculate the number of dimes used.
    ans += cents / 10;
    cents %= 10;
    // Calculate the number of nickles used.
    ans += cents / 5;
    cents %= 5;
    // Calculate the number of pennies used.
    ans += cents;
    printf("%i\n", ans);
    return 0;
}
