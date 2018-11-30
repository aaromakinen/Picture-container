#include "stdafx.h"
#include "Picture.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Picture::Picture() {}
Picture::Picture(string& name, string& desc, string& loc, int peop)
{
	filename = name;
	description = desc;
	location = loc;
	people = peop;
}


Picture::~Picture()
{
}
void Picture::deflist(int count,bool defined) {
	if (!defined) {
		if (people == 0) {
			cout << " * Filename: " << filename << " Description: " << description << " Location: " << location << endl;		//for when wanted people count is not defined. * if the people count in the picture is 0
		}
		else {
			cout << "Filename: " << filename << " Description: " << description << " Location: " << location << " People: " << people << endl;
		}
	}
	else {
		if (count <= people) {
			cout << "Filename: " << filename << " Description: " << description << " Location: " << location << " People: " << people << endl;		//for defined people count
		}
	}
}
string Picture::getname() {
	return filename;
}

ostream& operator<<(ostream &out, Picture picture) {

	out << "Filename: " << picture.filename << endl << "Description: " << picture.description << endl << "Location: " << picture.location << endl << "People count: " << picture.people << endl << "\n";
	
	return out;			//Puts information in the right format to the file
}
/*istream& operator>>(istream &in, Picture picture) {
	
	in >> picture.filename >> picture.description >> picture.location >> picture.people;
	return in;
}*/
/*void Picture::read() {																							//failed attempt. Left for implementation option.
	ifstream in("test.txt");
	in >> filename >> description >> location >> people;
	in.close();
}*/
void Picture::set_filename(string name) {
	filename = name;
}
void Picture::set_description(string desc){
	description = desc;
}
void Picture::set_location(string loc) {
	location = loc;
}
void Picture::set_people(int peop) {
	people = peop;
}
