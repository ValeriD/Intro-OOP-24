#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Point2D
{
    double x, y;

protected:
    virtual vector<double> getParameters() const
    {
        vector<double> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    }

public:
    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    friend ostream &operator<<(ostream &out, const Point2D *p)
    {

        out << "(";

        vector<double> params = p->getParameters();

        for (int i = 0; i < params.size(); i++)
        {
            out << params[i];
            if (i + 1 != params.size())
            {
                out << ",";
            }
        }

        out << ")";
        return out;
    }

    friend istream &operator>>(istream &in, Point2D &p)
    {
        string line;
        getline(in, line);

        line = line.substr(1, line.size() - 2);

        stringstream ss(line);

        string x, y;
        getline(ss, x, ',');
        getline(ss, y, ',');

        string newLine = x + " " + y;
        stringstream nss(newLine);

        nss >> p.x >> p.y;

        return in;
    }
};

class Point3D : public Point2D
{
    double z;

protected:
    vector<double> getParameters() const override
    {
        vector<double> res = Point2D::getParameters();
        res.push_back(this->z);

        return res;
    }

public:
    double getZ() const { return this->z; }

    void setZ(double z) { this->z = z; }
};

int main()
{
    // Point2D p;
    // p.setX(0.1);
    // p.setY(0.11);
    // int a;
    // cin >> p;
    // cout << "The point chosen is: " << p << endl; // operator<<(operator<<(cout, p), endl);

    // p << cout; // p.operator<<(cout);
    // operator<<(cout, p);

    Point3D p1;
    p1.setX(0.1);
    p1.setY(0.1);
    p1.setZ(0.1);
    // cin >> p;

    cout << &p1 << endl;
    return 0;
}