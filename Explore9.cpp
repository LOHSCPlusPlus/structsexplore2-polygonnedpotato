
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
// This is new
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

// All of this is new
Triangle::Triangle() {
    // There is nothing to do here because the default
    // constructor of Point is automatically called when
    // we create the array.
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

int main() {
    Triangle a(Point(1,3), Point(5, 7), Point(12, 22));
    Triangle b;
    cout << "Triangle a ";
    PrintTriangle(a);
    cout << "Triangle b ";
    PrintTriangle(b);
    b = a;
    cout << "Triangle b ";
    PrintTriangle(b);
    
    return 0;
}


