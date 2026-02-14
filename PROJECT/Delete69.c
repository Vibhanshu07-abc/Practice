#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim_spaces(char* str) {
    int start = 0, end = strlen(str) - 1;

    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }

    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }

    for (int i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[end - start + 1] = '\0';
}

void delete() {
    FILE *fp = fopen("loginuserdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char username[50];
    printf("Enter username to delete: ");
    while (getchar() != '\n'); 
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    trim_spaces(username);

    FILE *temp = fopen("tempdata.txt", "w");
    if (temp == NULL) {
        printf("Error opening temp file.\n");
        fclose(fp);
        return;
    }

    char line[256];
    int found = 0, skip = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Username:", 9) == 0) {
            char extractedName[50];
            sscanf(line + 9, " %49[^\n]", extractedName);
            trim_spaces(extractedName);

            if (strcmp(extractedName, username) == 0) {
                found = 1;
                skip = 3;  
                continue;
            } else {
                skip = 0;
            }
        }

        if (skip > 0) {
            skip--;
            continue;
        }

        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("loginuserdetails.txt");
        rename("tempdata.txt", "loginuserdetails.txt");
        printf("User record deleted successfully.\n");
    } else {
        remove("tempdata.txt");
        printf("User not found.\n");
    }
}
