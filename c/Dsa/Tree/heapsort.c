#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}
void maxheapify(int arr[],int n,int i){
int largest=i;
int l=2*i+1;
int r=i*2+2;
if(l<n && arr[largest]<arr[l]){
    largest=l;
}
if(r<n && arr[largest]<arr[r]){
    largest=r;
}
if(largest !=i){
    swap(&arr[largest],&arr[i]);
    maxheapify(arr,n,largest);
}
}
void  heapsort(int arr[],int n){
    int i;
   //build max heap 
   for(i=(n/2)-1;i>=0;i--){
    maxheapify(arr,n,i);
   }
   //deletion
   for(i=n-1;i>=0;i--){
    swap(&arr[i],&arr[0]);
    maxheapify(arr,i,0);
   }
}
int main(){
    int n;
    
    printf("enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter [%d]",i+1);
        scanf("%d",&arr[i]);
    }
    printf("enterd current array is  :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    heapsort(arr,n);
    printf("\n");
    printf("sorted current array is  :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}