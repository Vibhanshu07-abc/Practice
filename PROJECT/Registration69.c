#include<stdio.h>

struct user{
    char username[50];
    char password[50];
    char name[100];
    char email[50];
};
void Registration(){
    FILE *fp=fopen("loginuserdetails.txt","a");
    if (fp==NULL){
        printf("Errors in opening files: ");
        return;
    }
    struct user e;

    printf("Enter a username: ");
    getchar();
    scanf("%[^\n]s",e.username);

    printf("Enter a password: ");
    getchar();
    scanf("%[^\n]s", e.password);

    printf("Enter a name: ");
    getchar();
    scanf("%[^\n]s", e.name);

    printf("Enter a email: ");
    getchar();
    scanf("%[^\n]s",e.email);

    fprintf(fp, "User name :%s\n", e.username);
    fprintf(fp, "Password :%s\n", e.password);
    fprintf(fp, "Name :%s\n", e.name);
    fprintf(fp, "email :%s\n", e.email);
    fclose(fp);
}

