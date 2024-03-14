#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char *StrDup(char *s)
{
    if (s == nullptr)
    {
        throw invalid_argument("Source is a nullptr");
    }

    size_t len = strlen(s);

    char *d = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        d[i] = s[i];
    }
    d[len] = '\0';

    return d;

    // char *source = s;
    // char *destination = d;
    // while (s)
    // {
    //     *destination = *source;
    //     source++;
    //     destination++;
    // }
}

int main()
{
    string a;
    try
    {
        char *b = StrDup(nullptr);
    }
    catch (invalid_argument &e)
    {
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (bad_alloc &e)
    {
        cout << "Bad allocation: " << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}