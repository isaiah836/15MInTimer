#pragma once
#include <iostream>
#include <string>
#include "Windows.h"
#include <ctime>

//using stuff from the standard library and strings
using std::cout;
using std::cin;
using std::string;
using std::endl;


//Declare timer class
class Timer
{
public:
	void setTime(int customTimeUnit, unsigned int customTime);
	unsigned int getTime(int unitOfTime);

private:
	unsigned int timeHours = 0;
	unsigned int timeMinutes = 15;
	unsigned int timeSeconds = 59;
};

//Declare Functions
string usersName(string question);
//function that greets the user 
void Greet(string& name);
