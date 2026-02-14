#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}link;

int main(){
link*head=NULL;
link*temp,*newnode;
int choice=1;
while(choice==1){
newnode=(link*)malloc(sizeof(link));
if(newnode==NULL){
    printf("memory allocation failed\n");
}
else{
    printf("enter the data in the new node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
printf("enter 1 to continue \n enter 2 to exit ...\n");
scanf("%d",&choice);
}
printf("the elements are :\n");
temp=head;
while(temp!=NULL){
   printf("  %d\n",temp->data);
   temp=temp->next;
}
}