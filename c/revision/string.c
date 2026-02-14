/*#include <stdio.h>
int main(){
int i=0;
int size=0;
int j=0,k=0;
char str[100];
printf("enter a string \n");
gets(str);
while(str[k]!='\0')
{
    size++;
    k++;
}
for(i=0, j=size-1;i<j;i++,j--)
{
    char temp= str[i];
    str[i]=str[j];
    str[j]= temp;
}
printf("the reverse of string is %s\n",str);
}*/
 struct employee{
        char name[20];
        int Emp_code;
        float salary;
    };
    void display(struct employee arr[]);
int main(){
    int i;
    int n;
   
    struct employee arr[i];
    printf("enter total no of employee:\n ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("enter the name of the employee:\n");
        fgets(arr[i].name,20,stdin);
        printf("enter the employee code :\n");
        scanf("%d",&arr[i].Emp_code);
        printf("enter the salary:\n");
        scanf("%f",&arr[i].salary);
    }
    display(arr[]);
}
  void display(struct employee arr[i])
  {
    int n;
    int i;
  for (i=0;i<n;i++)
    {
        printf(" the name of the employee%s\n",arr[i].name)
        printf(" the employee code :%d\n",arr[i].Emp_code);
        printf("enter the salary:%f\n",arr[i].salary);
    }
}