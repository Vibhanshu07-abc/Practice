#include<stdio.h>
#include<stdlib.h>
struct node{
 int data ;
 struct node* next;
};
struct node*deletehead(struct node*head){
 struct node*ptr=head;
 head=head->next;
 free(ptr)
  return head;
}
struct node*delidx(struct node*head,int index){
    struct node*ptr=head;
    struct node*p;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    } 
    p=ptr->next; 
    ptr->next=p->next;
    free(p);
   return head;
}

struct node*atend(struct node*head){
       struct node*prev=head;
       struct node*p=head->next;
     while(p->next!=NULL){
     prev=prev->next;
     p=p->next;
     }
     prev->next=NULL;
     free(p);
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
struct node*third;

head=(struct node*)malloc(sizeof(struct node));
first=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));
head->data=29;
head->next=first;
first->data=28;
first->next=second;
second->data=26;
second->next=third;
third->data=10;
third->next=NULL;
transversal(head);
printf("after operation:\n");
//head=deletehead(head);
//head=delidx(head,2);
head=atend(head);
transversal(head);
 free(head);
 free(first);
 free(second);
 free(third);
 return 0;
}