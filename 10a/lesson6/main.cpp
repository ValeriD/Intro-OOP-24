#include <iostream>

using namespace std;

class Base
{
    int a;

public:
    Base()
    {
        cout << "Hello from Base constructor" << endl;
    }

    Base(int a)
    {
        cout << "Hello from Base param constructor" << endl;
    }

    Base(const Base &other)
    {
        cout << "Hello from Base copy constructor" << endl;
    }

    ~Base()
    {
        cout << "Hello from Base destructor" << endl;
    }

    void print() const
    {
        cout << "Hello from base" << endl;
    }

protected:
private:
};

class Child : public Base
{
    string a;

public:
    Child()
        : Base()
    {
        cout << "Hello from Child constructor" << endl;
    }

    Child(int a)
        : Base(a)
    {
        cout << "Hello from Child param constructor" << endl;
    }

    Child(const Child &other)
        : Base(other)
    {
    }

    ~Child()
    {
        cout << "Hello from Child destructor" << endl;
    }

    Child &operator=(const Child &other)
    {
        if (this != &other)
        {
            Base::operator=(other);
            cout << "Hello from Child copy assign operator" << endl;
        }
        return *this;
    }

    void print2() const
    {
        cout << "Hello from child" << endl;
    }

    const string &getA() const { return a; }
};

int main()
{
    /*
    Child child;

    cout << child.getA() << endl;
    child.getA() = "Test";

    cout << child.getA() << endl;
    */

    // Base b;

    Child c;
    cout << "----------------" << endl;
    return 0;
}