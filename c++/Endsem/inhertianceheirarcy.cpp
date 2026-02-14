#include <iostream>
using namespace std;

class A {
public:
    A() { callA = 0; }
    void func(int &val) {
        val *= 2;
        callA++;
    }
    int callA;
};

class B {
public:
    B() { callB = 0; }
    void func(int &val) {
        val *= 3;
        callB++;
    }
    int callB;
};

class C {
public:
    C() { callC = 0; }
    void func(int &val) {
        val *= 5;
        callC++;
    }
    int callC;
};

class D : public A, public B, public C {
public:
    D() { val = 1; }

    void update_val(int new_val) {
        while (new_val % 2 == 0) {
            A::func(val);
            new_val /= 2;
        }
        while (new_val % 3 == 0) {
            B::func(val);
            new_val /= 3;
        }
        while (new_val % 5 == 0) {
            C::func(val);
            new_val /= 5;
        }
    }

    void check(int new_val) {
        update_val(new_val);
        cout << "A's func called " << callA << " times" << endl;
        cout << "B's func called " << callB << " times" << endl;
        cout << "C's func called " << callC << " times" << endl;
    }

    int val;
};

int main() {
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
    return 0;
}
