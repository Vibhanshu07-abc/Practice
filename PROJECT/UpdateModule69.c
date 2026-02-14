#include <stdio.h>
#include <string.h>

struct user {
    char username[50];
    char password[50];
    char name[100];
    char email[50];
};

void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; 
    }
}

void update() {
    FILE *fp = fopen("loginuserdetails.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char search_username[50];
    printf("Enter the username to update: ");
    read_line(search_username, sizeof(search_username));

    struct user e;
    char line[200];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "User name :", 11) == 0) {
            if (sscanf(line, "User name :%[^\n]", e.username) != 1) continue;
            if (!fgets(line, sizeof(line), fp) || sscanf(line, "Password :%[^\n]", e.password) != 1) continue;
            if (!fgets(line, sizeof(line), fp) || sscanf(line, "Name :%[^\n]", e.name) != 1) continue;
            if (!fgets(line, sizeof(line), fp) || sscanf(line, "email :%[^\n]", e.email) != 1) continue;

            if (strcmp(e.username, search_username) == 0) {
                printf("\nUser found. Enter new details:\n");

                printf("Enter new password: ");
                read_line(e.password, sizeof(e.password));

                printf("Enter new name: ");
                read_line(e.name, sizeof(e.name));

                printf("Enter new email: ");
                read_line(e.email, sizeof(e.email));

                found = 1;
            }

            fprintf(temp, "User name :%s\n", e.username);
            fprintf(temp, "Password :%s\n", e.password);
            fprintf(temp, "Name :%s\n", e.name);
            fprintf(temp, "email :%s\n", e.email);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("loginuserdetails.txt");
        rename("temp.txt", "loginuserdetails.txt");
        printf("\nUser data updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("\nUsername not found.\n");
    }
}
                                 
