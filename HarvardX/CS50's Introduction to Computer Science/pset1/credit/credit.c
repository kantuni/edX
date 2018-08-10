#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    // Prompt user for a number.
    long long n = get_long_long("Number: ");
    // Calculate the length of the number.
    int m = (n == 0) ? 1 : floor(log10(n)) + 1;
    // Put digits of the number in an array.
    int d[m];
    for (int i = 0; i < m; i++)
    {
        d[m - i - 1] = n % 10;
        n /= 10;
    }
    // Multiply every other digit by 2,
    // starting with the number’s second-to-last digit,
    // and then add those products' digits together.
    int sum = 0;
    for (int i = m - 2; i >= 0; i -= 2)
    {
        int tmp = d[i] * 2;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
    }
    // Add the sum to the sum of the digits
    // that weren’t multiplied by 2.
    for (int i = m - 1; i >= 0; i -= 2)
    {
        sum += d[i];
    }
    // If the total’s last digit is 0, the number is valid.
    if (sum % 10 == 0)
    {
        // American Express uses 15-digit numbers.
        // American Express numbers all start with 34 or 37.
        bool amex = m == 15 && d[0] == 3 && (d[1] == 4 || d[1] == 7);
        // MasterCard uses 16-digit numbers.
        // MasterCard numbers all start with 51, 52, 53, 54, or 55.
        bool mastercard = m == 16 && d[0] == 5 && d[1] > 0 && d[1] < 6;
        // Visa uses 13- and 16-digit numbers.
        // Visa numbers all start with 4.
        bool visa = (m == 13 || m == 16) && d[0] == 4;
        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mastercard)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
