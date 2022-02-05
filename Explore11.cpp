
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
struct Triangle {
    Point points[3];
    Triangle();
    Triangle(Point p0, Point p1, Point p2);
};
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}


void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y;
}

Triangle::Triangle() {
}
Triangle::Triangle(Point p0, Point p1, Point p2) {
    points[0] = p0;
    points[1] = p1;
    points[2] = p2;
}

void PrintTriangle(Triangle t) {
    for (int index = 0; index < 3; index++) {
        cout << " p" << index;
        PrintPoint(t.points[index]);
    } 
    cout << endl;
}
// Rotates the triangle 90 degrees counter-clockwise around
// the origin. To rotate a triangle you swap the x/y values
// of the points & change the sign of y as you swap it.
void RotateTriangle(Triangle &t) {
    for (int index = 0; index < 3; index++) {
        double temp = t.points[index].x;
        t.points[index].x = -1.0 * t.points[index].y;
        t.points[index].y = temp;
    }
}

int main() {
    Triangle a(Point(1,3), Point(5, 7), Point(12, 22));
    cout << "Triangle a ";
    PrintTriangle(a);
    RotateTriangle(a);
    cout << "Triangle a post rotation ";
    PrintTriangle(a);
    
    return 0;
}


