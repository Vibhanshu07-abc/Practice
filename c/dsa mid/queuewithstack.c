#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack1[max];
int stack2[max];
int top1=-1;
int top2=-1;
void push1(int value){
     if(top1==max-1){
     }
     else{
        stack1[++top1]=value;
     }
}
void push2(int value){
     if(top2==max-1){
     }
     else{
       stack2[++top2]=value;
     }
}
int pop1(){
    if(top1==-1){
    }else{
        return stack1[top1--];
    }
}
int pop2(){
    if(top2==-1){
    }else{
        return stack2[top2--];
    }
}
void enque(int value){
     push1(value);
}
void dequeue(){
    int a,b;
    if(top1==-1&&top2==-1){
        printf("queue is empty \n");
    }else{
         while(top1!=-1){
            a=pop1();
            push2(a);
         }
        b= pop2();
        printf("value dequed is %d \n",b);
        while(top2!=-1){
            b=pop2();
            push1(b);
        }
    }
}
int main(){
   int ch,value,i,n;
   while(1){
      printf("enter 1 to enueue value \n  enter 2 to dequeue value \n enter 3 to exit code \n");
      scanf("%d",&ch);
      switch(ch){
        case 1 : printf("enter the value to be inserted : \n");
                 scanf("%d",&value);  
                   enque(value);
                   break;
        case 2 : dequeue();
                break;
        case 3 :  printf("----exiting----\n");
              return 0;
        default : printf("invalid input \n");
      }
   }
}