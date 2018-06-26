//Main timer source file

#include "Timer.h"

int main()
{
	//Initialize Variables
	char Restart = 'n';
	string name;
	Timer timer;
	
	//greets the user and gets the users name
	Greet(name);

	do
	{
		//Initializing variables
		char chosenTime;
		unsigned int customHours;
		unsigned int customMinutes;
		unsigned int customSeconds;

		//asks if they want the default 15 minutes or put a custom time
		cout << "Would you like to set a custom time for me to remind you to take a break? Or would you like the default time?\n\td = Default, c = Custom:  ";
		cin >> chosenTime;

		if (chosenTime == 'd')
		{
			//does the actual counting down
			unsigned int totalTime;
			do
			{
				//These variables set the default in the class Timer so i can use them later on
				unsigned int defaultTimeHrs = timer.getTime(1);
				unsigned int defaultTimeMins = timer.getTime(2);
				unsigned int defaultTimeSecs = timer.getTime(3);

				//total time i am using this to count down till time is up and the alarm goes off
				totalTime = timer.getTime(1) + timer.getTime(2) + timer.getTime(3);

				cout << "****************************************************************\n";
				cout << "*HRS   MINS   SECS*\n";
				cout << "*" << timer.getTime(1) << "   :   " << timer.getTime(2) << "   :   " << timer.getTime(3) << "*" << endl;
				cout << "****************************************************************\n";
				Sleep(1000); //Makes the program wait a second
				system("cls");

				timer.setTime(3, (defaultTimeSecs - 1));
				if (timer.getTime(3) == 0 && timer.getTime(2) != 0)
				{
					timer.setTime(2, defaultTimeMins - 1);
					timer.setTime(3, defaultTimeSecs + 59);
				}
				if (timer.getTime(2) == 0 && timer.getTime(1) != 0)
				{
					timer.setTime(1, defaultTimeHrs - 1);
					timer.setTime(2, defaultTimeMins + 59);
				}
			} while (totalTime != 0);
			cout << "Would you like to restart?: ";
			cin >> Restart;
		}
		else if (chosenTime == 'c')
		{
			ChooseTime(customHours, customMinutes, customSeconds);
			unsigned int totalTime;
			do
			{
				//These variables set the default in the class Timer so i can use them later on
				unsigned int TimeHrs = timer.getTime(1);
				unsigned int TimeMins = timer.getTime(2);
				unsigned int TimeSecs = timer.getTime(3);

				//total time i am using this to count down till time is up and the alarm goes off
				totalTime = timer.getTime(1) + timer.getTime(2) + timer.getTime(3);

				cout << "****************************************************************\n";
				cout << "*HRS   MINS   SECS*\n";
				cout << "*" << timer.getTime(1) << "   :   " << timer.getTime(2) << "   :   " << timer.getTime(3) << "*" << endl;
				cout << "****************************************************************\n";
				Sleep(1000); //Makes the program wait a second
				system("cls");

				timer.setTime(3, (TimeSecs - 1));
				if (timer.getTime(3) == 0 && timer.getTime(2) != 0)
				{
					timer.setTime(2, TimeMins - 1);
					timer.setTime(3, TimeSecs + 59);
				}
				if (timer.getTime(2) == 0 && timer.getTime(1) != 0)
				{
					timer.setTime(1, TimeHrs - 1);
					timer.setTime(2, TimeMins + 59);
				}
			} while (totalTime != 0);
			
			cout << "Would you like to restart?: ";
			cin >> Restart;
		}
	} while (Restart == 'y');
	
	cout << "Goodbye " << name;
	system("pause");

	return 0;
}


