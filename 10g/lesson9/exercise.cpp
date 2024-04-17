#include <iostream>
#include <vector>

using namespace std;

//----------------------------------------------------------------
// The task is to implement the two child classes which should implement
// the two abstract methods and a Rule of 3 (Constructor, Copy constructor, copy operator=).
// There is no limitation on fields and methods as long as the functionality is implemented.
// Make sure to verify the parameters where it is required using exceptions!
//----------------------------------------------------------------

class Figure
{

public:
    virtual double calculatePerimeter() const = 0;

    virtual double calculateArea() const = 0;
};

class Polygon : public Figure
{
};

class Circular : public Figure
{
};

int main()
{

    return 0;
}