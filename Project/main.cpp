#include <iostream>

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

int main() {
	Point one(1, 2);
	one.print();


	return 0;
}