#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A
{
public:
    virtual void printHello()
    {
        cout << "Hello from A" << endl;
    }

    virtual void printGoodbye() = 0;
};

class B : public A
{
public:
    void printHello()
    {
        cout << "Hello from B" << endl;
    }

    void printGoodbye() override
    {
        cout << "Goodbye from B" << endl;
    }
};

class C : public A
{
public:
    void printHello() override
    {
        cout << "Hello from C" << endl;
    }
    void printGoodbye() override
    {
        cout << "Goodbye from C" << endl;
    }
};

int main()
{
    // A a;
    // B b;
    // a.printHello();
    // b.printHello();

    // cout << typeid(a).name() << endl;
    // cout << typeid(b).name() << endl;

    vector<A *> arr;
    for (size_t i = 1; i <= 6; i++)
    {
        // if (i % 3 == 0)
        // {
        //     arr.push_back(new A());
        // }
        if (i % 2 == 0)
        {
            arr.push_back(new B());
        }
        else
        {
            arr.push_back(new C());
        }
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << typeid(*arr[i]).name() << endl;
        arr[i]->printHello();
    }

    return 0;
}