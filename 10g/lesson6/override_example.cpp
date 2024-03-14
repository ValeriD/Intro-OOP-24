#include <iostream>
#include <vector>

using namespace std;

class Base
{
protected:
public:
    Base()
    {
    }

    virtual void print() const // Virtual is a keyword that tells the compiler that this function can be replaced by a function with the same signature in a derived class.
    {
        cout << "Base print" << endl;
    }
};

class Child : public Base
{
public:
    Child()
        : Base()
    {
    }

    void print() const override // We have to tell the compiler that we are replacing the Base::print with this one.
    {
        cout << "Child print" << endl;
    }
};

int main()
{
    vector<Base *> arr; // The type needs to be pointers, so we can skip casting. (https://stackoverflow.com/questions/74893562/c-casting-how-does-casting-really-works)
    for (int i = 0; i < 3; i++)
    {
        if (i % 2 == 0)
            arr.push_back(new Base());
        else
            arr.push_back(new Child());
    }
    for (int i = 0; i < 3; i++)
    {
        arr[i]->print();
    }

    return 0;
}