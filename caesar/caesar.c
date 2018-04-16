//Program that encrypts the message using Caesar’s cipher.
//Here plaintext is unencrypted text using the secret key it is encrypted to cipher text.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check if the user do not enter key
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //atoi converts string (key in this case) to integer
    int key = atoi(argv[1]);

    //prompt the user to enter the plaintext to be encrypted
    string plainText = get_string("plaintext: ");

    //prints the encrypted ciphertext characters
    printf("ciphertext: ");

    //loops through the entire length of the plaintext string
    for (int i = 0, length = strlen(plainText); i < length; i++)
    {
        //if the user entered uppercase plaintext
        if (isupper(plainText[i]))
        {
            //prints ciphertext in uppercase
            printf("%c", (plainText[i] - 'A' + key) % 26 + 'A');
        }
        //if the user entered lowercase plaintext
        else if (islower(plainText[i]))
        {
            //prints lowercase ciphertext
            printf("%c", (plainText[i] - 'a' + key) % 26 + 'a');
        }
        else
        {
            //prints anything entered by user other than alphabets eg: 1 2 3 4
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}