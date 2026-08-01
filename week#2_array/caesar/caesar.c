#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter : ./caeser \"key\"\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    for (int i = 0; key_length > i; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Enter : ./caeser \" only string here\"\n");
            return 1;
        }
    }

    int key_number = atoi(key);

    string text = get_string("plaintext :");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        if (isupper(c))
        {
            printf("%c", (c - 'A' + key_number) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key_number) % 26 + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}
