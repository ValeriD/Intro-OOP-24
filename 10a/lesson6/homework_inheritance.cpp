#include <iostream>
#include <exception>

using namespace std;

/**
 * Your task is to create a class MyException that inherits from std::exception and overrides the what() method.
 * You have the signature of the what method below.
 *
 * I want you to create:
 *  - Default constructor that will have a default message: MyCustomError: No message!
 *  - Constructor with a message
 *  - Destructor
 *  - Copy constructor
 *  - Copy assignment operator
 *  - what() method that will print the message in the following format: MyCustomError: <message>
 */

class MyException : exception
{
public:
    MyException()
        : exception()
    {
    }
    const char *what() const noexcept;
};

int main()
{
    MyException e1;
    cout << "Expected: MyCustomError: No message!"
         << "Got: " << e1.what() << endl;

    MyException e2("This is a message");
    cout << "Expected: MyCustomError: This is a message"
         << "Got: " << e2.what() << endl;
    return 0;
}
