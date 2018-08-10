#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // There should be exactly 2 command line arguments
    // (the program name and the key).
    if (argc == 2)
    {
        // Get the key as an integer.
        int k = atoi(argv[1]);
        // Prompt the user for a plaintext.
        string p = get_string("plaintext: ");
        // Encipher the plaintext.
        string c = p;
        for (int i = 0, len = strlen(p); i < len; i++)
        {
            // Apply transformation only to alphabetical characters.
            if (isalpha(c[i]))
            {
                // The program must preserve case.
                char start = isupper(c[i]) ? 'A' : 'a';
                c[i] = start + (p[i] - start + k) % 26;
            }
        }
        // Print the ciphertext.
        printf("ciphertext: %s\n", c);
    }
    // Otherwise, print the error message and exit with code 1.
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    return 0;
}
