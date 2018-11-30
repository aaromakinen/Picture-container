#include "stdafx.h"
#include "Menu.h"

#include <iostream>
using namespace std;


Menu::Menu()
{
	int user = 0;
	bool correct;
	c.read();
	do {
		cout << "1. Initialize \n2. Save to disk\n3. Read from disk\n4. Add new picture\n5. Remove picture\n6. Print with specified people count\n7. Print all\n0. Exit\n";
		cin >> user;
		correct = i.checkint(user);				//Typical menu interface that the user interacts with number input. Calls for input object to check correctness of the input
		if (correct) {
			if (user == 1 ) {
				c.initialize();
			}
			if (user == 2 ) {
				c.save();
			}
			if (user == 3 ) {
				c.read();
			}
			if (user == 4) {
				c.add();
			}
			if (user == 5) {
				c.remover();
			}
			if (user == 6) {
				c.defreport();
			}
			if (user == 7) {
				c.report();
			}
		}
	} while (user != 0);
}
Menu::~Menu()
{
}
