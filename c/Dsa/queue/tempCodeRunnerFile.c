#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node*next;
}q;
q* rear=NULL;
q* front =NULL;
void enqueue(int x){
    q*temp;
    temp=(q*)malloc(sizeof(q));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
q* dequeue(){
     q*temp=front;
    if(front==NULL&&rear==NULL){
        printf("list is empty:\n");
        return NULL;
    }
    int a=temp->data;
    printf("value popped is %d",a);
    if(front==rear){
        free(temp);
        front =rear=NULL; 
    }
    else{
    front=front->next;
    free(temp);
    }
    return front;
    
}
void display(){
    q*temp=front;
    if(front==NULL&&rear==NULL){
        printf("queue is empty :\n");
    }
    else{
        while(temp!=NULL){
            printf("  %d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int value;
    int choice;
    do{
        printf("enter the chocie :\n");
        printf("enter 1 to enqueue\n");
        printf("enter 2 to dequeue\n");
        printf("enter 3 to display\n");
        printf("enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter thee value :\n");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            break;
            default: 
            exit(0);
        }
    }while(choice!=4);
}