#include<stdio.h>
#define N 20
int front =-1;
int rear = -1;
int arr[N];
void enqueue(int x){
    if(front==-1&&rear==-1){
        front=rear=0;
        arr[rear]=x;
    }
    else if((rear+1)%N==(front)){
        printf("queueu is full:\n");
    }
    else{
        rear=((rear+1)%N);
        arr[rear]= x;
    }
}
void dequeue(){
    int value;
     if(front==-1&&rear==-1){
        printf("queue is empty : \n");
     }
      value=arr[front];
      printf("   %d\n",value);
     if(rear==front){
        rear=front=-1;
     }
     else{
        front=(front+1)%N;
     }
     return value;
}
void display(){
    int temp=front;
    if(front==-1&&rear==-1){
        printf("queue is :\n");
    }
    else{
        while(temp!=rear){
            printf("  %d",arr[temp]);
            temp=(temp+1)%N;
        }
        printf("%d",arr[rear]);
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
            return 0;
        }
    }while(choice!=4);
}