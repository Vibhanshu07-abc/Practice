#include<stdio.h>
#include<stdlib.h>
typedef struct node {
 int data;
struct node*prev;
struct node*next;
}d;
 void traversal(d*head){
    d*temp=head;
    printf("the nodes are \n");
    while(temp!=NULL){
        printf(" %d\n",temp->data);
        temp=temp->next;
    }
 }
 /*d*insertatstart(d*head){
    d*new;
    new=(d*)malloc(sizef(d));
    printf("enter the element\n");
    scanf("%d",&new-data);
    new->next=NULL;
    new->prev=NULL;
    head->prev=new;
    new->next=head;
    head=new;
    return new;
 }*/


d* create(d*head,d**tail){
  
  d*newnode;
  d*temp;
  newnode=(d*)malloc(sizeof(d));
  if(newnode==NULL){
    printf("memory allocation failed\n");
    exit(1);
  }
   else{
      printf("enter data in new node :\n");
      scanf("%d",&newnode->data);
      newnode->prev=NULL;
      newnode->next=NULL;
      if (head==NULL){
        head=(*tail)=newnode;
      }
      else {
            (*tail)->next=newnode;
            newnode->prev=(*tail);
            (*tail)=newnode;
      }      
   }
       return head;
   }
   void count(d*head){
    int count=0;int k;
    printf("enter the value of k\n");
    scanf("%d",&k);
    d*temp=head;
    while(temp!=NULL){
      if((temp->data)%k==0){
         printf("%d\n",temp->data);
         count++;
      }
      temp=temp->next;
    }
      if(count!=0){
         printf("the number of nodes divisible by %d = %d \n ",k,count);
      }else{
         printf("no nodes are divisible by %d :\n",k);
      }
   }
   
int main(){
   d*head=NULL;
   d*tail=NULL;
   int n;
   printf("enter number of nodes \n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   head=create(head,&tail);
   count(head);
    traversal(head);

}
