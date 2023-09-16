#include <stdio.h>
#include "encrypt_decrypt.h"

struct User
{
    char *full_name[50];
    char *email[50];
    char *phone[50];
    char *password[50];
};

void register_user()
{
    const SECRET_KEY = 0xFACADBF;
    struct User new_user;

    printf("Enter User Full Name: \n");
    scanf("%s", new_user.full_name);
    printf("Enter User E-mail: \n");
    scanf("%s", new_user.email);
    printf("Enter User Phone: \n");
    scanf("%s", new_user.phone);
    printf("Enter Password: \n");
    scanf("%s", new_user.password);

    // encrypt password
    char* encrypt = encrypt_pass(new_user.password, SECRET_KEY);

    // write data to file(db)
    FILE *fp;

    fp = fopen("db.txt", "w");
    fprintf(fp, "Name: %s\nE-mail: %s\nPhone: %s\nPassword: %s\n\n\n",new_user.full_name, new_user.email, new_user.phone, encrypt);

    fclose(fp);
}
