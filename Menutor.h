#include "pch.h"

using namespace std;

struct MenuItem;

class Menutor
{
	vector<MenuItem> menuItems;
public:
	Menutor();
	void add(string, std::function<void()>);
	void add(string, Menutor);
	void run();
	void display();
};

struct MenuItem {
	string message;
	std::function<void()> function;
	Menutor subMenu;
};
