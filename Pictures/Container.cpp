#include "stdafx.h"
#include "Container.h"
#include<vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Container::Container()
{
}


Container::~Container()
{
}

void Container::add() {
	bool correct = false;
	string filename,description,location;
	int people = 0;
	do {
		cout << "What is the filename? (Only alphabets and max character count 25)\n";		//asks the input and keeps asking it until correct input is given
		cin >> filename;
		correct = checker.checkword(filename);
	} while (!correct);
	do {
		cout << "What is the description? (Only alphabets and max character count 25)\n"; //asks the input and keeps asking it until correct input is given
		cin >> description;
		correct = checker.checkword(description);
	} while (!correct);
	do {
		cout << "What is the location? (Only alphabets and max character count 25)\n";	//asks the input and keeps asking it until correct input is given
		cin >> location;
		correct = checker.checkword(location);
	} while (!correct);
	do {
		cout << "How many people are in the picture? (max count 100)\n";	//asks the input and keeps asking it until correct input is given
		cin >> people;
		correct = checker.checkint(people,true);
	} while (!correct);
	Picture temp(filename, description, location, people);			//makes temporary Picture object with given values and puts it in the vector
	v.push_back(temp);
	count++;
}
void Container::initialize() {
	v.clear();			//clears the vector
	
}
void Container::save() {
	remove("test.txt");			//deletes the old file if exists
	ofstream out("test.txt");	//opens or creates the file
	it = v.begin();				//makes iterator it having the beginning of the vector
	int i = 0;
	while (it != v.end()) {		//goes through every elemnt on the vector and pushes them to output buffer and to teh file
		out << v[i];
		i++;
		it++;
	}
	out.close();			//closes the file
}
void Container::read() {
	v.clear();					//clears the vector
	ifstream in("test.txt");	//opens the file
	if (in.good()) {			//if the file exists it will continue otherwise displays error
		string name, desc, loc, str_count, line, new_line;
		int count = 0;
		Picture temp;
		while (getline(in, name) && getline(in, desc) && getline(in, loc) && getline(in, str_count) && getline(in, new_line)) {		//reads all info to variables and newline that is
			name.erase(0, 10);																										//separating them in file
			desc.erase(0, 13);
			loc.erase(0, 10);
			str_count.erase(0, 14);																									//erases explanation information in the file 
			count = stoi(str_count);																								//converts string to int
			temp.set_filename(name), temp.set_description(desc), temp.set_location(loc), temp.set_people(count);
			v.push_back(temp);																										//makes temporary Picture object with given values and puts it in the vector
		}

	}
	else {
		cout << "Error reading the file\n";

	}
}
void Container::remover() {
	string input;
	bool correct;
	int orig = v.size();
	do {
		cout << "What is the pictures filename?\n";		//asks input until correct
		cin >> input;
		correct = checker.checkword(input);
	} while (!correct);

	it = v.begin();
	while (it !=  v.end()) {
		if (it->getname() == input) { //goes through every element in the vector and check if there is a element with the same filename and erases it
			it=v.erase(it);
			
		}
		else it++;
	}
	if(orig==v.size()){
		cout << "Picture not found!\n";			//compares the length at the beginning of this function and after to determine if there were anything erased
	}

}
void Container::defreport() {
	
	int people;
	bool correct;
	do {
		cout << "How many people atleast?(Max 100)\n";
		cin >> people;
		correct = checker.checkint(people, true);			// boolean true so input objects knows that it is people count input check
	} while (!correct);

	for (it = v.begin(); it != v.end(); ++it) {			//goes through every element in the vector and calls the deflist function for all of them gives minimum wanted people count as parameter
		it->deflist(people);
	}

}
void Container::report() {
	
	for (it = v.begin(); it != v.end(); ++it) {	//goes through every element in the vector and calls the deflist function for all of them
		it->deflist(0,false);					//boolean false so deflist function knows it is to print all pictures
	}

}