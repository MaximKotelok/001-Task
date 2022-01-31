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
protected:
	vector<Point> points;
public:
	Figure(const vector<Point>& other) {
		points = other;
	}

	Figure(int size, Point p, ...) {
		Point *ptr = &p;
		while (size--) {
			points.push_back(*ptr);
			ptr++;
		}

	}

	virtual void print() = 0;

};

class Square : public Figure {
public:
	Square(const vector<Point> other) :Figure(other) {}

	void print() override {
		cout << "Square:\n";
		cout<<"------------------------------------------------------------\n";
		for (auto el : points)
			el.print();
		cout << "------------------------------------------------------------\n";
	}

};

class Line : public Figure {
public:
	Line(Point one, Point two) :Figure(2, one, two) {

	}

	void print() override {
		cout << "Line:\n";
		cout << "------------------------------------------------------------\n";
		for (auto el : points)
			el.print();
		cout << "------------------------------------------------------------\n";
	}

};

int main() {
	const int size = 2;
	Figure* figures[2]{ new Square({Point(1, 2), Point(3, 5), Point(1, 2), Point(5, 5)}), new Line(Point(1,2),Point(1,5)) };
	for (int i = 0; i < size; i++)
		figures[i]->print();
	

	return 0;
}