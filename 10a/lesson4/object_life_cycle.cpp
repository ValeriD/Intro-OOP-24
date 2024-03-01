#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////////////////
// 1. Enumerations
// 2. C string library
// 3. Copy constructor
// 4. Copy assignment operator =
// 5. Shallow vs deep copy
////////////////////////////////////////////////////////////////////////

using namespace std;

enum Weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

const char *translateDay(Weekday day)
{
    char *result;
    switch (day)
    {
    case Weekday::MONDAY:
        result = strdup("monday");
        break;
    case Weekday::TUESDAY:
        result = strdup("tuesday");
        break;
    case Weekday::WEDNESDAY:
        result = strdup("wednesday");
        break;
    case Weekday::THURSDAY:
        result = strdup("thursday");
        break;
    case Weekday::FRIDAY:
        result = strdup("friday");
        break;
    case Weekday::SATURDAY:
        result = strdup("saturday");
        break;
    case Weekday::SUNDAY:
        result = strdup("sunday");
        break;
    }

    return result;
}

// HOMEWORK
Weekday translateDay(const char *day)
{
    return Weekday::MONDAY;
}

class Event
{
    Weekday day;
    char *name;
    char *description;
    unsigned duration;

public:
    Event(const char *name, const char *description, unsigned duration, Weekday day)
    {
        cout << "Hello from Constructor with Parameters" << endl;
        this->name = strdup(name);
        this->description = strdup(description);
        this->duration = duration;
        this->day = day;
    }

    Event(const Event &other)
    {
        cout << "Hello from Copy Constructor" << endl;

        this->name = strdup(other.name);
        this->description = strdup(other.description);
        this->duration = other.duration;
        this->day = other.day;
    }

    // Event(Event &&other)
    // {
    //     this->name = strdup(other.name);
    //     this->description = strdup(other.description);
    //     this->duration = other.duration;
    //     this->day = other.day;

    //     delete[] other.name;
    //     delete[] other.description;
    // }

    Event &operator=(const Event &other)
    {
        if (this != &other)
        {

            delete[] this->name;
            delete[] this->description;

            this->name = strdup(other.name);
            this->description = strdup(other.description);
            this->duration = other.duration;
            this->day = other.day;

            delete[] other.name;
        }
        return *this;
    }
    ~Event()
    {
        delete[] this->name;
        delete[] this->description;
    }
};

// Event &doSomething()
// {
//     Event e("Test", "Test test", 1, Weekday::SUNDAY);
//     return e;
// }

int main()
{

    Event e("Test", "Test test", 1, Weekday::SUNDAY);

    Event e2 = e; // Event e2(e);

    Event e3 = e2;
    e3 = e; // e3.operator=(e);

    e3 = e3;

    // Event e4 = doSomething();
    return 0;
}
