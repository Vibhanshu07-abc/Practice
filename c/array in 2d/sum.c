#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,m,n;
   printf("enter the no of rows");
    scanf("%d",&m);
    printf("enter the no of columns");
    scanf("%d",&n);
    int a[m][n];
    printf("enter the elements in 1st matrix");
     for(int i=0;i<m;i++)
     {
        for(int j=0; j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
     }
     int b[m][n];
     printf("enter the elements in 2nd matrix");
  
     for(int i=0;i<m;i++)
     {
        for(int j=0; j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
        printf("\n");
     }
     
     int res[m][n];
     for(int i=0;i<m;i++)
     {
        for(int j=0; j<n;j++)
        {
            res[i][j]=a[i][j]+b[i][j];   
        } 
     }
        
        for(int i=0;i<m;i++)
        {
           for(int j=0; j<n;j++)
           {
               
               printf(" %d",res[i][j]);
           }
           printf("\n");
        }
}
