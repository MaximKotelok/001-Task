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

int main() {

	Square s({ Point(1, 2), Point(3, 5), Point(1, 2), Point(5, 5) });
	s.print();
	

	return 0;
}