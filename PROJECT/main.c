#include<stdio.h>
#include "loginuser.h"
#include "registration.h"
#include "standarddeduction.h"
#include "updation.h"
#include "deletion.h"    
int main(){
    int choice;
    printf("Enter a choice from 1 to 2: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            update();
            break;
        case 4:
            Delete()
            break;

        default: printf("invalid choice");
            break;
    }
    return 0;
}   