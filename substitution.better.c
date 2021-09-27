#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool isAlphabetical(string key);
void cypher(string input, string key);
bool isDuplicate(string key);

int main(int argc, string argv[])
{
    //uses multiple functions to check if the inputted command line argument key is valid. if valid, gets input from user and runs ciphers it.
    string input;
    if (argc != 2 || strlen(argv[1]) != 26 || !isAlphabetical(argv[1]) || !isDuplicate(argv[1]))
    {
        printf("Must provide one command line argument as encryption key. Key must be 26 alphabetic characters long with no repeating characters.\n");
        return 1;
    }
    input = get_string("plaintext: ");
    cypher(input, argv[1]);
    return 0;
}

//checks if the inputted key is strictly alphabetical characters
bool isAlphabetical(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

//checks if the inputted key has no reused characters. if theres no reused inputted chars, the total added ASCII value of the chars of the key should be 325
bool isDuplicate(string key)
{
    int array[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        int x = toupper(key[i]) - 'A';
        array[x] += 1;
        if (array[x] == 2)
        {
            return false;
        }
    }
    return true;
}

//function to cipher the inputted string using the provided valid key
void cypher(string input, string key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isupper(input[i]))
        {
            int x = input[i] - 'A';
            printf("%c", toupper(key[x]));
        }
        else if (islower(input[i]))
        {
            int x = input[i] - 'a';
            printf("%c", tolower(key[x]));
        }
        else
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}
