/*void delseclastnode(l**head){
    l*p=*head;
    l*prev=NULL;
    if(*head==NULL){
        printf("list empty \n");
    }else if((*head)->next==NULL){
        (*head)=(*head)->next;
        free(p);
    }else{
        while(p->next->next!=NULL){
           prev=p;
           p=p->mext;
        }
        prev->next=p->next;
        free(p);
    }
}*/
/*void palindrome(char str1[]){
    char str2[max];
    int i=0,flag=1;
    strcpy(str2,str1);
    while(str1[i]!='\0'){
        push(str1[i]);
        i++;
    }
    i=0;
    while(str2[i]!='\0'){
        char ch=pop();
        if(str2[i]!=ch){
            flag=0;
            break;
        }
        i++;
    }
    if(flag!=1){
        printf("not palindrome \n");
    }else{
        printf("palindrome \n");
    }
}*/
/*
    void deletekthelement(struct node**head,int index){
    struct node*temp=*head,*prev;
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

    void convertodecimal(l*head){
    int decimal=0,n=0;
      if(head==NULL){
      return ;
      }
      else{
        return(head->next);
         decimal=(head->data)*(2^n)+decimal;
         n++;
      }
    }
  
l*cycledetectio(l*head){
l*slow=head;l*fast=head;
int flag=0;
while(fast!=NULL&&fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
if(fast==slow){
     flag=1;
     break;
}
}
if(flag!=1){
printf("cycle not detected \n");
return NULL;
}else{
    slow=head;
    while(slow!=NULL&&slow->next!=NULL){
       slow=slow->next;
       fast=fast->next;
       if(slow==fast){
       printf("cycle detected \n");
       return slow;
       }
    }

}
return NULL;
}
void deletekfromend(l**head,int index){
if((*head)==NULL){
printf("cannot reverse list empty\n");
}
       reverse(head);
       l*temp=(*head);l*prev;
 if(index==0){
       (*head)=temp->next;
       free(temp);  
       printf("deleted successfully \n");
     }
  else{
     for(int i=1;i<index&&temp!=NULL;i++){
     prev=temp;
     temp=temp->next;
     }
     if(temp==NULL){
     printf("node not found \n");
     }else{
           prev->next=temp->next;
           free(temp);
           printf("node deleted successfully\n");
     }
  }
     reverse(head);
}



*/