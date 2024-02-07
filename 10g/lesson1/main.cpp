#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
// Types
// float, double
// char, string
// int, unsigned int, signed int, long, short
// struct
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// cout
// cin - for reading
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// Memory allocation
// new - equal to malloc and calloc
// delete - equal to free
////////////////////////////////////////////////////////////////

char *Malloc(unsigned int size)
{
    char *arr = new char[size];

    return arr;
}

char *Realloc(char *src, unsigned size)
{
    char *newArr = new char[size];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = src[i];
    }

    delete[] src;

    return newArr;
}

int main()
{
    int a;

    std::cin >> a;

    cout << "The number you chose is: " << a << endl;
}