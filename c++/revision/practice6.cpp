/*#include<iostream>
using namespace std;
int main(){
   int n,max=0,index=0;
   int arr[n],i;
   int sum[n-2];
   cout<<"enter the size of array : "<<endl;
   cin>>n;
   cin.ignore();
   cout<<"enter the elements in array : "<<endl;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   while(( i+2)<n){
      index=0;
      sum[i]=arr[i]+arr[i+1]+arr[i+2];
      if(sum[i]>max){
        max=sum[i];
        index=i+1;
      }
      i++;
   }
   cout<<"special sum is : "<<max<<"special integer is :"<<arr[index-1]<<"position of inter is "<<index<<endl;
}*/
/*#include<iostream>
using namespace std;
class student{
    private :
    int score[5];
    public :
    void input(){
        cout<<"enter the marks of students :"<<endl;
        for(int i=0;i<5;i++){
            cin>>score[i];
        }
    }
    int calc(){
        int sum=0;
        for(int i=0;i<5;i++){
            sum=sum+score[i];
        }
        return sum;
    }
};
int main(){
    int n,count=0;
    cout<<"enter the number of students :"<<endl;
    cin>>n;
    student s[n];
    for(int i=0;i<n;i++){
        cout<<"student "<<i+1<<endl;
        s[i].input();
    }
    //let annas score s[0]
    int annascore=s[0].calc();
    for(int i=1;i<n;i++){
       if(s[i].calc()>annascore){
        count=count +1;
       }
    }
    cout<<"annas total score is :"<<s[0].calc()<<endl;
    if(count==0){
        cout<<"no scored more than anna :"<<endl;
    }else{
        cout<<"no of students score more than ana are :"<<count<<endl;
    }
}*/
#include<iostream>
using namespace std;
int calc(int x){
    return x*x;
}
int calc(int x,int y){
    return x*y;
}
   int calc(int x,int y) {
    return x*y*0.5;
   }
   int main(){
    int areaoftriangle=calc(3,5);
   }