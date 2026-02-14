#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue1[max];
int queue2[max];
int front1=-1,rear1=-1,front2=-1,rear2=-1;
void enqueue1(int value){
    if(rear1==max-1){
        printf("queue is full \n");
        return;
    }
    else if((rear1==-1)&&(front1==-1)){
      front1=rear1=0;
      queue1[rear1]=value;
    }
    else{
        
        queue1[++rear1]=value;
    }
}
void enqueue2(int value){
    if(rear2==max-1){
        printf("queue is full \n");
        return;
    }
    else if((rear2==-1)&&(front2==-1)){
      front2=rear2=0;
      queue2[rear2]=value;
    }
    else{
        
        queue2[++rear2]=value;
    }
}
int dequeue2(){
    int a;
    if((rear2==-1)&&(front2==-1)){
        return -1;
    }
    else if((rear2==front2)){
         a=queue2[rear2];
         front2=rear2=-1;
         return a;
    }
    else{
        return queue2[front2++];
    }
}
int dequeue1(){int a;
    if((rear1==-1)&&(front1==-1)){
        return -1;
    }
    else if((rear1==front1)){
        a= queue1[rear1];
         front1=rear1=-1;
         return a;
    }
    else{
        return queue1[front1++];
    }
}
void push(int value ){
    int a,b;
    enqueue1(value);
    while(front2!=-1){
        a=dequeue2();
        enqueue1(a);
    }
    while(front1!=-1){
        b=dequeue1();
        enqueue2(b);
    }
}
void pop(){
    if(front2==-1){
        printf("stack is empty \n");
        return;
    }
    else{
        printf("value popped is : %d ",dequeue2());
    }
}
void display(){
    int i;
    if(front2==-1){
        printf("stack is empty : \n");
    }
    printf("the elements of stacks are : ");
    for(int i=front2;i<=rear2;i++){
       printf("%d\n",queue2[i]);
    }
}
int main(){
    int value,ch;
    while(1){
        printf("enter the choice : \n 1.enter an element in stack\n 2.delete an element from stack \n 3.display elemnts of stack \n 4. exit code \n ");
            scanf("%d",&ch);
            switch(ch){
                case 1 :  printf("enter the value :\n");
                          scanf("%d",&value);
                          push(value);
                          break;
                case 2 :  pop();
                          break;
                case 3 : display();
                         break;
                case 4 : printf("......exiting.....");
                        return 0;
                default : printf("invalid choice \n");
            }
    }
}