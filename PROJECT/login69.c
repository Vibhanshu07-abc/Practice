#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login() {
    FILE *fp = fopen("Loginuserdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char username[50], password[50];

    printf("Enter a username to login: ");
    scanf(" %[^\n]", username);  
    printf("Enter a password to login: ");
    scanf(" %[^\n]", password);

    char regis_username[100];
    char regis_password[100];
    int flag = 0;

    while (fgets(regis_username, sizeof(regis_username), fp) != NULL) {
        if (strncmp(regis_username, "User name :", 11) == 0) {
            if (fgets(regis_password, sizeof(regis_password), fp) == NULL)
                break;

            if (strncmp(regis_password, "Password :", 10) != 0)
                continue;

            char username1[50], password1[50];
            sscanf(regis_username + 11, " %[^\n]", username1);
            sscanf(regis_password + 10, " %[^\n]", password1);

            if (strcmp(username, username1) == 0 && strcmp(password, password1) == 0) {
                flag = 1;
                break;
            }
        }
    }

    fclose(fp);

    if (flag == 1) {
        printf("Login successful.\n");
    } else {
        printf("Login unsuccessful.\n");
    }
}
