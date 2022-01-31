#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Point {
	int x, y;
public:
	Point();

	Point(int x, int y);

	void print();

	friend fstream& operator>>(fstream& fin, Point& p);

	friend fstream& operator<<(fstream& fout, Point& p);
};


class Figure {
protected:
	vector<Point> points;
public:
	Figure() {}

	Figure(const vector<Point>& other) {
		points = other;
	}

	Figure(int size, Point p, ...) {
		Point* ptr = &p;
		while (size--) {
			points.push_back(*ptr);
			ptr++;
		}

	}

	virtual void print() = 0;

	virtual void save(fstream& fin) = 0;
	virtual void load(fstream& fout) = 0;
};

class Square : public Figure {
public:
	Square() {}

	Square(const vector<Point>& other) : Figure(other) {}

	void print() override;

	void save(fstream& fout) override;

	void load(fstream& fin) override;

};

class Line : public Figure {
public:
	Line() : Figure() {}

	Line(Point one, Point two) :Figure(2, one, two) {

	}

	void print() override;

	void save(fstream& fout) override;

	void load(fstream& fin) override;
};

class Rhombus : public Figure {
	Point center;
public:
	Rhombus() : Figure() {}
	Rhombus(Point center, const vector<Point> other) :Figure(other) {
		this->center = center;
	}

	void print() override;

	void save(fstream& fout) override;

	void load(fstream& fin) override;

};

class Triangle : public Figure {
public:
	Triangle() : Figure() {}

	Triangle(Point one, Point two, Point three) :Figure(3, one, two, three) {

	}

	void print() override;

	void save(fstream& fout) override;

	void load(fstream& fin) override;

};

