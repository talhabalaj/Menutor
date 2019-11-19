#include "pch.h"
#include "Menutor.h"

Menutor::Menutor()
{
}

void Menutor::add(string m, std::function<void()> fun)
{
	// Create a new Menu Item
	MenuItem temp;
	temp.message = m;
	temp.function = fun;
	// Add it to the vector
	this->menuItems.push_back(temp);
}

void Menutor::add(string m, Menutor menu)
{
	// Create a new Menu Item
	MenuItem temp;
	temp.message = m;
	temp.subMenu = menu;
	// Add it to the vector
	this->menuItems.push_back(temp);
}


void Menutor::run()
{
	do {
		int menuChoice = -1;
		string choice;

		system("cls");

		this->display();
		cout << "e: for exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		try {
			menuChoice = stoi(choice);
		}
		catch (...) {
			if (choice == "e") {
				break;
			}
		}

		if (menuChoice != -1) {
			try {
				MenuItem& m = this->menuItems.at(menuChoice - 1);
				if (m.function != nullptr) m.function();
				else {
					m.subMenu.run();
				}
			}
			catch (out_of_range) {
				cout << "Invalid choice!" << endl;
			}
		}

		cout << "Press any button to continue" << endl;
		cin.get();

	} while (true);
}

void Menutor::display()
{
	int i = 1;
	for (MenuItem element : menuItems) {
		cout << i << ". " << element.message << endl;
		i++;
	}
}

