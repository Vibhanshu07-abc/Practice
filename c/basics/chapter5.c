#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr1;
    int *ptr;
    int i,k,n,m;
    int sum=0;
    printf("enter the size of array\n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL){
        printf("error in memo alocation:\n");
    }
    else{
    printf("enter the elements in array:\n");
    for(i=0;i<n;i++){
     scanf("%d",(ptr+i));
    }
}
    printf("enter the total number blocks you want to increase :\n");
    scanf("%d",&m);
    k=n+m;
    printf("enter new elements\n");
    ptr1=(int*)realloc(ptr,k*sizeof(int));
    if(ptr1==NULL){
        printf("memory allocation failed:\n");
    }
    else{
        for(i=n;i<k;i++){
            scanf("%d",(ptr1+i));
        }
    }
    for(i=0;i<k;i++){
        sum=sum + *(ptr1+i);
    }
    printf("the sum of all the elemnts is :%d \n",sum);
}
