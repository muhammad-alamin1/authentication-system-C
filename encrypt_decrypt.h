#include <stdio.h>
#include <string.h>

// pass encrypt
char* encrypt_pass(char *pass, int key)
{
    unsigned int i;
    for(i = 0; i < strlen(pass); ++i)
        pass[i] -= key;

    return pass;
}

// pass decrypt
char* decrypt_pass(char *pass, int key)
{
    unsigned int i;
    for(i = 0; i <strlen(pass); ++i)
        pass[i] += key;

    return pass;
}

// the password as '*' character
void change_pass(char *pass)
{
    char ch;
    unsigned int i;

    for(i = 0; i < strlen(pass); i++)
    {
        ch = pass[i];
        pass[i] = ch;
        ch = '*';

        printf("%c", ch);
    }
}










