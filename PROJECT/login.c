#include<stdio.h>
#include<string.h>
void main()
{
    char user_name[50];
    printf("Enter a user name: ");
    getchar();
    scanf("%[^\n]s",user_name);
    char username[50];
    printf("Enter a username for management system: ");
    getchar();
    scanf("%[^\n]s",username);
    char password[50];
    printf("Enter a password: ");
    getchar();
    scanf("%[^\n]s",password);
    FILE *ptr;
    ptr=fopen("loginuserdetails.txt","w");
    if(ptr==NULL)
    {
        printf("Error in opening files");
        return;
    }
    fprintf(ptr,"user Name: %s\n", user_name);
    fprintf(ptr,"taxpayers username: %s\n", username);
    fprintf(ptr,"taxpayers password: %s\n",password);

    printf("Enter the taxpayer username to login: ");
    getchar();
    scanf("%[^\n]s",user_name);
    char taxpayer_password[50];
    printf("Enter the taxpayer password to login: ");
    getchar();
    scanf("%[^\n]s",taxpayer_password);

    if(strcmp(username, user_name )==0)
    {
        if(strcmp(password, taxpayer_password)==0)
        {
            printf("Login successfully: ");
        }
        else{
            printf("Login unsuccessful: ");
        }
    }
    else{
        printf("Wrong username: ");
    }
    fclose(ptr);
}