#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class Base
{
    int b;
    char *tmp;

protected:
    int a;
    virtual bool validateA(int a) const = 0;

public:
    virtual void printHello() const
    {
        cout << "Hello from Base" << endl;
    }
    int getA() const { return a; }
    void setA(int a)
    {
        validateA(a);
        this->a = a;
    }
    virtual ~Base()
    {
        delete[] tmp;
    }
};

class Child : public Base
{
protected:
    bool validateA(int a) const override
    {
        if (a > 0)
        {
            throw invalid_argument("getA() - a is positive");
        }
        return true;
    }

public:
    void printHello() const override
    {
        cout << "Hello from Child" << endl;
    }
};

class Child2 : public Base
{

    char *tmp1;

protected:
    bool validateA(int a) const override
    {
        if (a < 0)
        {
            throw invalid_argument("getA() - a is negative");
        }
        return true;
    }

public:
    Child2() : Base()
    {
    }
    
    void printHello() const override
    {
        cout << "Hello from Child2" << endl;
    }
    ~Child2()
    {
        delete[] tmp1;
    }
};

int main()
{

    Child c;

    c.setA(-1);
    cout << c.getA() << endl;

    Child2 c2;
    c2.setA(5);
    cout << c2.getA() << endl;

    vector<Base *> arr;

    arr.push_back(&c);
    arr.push_back(&c2);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i]->printHello();
    }

    return 0;
}