#include <iostream>
#include <sstream>

using namespace std;

class Point2D
{
    int x, y;

public:
    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // ostream &operator<<(ostream &o) => p << cout;
    // {
    //     o << "(" << this->getX() << "," << this->getY() << ")";
    //     return o;
    // }
    friend ostream &operator<<(ostream &o, Point2D &p)
    {
        o << "(" << p.x << "," << p.y << ")";
        return o;
    }

    friend istream &operator>>(istream &is, Point2D &p)
    {
        string line;
        getline(is, line);
        line.pop_back();
        line = line.substr(1, line.length() - 1);

        stringstream ss(line);
        string x, y;
        getline(ss, x, ',');
        getline(ss, y, ',');

        string newLine = x + " " + y;

        stringstream ss2(newLine);
        ss2 >> p.x >> p.y;

        return is;
    }
};

int main()
{
    Point2D p;
    cin >> p;

    cout << "Point " << 1 << p << ";" << endl; // operator<<(cout, p);
    return 0;
}