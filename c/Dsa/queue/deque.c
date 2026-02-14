#include<stdio.h>
#define max 10
int front=-1;
int rear=-1;
void enqueueatend(int x){
    if(front==0&&rear==max-1||(rear+1)==front){
     printf("queue is full :\n");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        arr[front]=x;
    }
    else if{
        rear=(rear+1)%max;
        arr[rear]=x;
    }

}

