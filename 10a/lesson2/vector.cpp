#include <iostream>

using namespace std;

//----------------------------------------------------------------
// We talked about:
// What is a Array and a Dynamic array
// What does a typedef do
// Operations with pointers
//----------------------------------------------------------------

struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
};

typedef struct vector_t vector_t;

vector_t *init();

void destroy(vector_t *v);

void push_back(vector_t *v, int value);

void resize(vector_t *v, size_t cap);

int pop_back(vector_t *v);

int at(vector_t *v, int index);

int main()
{
    size_t a;
}

vector_t *init()
{
    vector_t *vector = new vector_t;
    vector->capacity = 2;
    vector->size = 0;
    vector->data = new int[vector->capacity];

    return vector;
}

void destroy(vector_t *v)
{
    delete[] v->data;
    delete v;
}

void push_back(vector_t *v, int value)
{
    if (v->size == v->capacity)
        resize(v, v->capacity * 2);

    v->data[v->size++] = value;
}

void resize(vector_t *v, size_t cap)
{
    v->capacity = cap;

    int *newArr = new int[v->capacity];

    for (unsigned i = 0; i < v->size; i++)
    {
        newArr[i] = v->data[i]; // *(v->data+i)
    }

    delete[] v->data;
    v->data = newArr;
}

int pop_back(vector_t *v)
{
    if (v->size == 0)
    {
        return NULL;
    }

    v->size--;
    int value = v->data[v->size];

    if (v->size <= v->capacity / 2)
        resize(v, v->capacity / 2);

    return value;
}

int at(vector_t *v, int index)
{
    if (index >= v->size)
    {
        return NULL;
    }
    if (index < 0)
    {
        if (-1 * index > v->size)
        {
            return NULL;
        }
        return v->data[v->size + index];
    }
    return v->data[index];
}