#include <iostream>
#include <sstream>
#include <fstream>
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

class File
{
    fstream fs;

public:
    File(const string &path, unsigned int flags)
        : fs(path, flags)
    {
        // this->fs.open(path, flags);
        if (!fs.is_open())
        {
            throw runtime_error("Couldn't open file '" + path + "'");
        }
    }
    ~File()
    {
        this->fs.close();
    }
    fstream &getFilestream()
    {
        return this->fs;
    }
};

class PointReader
{
    PointReader() {} // PointReader() = delete;

public:
    static Point2D readPoint2D(File &f)
    {
        Point2D res;

        f.getFilestream() >> res;

        return res;
    }
    static vector<Point2D> readPoints2D(File &f)
    {
        vector<Point2D> res;
        while (!f.getFilestream().eof())
        {
            res.push_back(PointReader::readPoint2D(f));
        }

        return res;
    }
};

class PointWriter
{
    PointWriter() {} // PointWriter() = delete;
public:
    static void writePoints2D(const vector<Point2D> &points, File &f)
    {
    }

    static void writePoint2D(Point2D &point, File &f)
    {
        f.getFilestream() << &point << endl;
    }
};

int main()
{

    File f("points.txt", ios::in);
    File f2("points2d.txt", ios::out | ios::trunc);
    // Point2D point = PointReader::readPoint2D(f);

    // cout << point.getX() << " " << point.getY() << endl;

    vector<Point2D> points = PointReader::readPoints2D(f);

    for (Point2D p : points)
    {
        cout << p.getX() << " " << p.getY() << endl;
        PointWriter::writePoint2D(p, f2);
    }

    return 0;
}