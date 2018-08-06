#include <stdio.h>
#include <cs50.h>

int main()
{
    // prompt user for an amount of change
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    // convert dollars to cents
    int cents = n * 100 + 0.5;
    // calculate the minimum number of coins
    int ans = 0;
    // quarters
    ans += cents / 25;
    cents %= 25;
    // dimes
    ans += cents / 10;
    cents %= 10;
    // nickles
    ans += cents / 5;
    cents %= 5;
    // pennies
    ans += cents;
    printf("%i\n", ans);
    return 0;
}
