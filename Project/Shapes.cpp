#include "Shapes.h"

//POINT
Point::Point() {
	x = y = 0;
}

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

void Point::print() {
	cout << "X = " << x << " | " << "Y = " << y << "\n";
}


//SQUARE
void Square::print() {
	cout << "Square:\n";
	cout << "------------------------------------------------------------\n";
	for (auto el : points)
		el.print();
	cout << "------------------------------------------------------------\n";
}

void Square::save(fstream& fout) {
	fout << "S ";
	for (int i = 0; i < points.size(); i++) {
		fout << points[i];
		if (i != points.size() - 1)
			fout << " ";
	}
	fout << ".\n";

}

void Square::load(fstream& fin) {
	Point p;
	char c = ' ';
	while (c != '.') {
		fin >> p;
		points.push_back(p);
		fin.get(c);
	}
}
//LINE

void Line::print() {
	cout << "Line:\n";
	cout << "------------------------------------------------------------\n";
	for (auto el : points)
		el.print();
	cout << "------------------------------------------------------------\n";
}

void Line::save(fstream& fout) {
	fout << "L ";
	for (int i = 0; i < points.size(); i++) {
		fout << points[i];
		if (i != points.size() - 1)
			fout << " ";
	}
	fout << ".\n";

}

void Line::load(fstream& fin) {
	Point p;
	char c = ' ';
	while (c != '.') {
		fin >> p;
		points.push_back(p);
		fin.get(c);
	}
}

//RHOMBUS


void Rhombus::print() {
	cout << "Rhombus:\n";
	cout << "------------------------------------------------------------\n";
	cout << "Center: \n";
	center.print();
	cout << "Other points: \n";
	for (auto el : points)
		el.print();
	cout << "------------------------------------------------------------\n";
}

void Rhombus::save(fstream& fout) {
	fout << "R ";
	fout << center << " ";
	for (int i = 0; i < points.size(); i++) {
		fout << points[i];
		if (i != points.size() - 1)
			fout << " ";
	}
	fout << ".\n";

}

void Rhombus::load(fstream& fin) {
	Point p;
	fin >> p;
	center = p;
	char c = ' ';
	while (c != '.') {
		fin >> p;
		points.push_back(p);
		fin.get(c);
	}
}

//TRIANGLE

void Triangle::print()  {
	cout << "Triangle:\n";
	cout << "------------------------------------------------------------\n";
	for (auto el : points)
		el.print();
	cout << "------------------------------------------------------------\n";
}

void Triangle::save(fstream& fout)  {
	fout << "T ";
	for (int i = 0; i < points.size(); i++) {
		fout << points[i];
		if (i != points.size() - 1)
			fout << " ";
	}
	fout << ".\n";

}

void Triangle::load(fstream& fin)  {
	Point p;
	char c = ' ';
	while (c != '.') {
		fin >> p;
		points.push_back(p);
		fin.get(c);
	}
}