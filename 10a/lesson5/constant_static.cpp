#include <iostream>
#include <string>

using namespace std;

class Class
{
    const string name;
    int grade;
    string teacherName;

public:
    static int numberOfClasses;
    Class()
        : name("A"), grade(10)
    {
    }

    Class(const string &name)
        : name(name), teacherName("Test")
    {
        this->teacherName = "Test";
        cout << this->grade << endl;
    }

    string getName() const
    {
        return this->name;
    }

    const string &getTeacherName(string name) const
    {
        // this->teacherName = name; 
        return this->teacherName;
    }

    // void setName(const string &name)
    // {
    //     this->name = name;
    // }
};

int Class::numberOfClasses = 0;

int main()
{
    cout << Class::numberOfClasses << endl;
    Class a("A");
    cout << a.getTeacherName("Test2") << endl;
    return 0;
}