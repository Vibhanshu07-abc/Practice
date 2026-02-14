#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,i,n,m,j,k;
    int *ptr1;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
      printf("memory allocation failed");
      return 1;
    }
        printf("-----enter the elements-----\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",(ptr+i));
        } 
    printf("enter the total size you want to increase\n");
    scanf("%d",&m);
       k= n+m;
      ptr1=(int*)realloc(ptr,k*sizeof(int));
      if(ptr1==NULL)
      {
        printf("memory allocation failed");
        return 1;
      }
      ptr=ptr1;
printf("----enter new elements---\n");
for(j=n;j<k;j++)
{
    scanf("%d",(ptr+j));
}
printf("---the elements are--- ");
for(i=0;i<k;i++)
{
    printf("%d\n",*(ptr+i));
}
printf("\n");
free(ptr1);
return 0;
}