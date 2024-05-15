#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Point2D
{
    int x, y;

public:
    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

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

class File
{
    fstream fs;

public:
    File(const string &path, unsigned int flags)
        : fs(path, flags)
    {
        // this->fs.open(path, flags);
        if (!this->fs.is_open())
        {
            throw runtime_error("Failed to open file: " + path);
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
    PointReader() {} // PointReader() = delete; - they have similar behavior

public:
    static Point2D readPoint2D(fstream &is)
    {
        Point2D p;
        is >> p;
        return p;
    }

    static vector<Point2D> readPoints2D(fstream &is)
    {
        vector<Point2D> res;

        while (!is.eof())
        {
            // READ
            Point2D p = PointReader::readPoint2D(is);

            // SAVE
            res.push_back(p);
        }

        return res;
    }
};

int main()
{
    File f("tmp.txt", ios::in | ios::out);
    cout << "File successfully opened" << endl;
    // Point2D p = PointReader::readPoint2D(f.getFilestream());
    // cout << p.getX() << " " << p.getY() << endl;

    vector<Point2D> arr = PointReader::readPoints2D(f.getFilestream());

    for (Point2D p : arr)
    {
        cout << p.getX() << " " << p.getY() << endl;
    }
    return 0;
}