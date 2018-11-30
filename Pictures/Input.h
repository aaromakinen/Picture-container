#pragma once
#include<iostream>
using namespace std;
class Input
{
public:
	Input();
	~Input();
	bool checkint(int input, bool def = false);
	bool checkword(string input);
};

