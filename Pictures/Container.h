#pragma once
#include <vector>
#include"Picture.h"
#include <fstream>
#include"Input.h"
#include<iostream>
using namespace std;

class Container
{
public:
	Container();
	void add();
	void initialize();
	void save();
	void read();
	void remover();
	void defreport();
	void report();
	~Container();
	
private:
	vector<Picture>v;
	vector<Picture>::iterator it;
	Input checker;
	int count = 0;
	
};

