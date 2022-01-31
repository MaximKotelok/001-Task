#include <iostream>
#include <vector>

using namespace std;

class Point {
	int x, y;
public:

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void print() {
		cout << "X = " << x << " | " << "Y = " << y << "\n";
	}
};

class Figure{
	vector<Point> points;
public:
	Figure(int size, Point p, ...) {
		Point *ptr = &p;
		while (size--) {
			points.push_back(*ptr);
			ptr++;
		}

	}

	void print() {
		cout << "------------------------------------------------------------\n";
		for (auto el : points)
			el.print();
		cout << "------------------------------------------------------------\n";
	}

};

int main() {
	Figure f(4, Point( 1,2 ), Point(2,4 ), Point(4,3 ), Point(5,6 ));
	f.print();

	Figure f2(2, Point(5, 6), Point(5, 10));
	f2.print();
	
	Figure f3(5, Point(5, 6), Point(6, 10), Point(10, 11), Point(2, 5), Point(1, 0) );
	f3.print();

	return 0;
}