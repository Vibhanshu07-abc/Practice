#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node*next;
}s;
s*push(int x,s**top){
    s*temp;
    temp=(s*)malloc(sizeof(s));
    temp->data=x;
    temp->next=(*top);
    (*top)=temp;
    return *top;
}
s*pop(s**top){
    s*temp=*top;
    if(*top==NULL){
        printf("stack is empty\n");
    }
    (*top)=(*top)->next;
    printf("the deleted value is   %d\n",temp->data);
    free(temp);  
    return *top;   
}
void display(s**top){
    s*temp;
    temp=*top;
    while(temp!=NULL){
        printf(" %d\n",temp->data);
        temp=temp->next;
    }
}
void peek(s**top){
    s*temp=*top;
    printf("top is pointing to %d\n",temp->data);
}
int main(){
    s*top=NULL;
   push(5,&top);
   push(6,&top);
   push(7,&top);
   push(10,&top);
   pop(&top);
   display(&top);
   peek(&top);
}