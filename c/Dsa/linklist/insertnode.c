#include<stdio.h>
#include<stdlib.h>
struct node{
 int data ;
 struct node* next;
};
struct node*firstnode(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node*inbetween(struct node*head,int index, int data){
    struct node* temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    int i=0;
    while(i!=index-1){
      temp=temp->next;
      i++;
    }
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node*atend(struct node*head,int data)
{     struct node*p=head;
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
     while(p->next!=NULL){
        p=p->next;
     }
     ptr->data=data;
     p->next=ptr;
    ptr->next=NULL;
    return head;
}
void transversal(struct node*ptr){
while(ptr!=NULL){

    printf("the data of structure is %d\n",ptr->data);
    ptr=ptr->next;
}
}

int main(){

struct node*head;
struct node*first;
struct node*second;
struct node*ptr;

head=(struct node*)malloc(sizeof(struct node));
first=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
ptr=(struct node*)malloc(sizeof(struct node));
head->data=29;
head->next=first;
first->data=28;
first->next=second;
second->data=26;
second->next=NULL;
ptr->data=10;
ptr->next=head;
head=ptr;
 transversal(head);
//head=firstnode(head,20);
//printf("after function-1\n");
//transversal(head);
//head=inbetween(head,2,56);
head=atend(head,68);
printf("after function-2\n");
transversal(head);
 free(head);
 free(first);
 free(second);
 return 0;
}