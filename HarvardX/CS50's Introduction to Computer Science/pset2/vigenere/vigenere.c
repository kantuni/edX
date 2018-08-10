#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // There should be exactly 2 command line arguments
    // (the program name and the key). Otherwise, print
    // the error message and exit with code 1.
    if (argc == 2)
    {
        // Get the key.
        string k = argv[1];
        int klen = strlen(k);
        // Check if the key is valid (it should contain
        // only alphabetical characters).
        bool valid = true;
        for (int i = 0; i < klen; i++)
        {
            if (!isalpha(k[i]))
            {
                valid = false;
                break;
            }
            k[i] = toupper(k[i]);
        }
        // If the key is not valid, print the error message and
        // exit with code 1.
        if (!valid)
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        // Prompt the user for a plaintext.
        string p = get_string("plaintext: ");
        // Encipher the plaintext.
        string c = p;
        int clen = strlen(c);
        for (int i = 0, j = 0; i < clen; i++)
        {
            // Apply transformation only to alphabetical characters.
            if (isalpha(c[i]))
            {
                // Calculate alphabetical index (the "shift").
                char start = isupper(c[i]) ? 'A' : 'a';
                int shift = k[j] - 'A';
                // Encipher the character.
                c[i] = start + (c[i] - start + shift) % 26;
                j = (j + 1) % klen;
            }
        }
        // Print the ciphertext.
        printf("ciphertext: %s\n", c);
    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    return 0;
}
