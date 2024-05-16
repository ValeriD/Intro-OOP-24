#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream ifs; // Only input
    ofstream ofs; // Only output

    fstream fs; // Read & write

    fs.open("tmp.txt", ios::in | ios::out);

    if (!fs.is_open())
    {
        cerr << "Failed to open file" << endl;
    }
    cout << fs.tellp() << endl;
    fs << "Hello, world!" << endl;
    fs << "This is test!" << endl;

    // cout << fs.tellg() << endl;

    fs.seekg(ios::beg);

    string line;
    while (!fs.eof())
    {
        getline(fs, line);
        cout << line << endl;
    }
    // fs >> line;

    fs.close();

    return 0;
}