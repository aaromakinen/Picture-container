#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Picture
{
	friend ostream& operator<<(ostream &out, Picture picture);
	//friend istream& operator>>(istream &in, Picture picture);		//failed attempt. Left for implementation option.
public:
	Picture();
	Picture(string& name,string& desc,string& loc,int peop=0);
	void deflist(int count,bool defined=true);
	~Picture();
	string getname();
	//void read();
	void set_filename(string name);
	void set_description(string desc);
	void set_location(string loc);
	void set_people(int peop);
private:
	string filename;
	string description;
	string location;
	int people;
	
};

