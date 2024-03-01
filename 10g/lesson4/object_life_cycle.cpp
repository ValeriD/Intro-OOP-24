#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////////////////
// 1. Enumerations
// 2. C string library
// 3. Copy constructor
// 4. Copy assignment operator =
////////////////////////////////////////////////////////////////////////


using namespace std;

enum Hobby
{
    READING,
    DRINKING,
    SLEEPING,
    GAMING,
};

char *translateEnum(Hobby h)
{
    char *r;
    switch (h)
    {
    case 0:
        r = strdup("reading");
        break;
    case 1:
        r = strdup("drinking");
        break;
    case 2:
        r = strdup("sleeping");
        break;
    case 3:
        r = strdup("gaming");
        break;
    }

    return r;
}

// Hobby translateEnum(const char *h)
// {
//     return Hobby::READING;
// }

class Person
{
    int age;
    char *name;
    Hobby hobby;

public:
    Person(int age, const char *name, Hobby hobby)
    {
        cout << "Hello from Constructor" << endl;
        this->age = age;
        this->name = strdup(name);
        this->hobby = hobby;
    }

    Person(const Person &p)
    {
        cout << "Hello from Copy Constructor" << endl;
        this->age = p.age;
        this->name = strdup(p.name);
        this->hobby = p.hobby;
    }

    Person &operator=(const Person &other)
    {
        cout << "Hello from Copy operator=" << endl;
        if (this == &other)
        {
            return *this;
        }
        this->age = other.age;
        delete[] this->name;
        this->name = strdup(other.name);
        this->hobby = other.hobby;

        return *this;
    }

    ~Person()
    {
        cout << "Hello from Destructor" << endl;
        delete[] name;
    }

    int getAge() const
    {
        return this->age;
    }

    void seAge(const int &age)
    {
        this->age = age;
    }
};

int main()
{
    Person p1(20, "John", READING);
    Person p2(p1); // Person* p2 = new Person(p1);
    Person p3 = p2;

    p3 = p1; // p3.operator=(p1);

    return 0;
}