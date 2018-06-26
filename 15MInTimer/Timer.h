#pragma once
#include <iostream>
#include <string>
#include "Windows.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

//Declare Functions
string usersName(string question);
void ChooseTime(unsigned int& customHours, unsigned int& customMinutes, unsigned int& customSeconds);
void Greet(string& name);

//Declare class
class Timer
{
public:
	void setTime(int customTimeUnit, unsigned int customTime);
	unsigned int getTime(int unitOfTime);

private:
	unsigned int timeHours = 0;
	unsigned int timeMinutes = 15;
	unsigned int timeSeconds = 60;
};