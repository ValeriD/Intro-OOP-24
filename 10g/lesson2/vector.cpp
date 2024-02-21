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

    void init();
};

typedef struct vector_t vector_t;
void vector_t::init()
{
}
vector_t *init();

void destroy(vector_t *v);

void push_back(vector_t *v, int value);

void resize(vector_t *v);

int at(vector_t *v, int index);

int pop_back(vector_t *v);

int main(int argc, char **argv)
{
    vector_t *v = init();
    cout << sizeof(v->data) << endl;
    for (unsigned int i = 0; i < 7; i++)
    {
        push_back(v, i);
    }

    for (unsigned int i = 0; i < v->size; i++)
    {
        cout << v->data[i] << " ";
    }

    destroy(v);
}

vector_t *init()
{
    vector_t *vector = new vector_t();
    vector->data = new int[5];
    vector->size = 0;
    vector->capacity = 5;

    return vector;
}

void destroy(vector_t *v)
{
    delete[] v->data;
}

void push_back(vector_t *v, int value)
{
    if (v->size == v->capacity)
    {
        resize(v);
    }
    v->data[v->size] = value;
    v->size++;
}

void resize(vector_t *v)
{
    int *newArr = new int[v->capacity * 2];

    for (unsigned int i = 0; i < v->size; i++)
    {
        newArr[i] = v->data[i];
    }

    delete[] v->data;
    v->capacity *= 2;
    v->data = newArr;
}

int at(vector_t *v, int index)
{
    if (index >= v->size)
    {
        return NULL;
    }
    return v->data[index];
}

int pop_back(vector_t *v)
{
    if (v->size == 0)
    {
        return NULL;
    }
    int value = v->data[v->size - 1];
    v->size--;
}