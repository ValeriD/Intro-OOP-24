#include <iostream>

using namespace std;

class Test
{
public:
    int a;
    Test()
    {
        cout << "Default constructor is called!" << endl;
        a = 10;
    }
    ~Test()
    {
        cout << "Destructor is called!" << endl;
    }
};
const size_t DEFAULT_VECTOR_CAP = 5;

class Vector
{
    int *data;
    size_t size;
    size_t capacity;

    void _resize()
    {
        this->capacity *= 2;
        int *newData = new int[this->capacity];

        for (size_t i = 0; i < this->size; i++)
        {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;
    }

public:
    Vector()
    {
        this->capacity = DEFAULT_VECTOR_CAP;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    Vector(size_t capacity)
    {
        this->capacity = capacity;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    Vector(int *data, size_t size, size_t capacity)
    {
        this->capacity = capacity;
        this->size = size;
        // this->data = data;
        this->data = new int[this->capacity];
        for (size_t i = 0; i < size; i++)
        {
            this->data[i] = data[i];
        }
    }

    ~Vector()
    {
        delete[] this->data;
    }

    int at(int index)
    {
        return this->data[index];
    }
    Vector &push_back(int value)
    {
        if (this->size == this->capacity)
        {
            this->_resize();
        }
        this->data[this->size++] = value;
        return *this;
    }
};

void doSomething(Test &t)
{
    t.a = 1;
}

int main()
{
    // Test t; // Test t();
    // doSomething(t);
    // cout << t.a << endl;

    // cout << t.a << endl;

    // Test *t2 = new Test();
    // delete t2; // t2->~Test();

    // int *data = new int[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     data[i] = i;
    // }

    // Vector v(data, 5, 5);

    // delete[] data;
    // cout << v.at(1) << endl;

    Vector v;
    v.push_back(1).push_back(2).push_back(3);
    cout << v.at(2) << endl;

    return 0;
}