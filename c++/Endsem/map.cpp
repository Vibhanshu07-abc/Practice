#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>m;
    m["apple"]=100;
    m["mango"]=200;
    m["litch"]=123;
    m["pinea"]=150;
    m.insert({"ayush",678});
    m.emplace("p",456);
    m.erase("p");
    cout<<" found \t "<<m.count("apple")<<endl;
        cout<<"__________"<<endl;
    for(auto p:m){
        cout<<"|"<<p.first<<"|"<<p.second<<"|"<<endl;
    }
    cout<<"_________"<<endl;
}