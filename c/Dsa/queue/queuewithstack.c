#include<stdio.h>
#include<stdlib.h>
#define max 20
int s1[max],s2[max];
int top1=-1;
int top2=-1;
int count;
void push1(int x){
    if(top1==max-1){
     printf("stack is empty :\n");
    }
    else{
      top1++;
      s1[top1]=x;
    }
}
void push2(int x){
    if(top2==max-1){
     printf("stack is empty :\n");
    }
    else{
      top2++;
      s2[top2]=x;
    }
}
int pop1(){
    if(top1==-1){
    printf("stack is empty :\n");
    }
    else{
        int value=s1[top1];
        top1--;
       return value;
    }
}
int pop2(){
    if(top2==-1){
    printf("stack is empty :\n");
    }
    else{
        int value=s2[top2];
        top2--;
       return value;
    }
}
void enqueue(int x){
    push1(x);
    count++;
}
void dequeue(){
    int a,b;
    if(top1==-1&&top2==-1){
        printf("queue is empty :\n");
    }
    else{
        for(int i=0;i<count;i++){
           a=pop1()
            push2(a);
        }
        b=pop2();
        printf("value enqueued is %d",b);
        count--;
        for(int i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}
void display(){
    int i;
    for(i=0;i=<top1;i++){
        printf(" %d\n",s1[i]);
    }
}