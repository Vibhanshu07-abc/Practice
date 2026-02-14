#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    for(int val:vec){
    cout<<val<<"\n";
    }
   vec.erase(vec.begin()+1,vec.begin()+3);
   vec.insert(vec.begin()+1,100);
   cout<<"after deletion\n";
   for(int val:vec){
    cout<<val<<"\n";
   }
   cout<<"the element at 2 is : \t"<<vec[2]<<endl;;
   cout<<"the size of vector is \t "<<vec.size()<<endl;//4
   cout<<"the capacity of vector is \t"<<vec.capacity()<<endl;//8
}