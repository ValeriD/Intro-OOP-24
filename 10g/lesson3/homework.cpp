#include <iostream>

using namespace std;

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

        this->data = data;
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

    size_t getCapacity() const
    {
        return this->capacity;
    }
    size_t getSize() const
    {
        return this->size;
    }
    /*
        The task is to implement the two operations of a vector:

        insert - inserts a new element at the provided index. If the index is greater than the size of the array, do not perform any operations
        remove - removes the element at the provided index. If the index is greater than the size of the array, do not perform any operations
    */
    Vector &insert(int index, int value);

    Vector &remove(int index);
};

int main()
{

    Vector v;

    v.push_back(1).push_back(2).push_back(3).push_back(4).push_back(5);
    v.insert(2, 10);
    cout << "The expected value is 10, the actual value is: " << v.at(2) << endl;
    cout << "The expected capacity is 10, the actual capacity is: " << v.getCapacity() << endl;
    cout << "The expected size is 6, the actual size is: " << v.getSize() << endl;

    v.remove(2);
    cout << "The expected value is 3, the actual value is: " << v.at(2) << endl;
    cout << "The expected capacity is 10, the actual capacity is: " << v.getCapacity() << endl;
    cout << "The expected size is 5, the actual size is: " << v.getSize() << endl;

    return 0;
}