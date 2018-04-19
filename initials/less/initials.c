//Program that prints a person’s initials given the person’s name

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//SC:This code looks good.
int main (void)
{
    //prompt the user for his/her full name with space in between first middle and last name
    string name = get_string();

    //Assign the length of string (total no. of characters) name to an int n
    int n = strlen(name);

    //Prints the first character of the person's name in uppercase i.e., the first initial
    printf("%c", toupper(name[0]));

    //loop iterates through the name checking for spaces
    for (int i = 0; i < n; i++)
    {
        if (name[i] == ' ')
        {
            //prints first letter after a space in upper case
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}