#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // get key from command line argument
        int k = atoi(argv[1]);
        // get plaintext
        string p = get_string("plaintext: ");
        // encipher
        string c = p;
        for (int i = 0, len = strlen(p); i < len; i++)
        {
            // the program must preserve case
            if (islower(c[i]))
            {
                c[i] = 'a' + (p[i] - 'a' + k) % 26;
            }
            else if (isupper(c[i]))
            {
                c[i] = 'A' + (p[i] - 'A' + k) % 26;
            }
        }
        // print ciphertext
        printf("ciphertext: %s\n", c);
    }
    else
    {
        // print error message
        printf("Usage: ./caesar k\n");
        // exit with code 1
        return 1;
    }
    return 0;
}
