#include <iostream>
#include <cstring>

using namespace std;

class Class
{
    const char *name;
    char *teacher;
    int grade;

    Class &operator=(const Class &other)
    {
    }
    static int numberOfClasses;

public:
    Class()
    {
        this->name = strdup("G");
    }

    Class(const char *name, const char *teacher)
    {
        numberOfClasses += 1;

        this->name = strdup(name);
        this->teacher = strdup(teacher);
        grade = 10;
    }

    Class(const Class &other)
    {
        this->name = strdup(other.name);
        this->teacher = strdup(other.teacher);
    }

    const char *getName()
    {
        return this->name;
    }

    char *getTeacherName() const
    {
        return this->teacher;
    }

    int getGrade() const
    {
        return this->grade;
    }

    static int getNumberOfClasses()
    {
        return numberOfClasses;
    }
};

int Class::numberOfClasses = 0;

int main()
{
    cout << Class::getNumberOfClasses() << endl;
    Class a("a", "Test");
    Class g("g", "Test1");
    cout << Class::getNumberOfClasses() << endl;

    // cout << g.getGrade() << endl;

    // g.getGrade() = 5;

    // cout << g.getGrade() << endl;

    return 0;
}