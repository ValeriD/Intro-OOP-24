#include <cstring>
#include <iostream>
#include <exception>

using namespace std;

char *StrDup(const char *s)
{
    if (s == nullptr)
    {
        throw invalid_argument("StrDup(): Nullptr provided!");
    }
    size_t len = strlen(s);
    char *d = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        d[i] = s[i];
    }
    d[len] = '\0';

    return d;
}

int main()
{
    char *res;
    try
    {
        res = StrDup(nullptr);
    }
    catch (exception &e)
    {
        res = StrDup("Test");
        cout << "Exception: " << e.what() << endl;
    }
    cout << res << endl;

    cout << "END" << endl;
    return 0;
}