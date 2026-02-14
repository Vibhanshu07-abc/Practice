#include<stdio.h>
int main(){
    int n,m,count=0;
    printf("enter the rows and column \n");
    scanf("%d %d",&n,&m);
    printf("enter element in array\n");
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    if (count>(m*n)/2){
        printf("sparse matrix \n");
    }else{
        printf("not a sparse matrrix \n");
    }
}
