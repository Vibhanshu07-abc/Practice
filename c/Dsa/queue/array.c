#include<stdio.h>
#define max 100
void enqueue(int *front,int *rear,int arr[],int value){
  if(rear==max-1){
    printf("queue is full\n");
  }
    else if(front==-1){
    *front++;
    *rear++;
    arr[*front]=value;
  }
  else{
    *rear++;
    arr[*rear]=value;
  }
}
int dequeue(int *front,int *rear,int arr[]){
    if((*rear)==(*front)){
        *front=*rear=-1;
    }
    else{
        int value=arr[*front];
        printf("value dequeued is %d\n",value);
        *front++;
    }
}
int main(){
    int arr[max];
    int front=-1;
    int rear=-1;
    int value;
    int choice ;
    do{
        printf("enter 1 to enqueue,enter 2 to dequeue enter 3 to exit ;")
        scanf("%d",&choice);
    }while(choice!=3);
}