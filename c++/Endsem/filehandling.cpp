#include<iostream>
#include<fstream>
using namespace std;
int main(){
   // ofstream write;
    //write.open("practice.txt");
    //write<<"first code in file handling ";
    //write.close();
    ifstream read;
    read.open("practice.txt");
    char c=read.get();
    while(!read.eof()){
        cout<<c;
        c=read.get();
    }
    read.close();
}