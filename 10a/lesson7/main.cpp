// Person  <-- BasketballPlayer
//         <-- FootballPlayer

/**
 * name, age, weight, height, birtday, sex - MALE, FEMALE, OTHER, UNDEFINED(default value)
 * Constructor birthday, weight, height, sex
 * Constructor ()
 *
 * Copy constructor
 * Copy assignment operator
 * Destructor
 *
 * constant birthday - '07/07/2007'
 *
 * counter of people created
 *
 * getters
 *
 * setters
 *
 * growUpWithOneYear
 * Person - 1, 5, 2,
 * BasketballPlayer - 1, 7, 10
 * FootballPlayer - 1, 6, 6
 *
 * sport - print different messages for each class
 *
 */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Sex
{
    MALE,
    FEMALE,
    OTHER,
    UNDEFINED
};

class Person
{
    char *name;
    unsigned int weight;
    unsigned int height;
    const string birthday;
    Sex sex;
    static unsigned numberOfPeopleCreated;

protected:
    unsigned int age;

public:
    Person()
        : name(strdup("")), age(0), weight(0), height(0), birthday(""), sex(Sex::UNDEFINED)
    {
        numberOfPeopleCreated++;
    }

    Person(const string &birthday, unsigned int weight, unsigned int height, Sex s)
        : name(strdup("")), age(0), weight(weight), height(height), birthday(birthday), sex(s)
    {
        numberOfPeopleCreated++;
    }

    // TODO Copy constructor & Destructor

    Person &operator=(const Person &other)
    {
        if (this->birthday != other.birthday)
        {
            throw runtime_error("Differance in birthday field");
        }

        if (this != &other)
        {
            delete[] this->name;
            this->name = strdup(other.name);
            this->age = other.age;
            this->weight = other.weight;
            this->height = other.height;
        }

        return *this;
    }

    const char *getName() const
    {
        return this->name;
    }

    void setName(const char *name)
    {
        if (name == nullptr)
        {
            throw invalid_argument("Nullptr passed as argument!");
        }
        delete[] this->name;
        this->name = strdup(name);
    }
    // TODO the rest of the getters and setters

    virtual void doSport() const
    {
        cout << "I am not doing anything..." << endl;
    }

    virtual void growUpWithOneYear()
    {
        this->age++;
        this->weight += 5;
        this->height += 2;
    }
};

class BasketballPlayer : public Person
{
    string teamName;

public:
    BasketballPlayer()
        : Person(),
          teamName("")
    {
    }

    BasketballPlayer(const char *name, const string &birthday, unsigned age, unsigned weight, unsigned height, Sex s)
        : Person(birthday, weight, height, s)
    {
        this->setName(name);
        this->age = age;
        this->teamName = ""; // Change if you want (make it a constructor's argument)
    }

    // TODO Copy constructor

    ~BasketballPlayer()
    {
        Person::~Person(); // Call the super destructor
    }

    BasketballPlayer &operator=(const BasketballPlayer &other)
    {
        Person::operator=(other);

        this->teamName = other.teamName;
    }

    void doSport() const override
    {
        cout << "I am playing a basketball game!" << endl;
    }

    // TODO override growUpWithOneYear
};

class FootballPlayer : public Person
{
    // TODO same as BasketballPlayer
};

unsigned Person::numberOfPeopleCreated = 0;

int main()
{
    const string b = "asd";

    Person p(b, 1, 2, Sex::MALE);

    // cout << p.age << endl; - age is unaccessible

    return 0;
}
