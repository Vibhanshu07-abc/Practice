#include<iostream>
usnig namespace std;
class employee {
    private:
    int arr[5];
    int n;
    public:
    void input(){
        cout<<"enter the scores of employee"<<":\n";
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
    }
  int calc(){
    int sum =0;
    for(int i=0;i<4;i++){
        sum=sum+arr[i];
    }
    return sum;
  }    
};
int main(){
    int m;
    cout<<"enter the number of employee :"<<endl;
    cin>>m;
    employee s[m];
    
    cout<<"enter the scores of employee : "<<endl;
    for(int i=0;i<m;i++){
        cin>>s[i].input();
    }
    int john =s[0].calc();
    int count=0;
    for(int i=1;i<m;i++){
        if(john<s[i].calc()){
            count+=1;
        }
    }
cout<<"employee with scores more than john are :"<<count<<endl;


}