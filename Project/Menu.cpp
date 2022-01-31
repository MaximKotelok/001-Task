#include "Menu.h"

menu::menu(string path) {
	this->path = path;
	Figure* f;
	fs.open(path, fstream::in);
	char c;
	while (fs >> c) {
		switch (c) {
		case 'S': {
			Square s;
			s.load(fs);
			f = new Square(s);
		}break;
		case 'L': {
			Line l;
			l.load(fs);
			f = new Line(l);
		}break;
		case 'R': {
			Rhombus r;
			r.load(fs);
			f = new Rhombus(r);
		}break;
		case 'T': {
			Triangle t;
			t.load(fs);
			f = new Triangle(t);
		}break;

		default:
			f = new Square({ {1,2},{1,2},{1,2},{1,2} });
		}

		figures.push_back(f);
	}

	fs.close();

}

void menu::add_new_figure(Figure* f) {
	figures.push_back(f);
}
void menu::print() {
	for (auto el : figures)
		el->print();
}

void menu::save() {
	fs.open(path, fstream::out);
	for (auto& el : figures)
		el->save(fs);
	fs.close();
}

menu::~menu() {
	for (auto& el : figures)
		delete el;
}