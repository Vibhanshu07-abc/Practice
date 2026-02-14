#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ;
    struct node*next;
}l;
l* reverse(l*head){
    l*current=head,*ad=head;
    l*prev=NULL;
    while(current!=NULL){
        ad=ad->next;
        current->next=prev;
        prev=current;
        current=ad;
    }head=prev;
    return head;
}
void deletekfromend(l**head,int index){
if((*head)==NULL){
printf("cannot  list empty\n");
}
      *head= reverse(*head);
       l*temp=(*head);l*prev=NULL;
 if(index==1){
       (*head)=temp->next;
         printf("deleted successfully %d \n",temp->data);
       free(temp);  
     
     }
  else{
     for(int i=1;(i<index)&&(temp!=NULL);i++){
     prev=temp;
     temp=temp->next;
     }
     if(temp==NULL){
     printf("node not found \n");
     }else{
           prev->next=temp->next;
           printf("node deleted successfully is %d \n",temp->data);
           free(temp);
           
     }
  }
   *head= reverse(*head);
}
void createnode(l**head,int value){
    l*newnode=(l*)malloc(sizeof(l));
    newnode->next=NULL;
    newnode->data=value;
    l*temp=*head;
    if((*head)==NULL){
        temp=*head=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void palindrome(l* head) {
    if (head == NULL || head->next == NULL) {
        printf("palindrome\n");
        return;
    }

    // Step 1: Find middle (slow will be at middle)
    l *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    l *secondHalf = reverse(slow);
    l *firstHalf = head;

    // Step 3: Compare halves
    int isPalindrome = 1;
    l *copySecond = secondHalf; // keep copy if you want to restore
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            isPalindrome = 0;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    if (isPalindrome)
        printf("palindrome\n");
    else
        printf("not palindrome\n");

    // (Optional) Restore second half if needed
     reverse(copySecond);
}
int main(){
    int ch,value,index;
    l*head=NULL;
    while(1){
        printf("enter the choice : \n 1.enter an element \n 2.display palindrome \n 3. exit code \n 4.delte fom end\n ");
            scanf("%d",&ch);
            switch(ch){
                case 1 :  printf("enter the value :\n");
                          scanf("%d",&value);
                         createnode(&head,value);
                          break;
                case 2 :  palindrome(head);
                          break;
                
                case 3 : printf("......exiting.....");
                        return 0;
                case 4 : printf("delete from kth elemnet from end \n");
                          scanf("%d",&index);
                          deletekfromend(&head,index);
                          break;
                default : printf("invalid choice \n");
            }
    }
}