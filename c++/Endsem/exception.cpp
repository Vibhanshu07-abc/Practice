#include<iostream>
#include<string>
using namespace std;
class bank {
    int account_id ;
    string accountholder;
    int balance;
    public :
    bank(string a,int b,int c){
        accountholder=a;
        account_id=b;
        balance=c;
    }
    void deposit(int dep){
      if(dep<=0){
        throw "invalid Amount ";
      }
      else{
         balance+=dep;
      }
    }
    void withdraw(int with){
        if(with<=0){
            throw "invalid amount";
        }
        else if(with>balance){
            throw"insufficient balance ";
        }
        else{
             balance-=with;
        }
    }
    void displayinfo(){
        cout<<"the name of the user is :\t"<<accountholder<<endl;
        cout<<"the account holder id is :\t"<<account_id<<endl;
        cout<<"the balance left in account is "<<balance<<endl;
    }
};
int main(){
    bank a("vibhanshu",62,10000);
    try{
        a.deposit(-5);
       // a.withdraw(1000000);
    }
    catch(const char *e){
        cout<<"error is : "<<e<<endl;
    }
    try{
        a.withdraw(100);
    }
    catch(const char *e){
        cout<<"error is : "<<e<<endl;
    }   
     a.displayinfo();   
}