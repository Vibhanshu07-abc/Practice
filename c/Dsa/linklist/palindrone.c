#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}r;
r*reverse(r*head){
    r*current=head;
    r*nextnode=head;
    r*prev=NULL;
     if(head==NULL){
   printf("list is empty\n");
    }
    while(current!=NULL){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
}head=prev;
    return head;
}
int main(){
r* head=NULL;
int flag=1;
r*temp,*newnode;
int choice;
r*newhead;
do{
    printf("enter the choice 1 to enter element:\n");
    printf("enter choice 2 to exit:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        newnode=(r*)malloc(sizeof(r));
        printf("enter the data in newnode : \n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        break;
        case 2:
        break;
        default:
        exit(0);
    }
 }while(choice!=2);
newhead=reverse(head);
    r*temp1=head;
    r*temp2=newhead;
while(temp1!=NULL&&temp2!=NULL){
    if(temp1->data!=temp2->data){
       flag=0;
       break;
    }
    temp1=temp1->next;
    temp2=temp2->next;
}
if(flag==0){
    printf("linklist is not palindrone :\n");
}
else{
    printf("linklist is  palindrone :\n");
}
return 0;
}