#include "Shapes.h"
class menu {
	vector<Figure*> figures;
	fstream fs;
	string path;
public:
	menu(string path);

	void add_new_figure(Figure* f);

	void print();

	void save();

	~menu();

};