#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main(){
struct node*head=NULL,*newnode,*temp;
int choice ;
while(choice!=2){
newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the element \n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
   if(head==NULL){
    head=temp=newnode;
   }
   else{
          temp->next=newnode;
          temp=newnode;
   }
printf("enter the 1 to enter details ,enter 2 to exit ...\n");
    printf("enter the choice ");
    scanf("%d",&choice);
}
temp=head;
while(temp!=NULL){
printf("%d",temp->data);
temp=temp->next;
}
}
