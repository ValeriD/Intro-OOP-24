#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // fstream fs("tmp.txt", ios::out);

    fstream fs;
    fs.open("tmp.txt", ios::in | ios::out | ios::trunc);

    if (!fs.is_open())
    {
        cout << "Error opening file" << endl;
        return -1;
    }

    fs << "Hello, world!" << endl;
    fs << "This is a test!" << endl;

    string line;
    cout << "Get cursor position: " << fs.tellg() << endl;
    fs.seekg(ios::beg);
    // fs.seekg(5);
    // cout << "Get cursor position: " << fs.tellg() << endl;

    while (!fs.eof())
    {
        line.clear();
        // getline(fs, line);
        fs >> line;
        cout << line << endl;
    }
    fs.close();
    return 0;
}