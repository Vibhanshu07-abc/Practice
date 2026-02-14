#include <iostream>
using namespace std;

class Box {
public:
    int width;
    //default 
    box(){

    }
    // paramatrised  constructor
    Box(int w) {
        width = w;
    }

    // Copy constructor
    Box(const Box & other) {
      width = other.width;
       cout << "Copy constructor called\n";
   }
};

int main() {
    Box a(10);      // normal constructor
    Box b=a;      // copy constructor
    
    cout << "a.width = " << a.width << endl;
    cout << "b.width = " << b.width << endl;
}
