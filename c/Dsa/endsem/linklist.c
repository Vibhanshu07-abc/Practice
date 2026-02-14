l* intersection(l*head1,l*head2){
    int len1=0;
    int len2=0;
    int diff;
    l*p=head1;l*q=head2;
    while(p){
        len1++;
        p=p->next;
    }
    p=head1;
     while(q){
        len2++;
        q=q->next;
    }
    q=head2;
    if(len1>len2){
        diff=len1-len2;
        for(int i=1;i<diff&&p->next!=NULL;i++){
            p=p->next;
        }
    }else{  
        diff=len2-len1;
        for(int i=1;i<diff&&q->next!=NULL;i++){
            q=q->next;
        }
    }
    while(p!=NULL&&q!==NULL){
        if(p==q){
            return p;
        }
        p=p->next;
        q=q->next;
    }
    return NULL;
}