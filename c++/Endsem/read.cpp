#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    int count=0 ;
    ifstream fin;
    string c;
    fin.open("practice.txt");
    while(getline(fin,c)){
        cout<<c<<endl;
         count=count +1;
    }
    cout<<count;
    fin.close();
}