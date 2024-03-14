#include <iostream>
#include <vector>

using namespace std;

class Base
{
protected:
public:
    Base()
    {
        cout << "Base default constructor" << endl;
    }

    Base(int a)
    {
        cout << "Base constructor with parameters" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
    Base(const Base &other)
    {
        cout << "Base copy constructor" << endl;
    }

    Base &operator=(const Base &other)
    {
        cout << "Base copy operator =" << endl;

        return *this;
    }
};

class Child : public Base
{
    int b;

public:
    Child()
        : Base(1), b(1)
    {
        cout << "Child default constructor" << endl;
    }

    ~Child()
    {
        cout << "Child destructor" << endl;
    }

    Child(const Child &other)
        : Base(other)
    {
        cout << "Child copy constructor" << endl;
    }

    Child &operator=(const Child &other)
    {
        Base::operator=(other);
        cout << "Child copy operator =" << endl;

        return *this;
    }
};

int main()
{
    Child c;

    Child c2 = c;

    Base b = c;
    // Child c3 = b; //Invalid
    return 0;
}