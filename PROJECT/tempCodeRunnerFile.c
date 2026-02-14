#include<stdio.h>
#include "Delete69.h"
#include "login69.h"
#include "Registration69.h"
#include "standarddeduction69.h"
#include "UpdateModule69.h"
void Registration();
void login();
void deduction();
void update();
void delete();
int main(){
    int choice;
    printf("-----Welcome To The Tax Management System----- \n");
    printf("choose option 1 for Registration: \n");
    printf("choose option 2 for Login: \n");
    printf("choose option 3 to check deduction in salary: \n");
    printf("choose option 4 to Update user details: \n");
    printf("choose option 5 to Delete user details: \n");
    printf("choose option 6 to exit: \n");
      while (choice!=6)
    {
    printf("Enter a choice from 1 to 6: ");
    scanf("%d", &choice);
   switch(choice)
    {
        case 1:
             Registration();
            break;
        case 2:
             login();
            break;
        case 3:
             deduction();
            break;
        case 4:
             update();
            break;
        case 5:
            delete();
            break;
        case 6:
            printf("Exiting-----\n");
            break;
        default: printf("invalid choice");
            break;
    }
}   
}