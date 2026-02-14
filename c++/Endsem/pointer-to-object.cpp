#include <iostream>
#include <string>
using namespace std;

class Cricketer {
public:
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg) {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
};
void change (Cricketer *c){
    c->avg=100;
}
int main() {
    Cricketer c1("Virat Kohli", 25000, 55.2);
    Cricketer c2("Rohit Sharma", 18000, 47.8);

    Cricketer* p1 = &c1;
     
    cout << (*p1).runs << endl;  // Accessing runs using pointer
    cout << p1->name << endl;    // Accessing name using arrow operator
    cout<<p1->avg<<endl;
    change(&c1);
    cout<<p1->avg<<endl;
    return 0;
}
