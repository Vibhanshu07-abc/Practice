#include<iostream>
using namespace std;
namespace myspace1 {
void calculate(int a){
    for(int i=0;i<10;i++){
     cout<<a*i<<endl;
    }
}
}
namespace myspace2{
    void calculate(int a){
cout<<a*a<<endl;
    }
}
int main(){
    
  // myspace1::calculate(4);
    myspace2::calculate(4);
}