#include <iostream>

using namespace std;

//----------------------------------------------------------------
// We discussed:
// What is a class?
// Differences between structure and a class, variable and a field, function and a method
// Default constructor, Destructor, and Constructor with parameters
// What is encapsulation?
// Passing arguments by value and by reference
// Chaining of commands
// How to trigger the Constructor and the Destructor
//----------------------------------------------------------------
/*
class Test
{
    int a;

public:
    Test()
    {
        this->a = 5;
    }
    int getA()
    {
        return a;
    }
    void setA(int a)
    {
        this->a = a;
    }
};

void doSomethingWithA(Test& t){
    int a;
    cin >> a;
    t.setA(a);
}

int main()
{
    // Test *v = new Test();
    Test t; // Test t();
    cout << t.getA() << endl;
    doSomethingWithA(t);
    cout << t.getA() << endl;
}

*/

class Vector
{
private:
    int *data;
    size_t size;
    size_t capacity;

    void resize()
    {
        int *newData = new int[this->capacity * 2];
        for (int i = 0; i < this->size; i++)
        {
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
        this->capacity *= 2;
    }

public:
    Vector()
    {
        this->data = new int[5];
        this->size = 0;
        this->capacity = 5;
    }

    Vector(int *data, size_t size, size_t capacity)
    {

        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = data[i];
        }

        this->size = size;
        this->capacity = capacity;
    }

    ~Vector()
    {
        delete[] this->data;
    }

    Vector &push_back(int value)
    {
        if (this->size == this->capacity)
        {
            this->resize();
        }
        this->data[this->size] = value;
        this->size++;

        return *this;
    }

    Vector &pop_back()
    {
        if (this->size == 0)
        {
            return *this;
        }
        this->size--;
        return *this;
    }

    int at(int index)
    {
        if (index < 0 || index >= this->size)
        {
            return NULL;
        }
        return data[index];
    }
};

int main()
{
    /*
        Example for passing a dynamic array as a parameter

        int *data = new int[5];

        for (unsigned int i = 0; i < 5; i++)
        {
            data[i] = i;
        }

        Vector v(data, 5, 5);

        delete[] data;
        cout << v.at(1) << endl;
    */

    Vector v;
    v.push_back(5)     // v.push_back(5) -> v
        .push_back(6)  // v.push_back(6) -> v
        .push_back(7); // v.push_back(7) -> v

    cout << v.push_back(1).push_back(2).at(1) << endl;

    Vector *v2 = new Vector(); // New calls the Contrstuctor

    delete v2; // Delete triggers the Destructor;

    return 0;
}