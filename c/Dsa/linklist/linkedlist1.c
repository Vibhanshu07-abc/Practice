#include<stdio.h>
#include<stdlib.h>
struct node{
 int data ;
 struct node* next;
};

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

head=(struct node*)malloc(sizeof(struct node));
first=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));

head->data=29;
head->next=first;
first->data=28;
first->next=second;
second->data=26;
second->next=NULL;
 transversal(head);
 free(head);
 free(first);
 free(second);
 return 0;
}


