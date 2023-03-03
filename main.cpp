/*
 * In the example, we have a class B which inherits from a class A. When we try to construct an instance of B,
 * it needs to construct its base object of A. So, it calls A ctor.
 * Then, in its constructor, the class B has an initialization list which also needs
 * to construct two A instance members, A x and A y. So, it calls A ctor twice with different m member
 * for each instance of A. After that, it finally executes the body of B ctor.

    //A ctor at B(int n)
    //Construct A obj x at x(m+1)
    //Construct A obj y at y(n)
    //B ctor and execute its body
 * */

#include <iostream>
using namespace std;

class A { // Base class
public:
    A(int n = 7) : m(n) { // Constructor with default argument and initializer list
        cout << "A() n = " << n << " m = " << m << endl;
    }

    ~A() { // Destructor
        cout << "~A() m = " << m << endl;
    }

protected: // Protected data member
    int m;
};

class B : public A { // Derived class B from class A
public:
    // (1) A ctor at B(int n)
    // (2) Construct A obj x at x(m+1)
    // (3) Construct A obj y at y(n)
    // (4) B ctor and execute its body
    B(int n) : x(m + 1), y(n) {
        cout << "B() n = " << n << endl;
    }

public:
    // (1) dtor of B
    // (2)-(4) dtor of A
    ~B() {
        cout << "~B() m = " << m << endl;
        --m;
    }

private:
    A x; // (2) Construct A obj x at x(m+1)
    A y; // (2) Construct A obj y at y(m+1)
};

int main() {
    {
        B b(10);
    }

    return 0;
}