#include<stdio.h>
void main()
{
    int r,c,i,j;
    printf("enter the no of rows");
    scanf("%d",&r);
    printf("enter the no columns");
    scanf("%d",&c);
    int a[r][c];
    printf("enter the no elements");
    for(int i =0;i<r;i++)
    {
        for(int j=0; j<c; j++)
        {
        scanf("%d",&a[i][j]);
        }

    }
    int maxsum=0;
   
    for(int i =0;i<r;i++)
    {   int sum=0;
        for(int j=0; j<c; j++)
        {
            sum=sum+a[i][j];
        }
        {if(maxsum<sum)
            {
              maxsum=sum;
            }
        }

    }
      printf("max sum is %d",maxsum);
}