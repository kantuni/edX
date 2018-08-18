#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool check(string hash, string key, string salt)
{
    // Get the hash generated from the key and salt.
    string h = crypt(key, salt);
    if (h == hash)
    {
        // Print the cracked password.
        printf("%s\n", key);
        return true;
    }
    return false;
}

int main(int argc, string argv[])
{
    // There should be exactly 2 command line arguments
    // (the program name and the hash).
    if (argc == 2)
    {
        // Get the hash.
        string hash = argv[1];
        // Get the salt.
        char salt[] = {hash[0], hash[1]};
        // Create an array with all possible letters.
        char letters[] =
        {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        // Get the length of that array.
        int llen = strlen(letters);
        // Generate all possible keys. Assume that each key is composed
        // entirely of alphabetical characters (uppercase and/or lowercase).
        // Encrypt them with the given salt. Compare the result with the
        // given hash. If the hashes match, we've cracked the password.
        bool cracked = false;
        for (int len = 1; len < 6; len++)
        {
            char key[len];
            for (int i = 0; i < llen; i++)
            {
                // Generate a key with length 1.
                key[0] = letters[i];
                // Check that key.
                cracked = check(hash, key, salt);
                for (int j = 0; j < llen && len > 1 && !cracked; j++)
                {
                    // Generate a key with length 2.
                    key[1] = letters[j];
                    // Check that key.
                    cracked = check(hash, key, salt);
                    for (int k = 0; k < llen && len > 2 && !cracked; k++)
                    {
                        // Generate a key with length 3.
                        key[2] = letters[k];
                        // Check that key.
                        cracked = check(hash, key, salt);
                        for (int l = 0; l < llen && len > 3 && !cracked; l++)
                        {
                            // Generate a key with length 4.
                            key[3] = letters[l];
                            // Check that key.
                            cracked = check(hash, key, salt);
                            for (int m = 0; m < llen && len > 4 && !cracked; m++)
                            {
                                // Generate a key with length 5.
                                key[4] = letters[m];
                                // Check that key.
                                cracked = check(hash, key, salt);
                            }
                        }
                    }
                }
            }
        }
    }
    // Otherwise, print the error message and exit with code 1.
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    return 0;
}
