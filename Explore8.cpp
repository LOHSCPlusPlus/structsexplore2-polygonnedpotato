#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
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

Line::Line(Point s, Point e) {
    start = s;
    end = e;
}

void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y;
}


void PrintLine(Line l) {
    cout << "\tStart";
    PrintPoint(l.start);
    cout << "\tEnd";
    PrintPoint(l.end); 
    cout << endl;
}

// This is new
Point FindMidPoint(Line l) {
    Point mid;
    mid.x = (l.start.x + l.end.x)/2.0;
    mid.y = (l.start.y + l.end.y)/2.0;
    return mid;
}
Point FindLowestPoint(Line l){
  Point lowest;
  if(l.start.y<l.end.y){
    lowest.x=l.start.x;
    lowest.y=l.start.y;
  }else{
    lowest.x=l.end.x;
    lowest.y=l.end.y;
  }
  return lowest;
}

int main() {
    Line a(Point(3,9), Point(12,22));
    cout << "Line a";
    PrintLine(a);
    cout << "Line a's midpoint";
    // This is new
    Point midPoint = FindMidPoint(a);
    PrintPoint(midPoint);
    cout<<"\nLine a's lowest point";
    PrintPoint(FindLowestPoint(a));
    cout << endl;
    Line b(Point(7,-9), Point(8,-15));
    PrintPoint(FindLowestPoint(b));
    cout<<endl;
    return 0;
}


