#include <iostream>
#include <vector>

using namespace std;

class Point {
	int x, y;
public:
	Point() {
		x = y = 0;
	}

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

class Rhombus : public Figure {
	Point center;
public:
	Rhombus(Point center, const vector<Point> other) :Figure(other) {
		this->center = center;
	}

	void print() override {
		cout << "Rhombus:\n";
		cout << "------------------------------------------------------------\n";
		cout << "Center: \n"; 
		center.print();
		cout << "Other points: \n";
		for (auto el : points)
			el.print();
		cout << "------------------------------------------------------------\n";
	}

};

class Triangle : public Figure {
public:
	Triangle(Point one, Point two, Point three) :Figure(2, one, two, three) {

	}

	void print() override {
		cout << "Triangle:\n";
		cout << "------------------------------------------------------------\n";
		for (auto el : points)
			el.print();
		cout << "------------------------------------------------------------\n";
	}

};

int main() {
	const int size = 4;
	Figure* figures[size]{ new Square({Point(1, 2), Point(1, 2), Point(2, 1), Point(2, 2)}), 
						   new Line(Point(1,2),Point(1,5)), 
						   new Rhombus(Point(0,0),{Point(0,1),Point(1,0),Point(-1,0),Point(0,-1)}),
						   new Triangle(Point(1,0),Point(-1,0),Point(0,-1))};
	for (int i = 0; i < size; i++)
		figures[i]->print();
	

	return 0;
}