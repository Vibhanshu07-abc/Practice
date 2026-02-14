#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"enter input \n";
    cin>>n;
    vector<int >vec(n);
    cout<<"enter the number of element you want to insertin vector 1\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>v2={11,12,13,14,15};
    vector<int>v3;
    // cout<<"merging \n";
   //sort(vec.begin(),vec.end());
    sort(vec.begin(),vec.end(),greater<int>());
    cout<<"printing \n";
    for(auto it=vec.begin();it!=vec.end();it++){
        cout<<*(it)<<endl;
    }
}