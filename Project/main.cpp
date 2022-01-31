#include "menu.h"
fstream& operator>>(fstream& fin, Point& p) {
	fin >> p.x >> p.y;
	return fin;
}

fstream& operator<<(fstream& fout, Point& p) {
	fout << p.x << " " << p.y;

	return fout;
}

int main() {
	menu m("figures.txt");
	//m.add_new_figure(new Square({ Point(1, 2), Point(1, 2), Point(2, 1), Point(2, 2) }));
	//m.add_new_figure(new Line(Point(1, 2), Point(1, 5)));
	//m.add_new_figure(new Rhombus(Point(0, 0), { Point(0,1),Point(1,0),Point(-1,0),Point(0,-1) }));
	//m.add_new_figure(new Triangle({ 1,2 }, {1,-2}, {0,3}));

	m.print();
	m.save();
	return 0;
}