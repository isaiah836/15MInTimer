//This will keep track of the time

#include <iostream>
#include "Timer.h"

//function that sets the hours, minutes and seconds
void Timer::setTime(int customTimeUnit, unsigned int customTime)
{
	if (customTimeUnit == 1)
	{
		timeHours = customTime;
	}
	else if (customTimeUnit == 2)
	{
		timeMinutes = customTime;
	}
	else if (customTimeUnit == 3)
	{
		timeSeconds = customTime;
	}
}
//gets the Hours, minutes and Seconds
unsigned int Timer::getTime(int unitOfTime)
{
	if (unitOfTime == 1)
	{
		return timeHours;
	}
	else if (unitOfTime == 2)
	{
		return timeMinutes;
	}
	else if (unitOfTime == 3)
	{
		return timeSeconds;
	}
}