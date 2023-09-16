#include <stdio.h>
#include <string.h>

struct Usr {
    char name[50];
    char email[50];
    char password[50];
};
const SECRET_KEY = 0xFACADBF;

// authenticate user
int authenticate_user()
{
    char search_email[50];
    char search_password[50];

    printf("Enter Your E-mail: \n");
    scanf("%s", search_email);
    printf("Enter Your Password: \n");
    scanf("%s", search_password);

    struct Usr user;
    int found = 0; // Flag to track if the email was found

    // read data to file (db)
    FILE *fp;
    fp = fopen("db.txt", "r");

    if (fp == NULL) {
        perror("Error opening the file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "E-mail: ") != NULL) {
            strcpy(user.email, line + strlen("E-mail: "));
            user.email[strlen(user.email) - 1] = '\0'; // Remove the newline character
        } else if (strstr(line, "Password: ") != NULL) {
            strcpy(user.password, line + strlen("Password: "));
            user.password[strlen(user.password) - 1] = '\0'; // Remove the newline character
        }else if (strstr(line, "Name: ") != NULL) {
            strcpy(user.name, line + strlen("Name: "));
            user.name[strlen(user.name) - 1] = '\0'; // Remove the newline character
        }

        // decrypt password
        char* decrypt = decrypt_pass(user.password, SECRET_KEY);

        if (strcmp(search_email, user.email) == 0 && strcmp(search_password, decrypt) == 0) {
            printf("Authentication successful. Welcome, %s!\n", user.name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Authentication failed. Invalid email or password.\n");
    }

    fclose(fp);
}
