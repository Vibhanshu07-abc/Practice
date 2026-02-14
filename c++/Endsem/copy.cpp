#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream read;
    ofstream write;
    read.open("practice.txt");
    write.open("sample.txt");
    char c;
    while(read.get(c)){
        write.put(c);
    }
    read.clear();
    read.seekg(0);
    while(read.get(c)){
        cout<<c;
    }
    write.close();
    read.close();
}
