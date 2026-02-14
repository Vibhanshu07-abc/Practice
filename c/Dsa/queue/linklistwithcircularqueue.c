#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node*next;
}cq;
cq*rear=NULL;
cq*front=NULL;
void enqueue(int x){
    cq*newnode;
    newnode=(cq*)malloc(sizeof(cq));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    cq*temp;
    temp=front;
if(front==NULL&&rear==NULL){
    printf("queue is empty :\n");
}
    printf("%d",temp->data);
   if(front==rear){
        front=rear=NULL;
        free(temp);
    }
    else {
        front=front->next;
        rear->next=front;
    }
    free(temp);
}
void display(){
    cq*temp;
     temp=front;
     while(temp->next!=front){
        printf("  %d",temp->data);
        temp=temp->data;
     }
}
