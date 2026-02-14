#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node*next;
}l;
l*createnode(l*head,int value){
    l*temp=head;
    l*newnode=(l*)malloc(sizeof(l));
    if(newnode==NULL){
        printf("memory allocation failed\n");
        return head;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL) {
        head=temp=newnode;
    }
    else{
         while(temp->next!=NULL){
        temp=temp->next;
         }
         temp->next=newnode;
    }
    return head;
}
l*reverse(l*head){
    l*prev=NULL;
    l*current=head;
    l*next=head;
    while(next!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("linklist reversed succcessfully \n");
    return head;
}
void display(l*head){
    l*temp=head;
if(head==NULL){
    printf("list is empty \n");
}else{
    printf("the data of the linked list is :\n");
    while(temp!=NULL){
      printf("%d\n",temp->data);
      temp=temp->next;
    }
}
}
void deletekthelement(l**head,int index){
    l*temp=(*head),*prev;
    if((*head)==NULL) return;
    else if(index==0){
    *head=temp->next;
      free(temp);
      return;
    }else{
          for(int i=1;i<index&&temp!=NULL;i++){
              prev=temp;
              temp=temp->next;
          }
            if(temp==NULL){
              printf("element not found \n");
              return;
            }else{
               prev->next=temp->next;
               free(temp);
            }  
    }
    }
    int convertodecimal(l*head){
        int decimal=0;l*temp=head;
        while(temp!=NULL){
            decimal=(decimal<<1)+temp->data;
            temp=temp->next;
        }
        return decimal;
    }
    
int main(){
    l*head=NULL;
    int ch,value,N,index;
    int decimal;
    while(1){
        printf("create node enter 1 :\n enter 2 to reverse node :\n enter 3 to display :\n enter 4 to exit \n");
        printf("enter 5 to delete from k position :\n enter 6 to covert decimal\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:  printf("enter the no of nodes to be added :\n");
                     scanf("%d",&N);
                     for(int i=0;i<N;i++){
                        value=0;
                        printf("enter the value of node %d : \n",i+1);
                        scanf("%d",&value);
                        head=createnode(head,value);
        }
        break;
        case 2 : head=reverse(head);
        break;
        case 3 : display(head);
        break;
        case 4 :   return 0;
        case 5 :   printf("enter the index from which you want to delete \n");
                    scanf("%d",&index);
                    deletekthelement(&head,index);
                    break;
        case 6 :  decimal= convertodecimal(head);
                printf("the decimal is %d\n",decimal);
                break;
        default : printf("invalid input : ");
    } 
    }
}