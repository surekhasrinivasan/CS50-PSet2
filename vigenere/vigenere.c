//Program that encrypts the message using Vigenère’s cipher.
//Here plaintext is unencrypted text using a keyword(i.e.,an alphbetical string), it is encrypted to cipher text.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check if the user do not enter keyword
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //2nd command line argument is a string which user enters as keyword
    string keyword = argv[1];

    //get the length of the keyword
    int key = strlen(argv[1]);

    //check if the user enters only alphabets for keyword
    for (int i = 0; i < key; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    //prompt the user to enter the plaintext to be encrypted
    string plainText = get_string("plaintext: ");

    //prints the encrypted ciphertext characters
    printf("ciphertext: ");

    //loops through the entire length of the plaintext string
    for (int i = 0, length = strlen(plainText), key_count = 0; i < length; i++)
    {
        //check if the user enters only alphabets for the plaintext
        if (isalpha(plainText[i]))
        {
            //if the user entered uppercase plaintext
            if (isupper(plainText[i]))
            {
                //prints ciphertext in uppercase to the corresponding plaintext uppercase characters
                printf("%c", (plainText[i] - 'A' + toupper(keyword[key_count]) - 'A') % 26 + 'A');
            }
            //if the user entered lowercase plaintext
            else if (islower(plainText[i]))
            {
                //prints ciphertext in lowercase to the corresponding plaintext lowercase characters
                printf("%c", (plainText[i] - 'a' + tolower(keyword[key_count]) - 'a') % 26 + 'a');
            }
            //Using modulo for wraparound the index of the keyword
            key_count = (key_count + 1) % key;
        }
        else
        {
            //prints anything entered by user other than alphabets eg: 1 2 3 4
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    return 0;
}