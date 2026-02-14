#include<stdio.h>
int main(){
    int n,count=0;
    printf("enter the rows and column \n");
    scanf("%d %d",&n);
    printf("enter element in array\n");
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(i>j && arr[i][j]!=0){
                count=1;
            }
        }
    }
    if (count==0){
        printf("upper triangular matrix \n");
    }else{
        printf("not a upper triangular matrrix \n");
    }
}
