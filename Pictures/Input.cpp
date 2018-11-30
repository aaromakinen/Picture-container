#include "stdafx.h"
#include "Input.h"
#include<limits>
#include <stdlib.h>
#include <iostream>
using namespace std;


Input::Input()
{
}


Input::~Input()
{
}
bool Input::checkint(int input, bool def) {
	system("CLS");			//clears the console and then checks out if the given int is correct. Variable def is to determine if it used as menu check or people count
	if (def == true) {
		if (input < 0 || input >100) {  //this is for poeople count
			cout << "Wrong input\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');		//clears input buffer
			return false;
		}
	}
	else {
		if (input < 0 || input>7) {
			cout << "Wrong input\n";		//this is for menu interface
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return true;
}
bool Input::checkword(string input) {
	system("CLS");
	int i = 0;
	if (input.length() >= 25) {		//check that the input length is equal or less than 25 characters
		return false;
	}
	while (i != (input.size())) {
		if ((input[i]) < 65 || (input[i])>122) {		//checks that all characters were either uppercase or lowercase characters
			cout << "Wrong input\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}
		if (input[i] > 90 && input[i] < 97) {
			cout << "Wrong input\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}
		i++;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return true;
}