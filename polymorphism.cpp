#include <bits/stdc++.h>
using namespace std;

// ---------------- Parent Class -----------------
class Parent
{
    int x, y;  // Private variables (cannot be accessed directly in Child)

public:

    // Constructor of Parent class
    Parent(int a, int b){
        cout << "Parent Constructor" << endl;
        cout << "X at Parent is : " << a << endl;
        cout << "Y at Parent is : " << b << endl;
    }

    // 'virtual' means this method can be overridden in child class
    virtual void show(){   
        cout << "This is parent's show" << endl;
    }

    // A normal method (not virtual)
    void method(){
        cout << "This is Method" << endl;
    }
};

// ---------------- Child Class -----------------
class Child : public Parent
{
public:

    // Child constructor, but it must call Parent constructor first
    // Here Parent(20,30) is called before anything else
    Child(int a) : Parent(20, 30){
        cout << "Child Constructor" << endl;
        cout << "X at Child is : " << a << endl;
    }

    // Overriding the parent's show() method
    void show() override {   
        // Calling parent's version explicitly
        Parent::show();

        // Child's own show behavior
        cout << "This is child's show" << endl;

        // Calling parent's normal method
        Parent::method();
    }
};

// ---------------- Main Function -----------------
int main()
{
    // Creating Child object
    // This will call:
    // 1) Parent constructor
    // 2) Then Child constructor
    Child val(12);

    // Calls Child's overridden show() method
    val.show();   

    return 0;
}

// Parent Constructor
// X at Parent is : 20
// Y at Parent is : 30
// Child Constructor
// X at Child is : 12
// This is parent's show
// This is child's show
// This is Method
