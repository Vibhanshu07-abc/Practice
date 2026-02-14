#include<stdio.h>
#include<stdlib.h>
typedef struct node {
 int data;
struct node*prev;
struct node*next;
}d;
 void traversal(d*head){
    d*temp=head;
    while(temp!=NULL){
        printf(" %d\n",temp->data);
        temp=temp->next;
    }
 }
 d*insertatstart(d*head){
    d*new;
    new=(d*)malloc(sizef(d));
    printf("enter the element\n");
    scanf("%d",&new-data);
    new->next=NULL;
    new->prev=NULL;
    head->prev=new;
    new->next=head;
    head=new;
    return new;
 }
 void insertatpos(int pos,d*head){
   d*newnode;
   d*temp=d*head;
    if(pos<1||pos>n){
      printf("invalid position\n");
    }
    else if (pos==1){
      insertatstart();
    }
    else{
      newnode=(d*)malloc(sizeof(d));
      printf("enter the value : \n");
      scanf("%d",&newnode->data);
      while(i<pos-1){
         temp=temp->next;
         i++;
      }
      newnode->prev=temp;
      newnode->next=temp->next;
      temp->next=newnode;
      newnode->nex->prev=newnode;
    }
 }
void create(){
  d*head=NULL;
  d*tail;
  d*newnode;
  d*temp;
  int choice=1;
  while (choice!=1){
  newnode=(d*)malloc(sizeof(d));
  if(newnode==NULL){
    printf("memory allocation failed\n");
    exit(1);
  }
   else{
      printf("enter data in new node :\n");
      scanf("%d",&newnode->data);
      newnode->prev=NULL;
      newnode->next=NULL;
      if (head==NULL){
        head=temp=newnode;
      }
      else {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
      }      
   }
   }
}