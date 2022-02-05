
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
// This is new!
struct Line {
    Point start;
    Point end;
    Line(Point s, Point e);
};
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

// This is new
Line::Line(Point s, Point e) {
    start = s;
    end = e;
}

void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y;
}


// This is new
void PrintLine(Line l) {
    cout << "  Start";
    PrintPoint(l.start);
    cout << "   End";
    PrintPoint(l.end); 
    cout << endl;
}

int main() {
    // We can create two temporary points by directly calling the Point constructor
    Line a(Point(3,9), Point(12,22));
    Line b(Point(7,77), Point(128, -92));
    cout << "Line a";
    PrintLine(a);
    cout << "Line b";
    PrintLine(b);
    a.start.x = b.start.x * -1;
    a.start.y = b.start.y * -1;
    a.end.x = b.end.x * -1;
    a.end.y = b.end.y * -1;
    cout << "Line a";
    PrintLine(a);
    return 0;
}


