#include<stdio.h>
int main(){
    int n;
    printf("enter the rows and column \n");
    scanf("%d",&n);
    printf("enter element in array\n");
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int arr2[n][n];
    printf("enter element in array\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    int res[n][n];
     printf(" element in array re\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=arr[i][j]-arr2[i][j];
            printf("%d\n",res[i][j]);
        }
    }
   return 0;
}
