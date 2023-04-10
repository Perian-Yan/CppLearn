#include <iostream>
using namespace std;

class Point
{
public:
    void setX(int x) {
        m_X = x;
    }
    int getX() {
        return m_X;
    }

    void setY(int y) {
        m_Y = y;
    }
    int getY() {
        return m_Y;
    }

private:
    int m_X;
    int m_Y;
};


class Circle
{
public:
    void setR(int r) {
        m_R = r;
    }
    int getR() {
        return m_R;
    }

    void setCenter(Point center)
    {
        m_Center = center;
    }

    Point getCenter() {
        return m_Center;
    }
private:
    int m_R;
    Point m_Center;
};

void isInCircle(Circle& c, Point& p) {
    int distance =
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()) +
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX());

    int r_square = c.getR() * c.getR();

    if (distance == r_square) {
        cout << "On the circle" << endl;

    }
    else if (distance > r_square) {
        cout << "Outside of the circle" << endl;

    }
    else {
        cout << "Inside the circle" << endl;
    }
}
int main()
{
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    Point point;
    point.setX(1);
    point.setY(0);

    isInCircle(c, point);

    return 0;
}
