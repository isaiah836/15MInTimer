//Main timer source file

#include "Timer.h"

int main()
{
	//Initialize Variables
	char Restart = 'n';
	string name;
	srand(static_cast<unsigned int>(time(0))); // seed the random generator
	//default time for the time class
	unsigned int DEFAULTTIMEHRS = 0;
	unsigned int DEFAULTTIMEMINS = 15;
	unsigned int DEFAULTTIMESECS = 59;
	Timer timer; //creates an object
	string Messages[3]; // an array with with 3 messages
	int numMessages = 0;
	Messages[numMessages++] = "starting to look like a potato. you should take a break and stand up";
	Messages[numMessages++] = "Get up and boogie a bit.";
	Messages[numMessages++] = "Time-bot the defender is here to let you know its time to stand and stretch.";
	
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

		//resets to the defaults
		timer.setTime(1, DEFAULTTIMEHRS);
		timer.setTime(2, DEFAULTTIMEMINS);
		timer.setTime(3, DEFAULTTIMESECS);

		//IF USER INPUTS D USES DEFUALT SETTINGS
		if (chosenTime == 'd')
		{
			system("cls");
			//does the actual counting down
			unsigned int totalTime;
			do
			{
				//These variables set the default in the class Timer so i can use them later on
				unsigned int updateTimeHrs = timer.getTime(1);
				unsigned int updateTimeMins = timer.getTime(2);
				unsigned int updateTimeSecs = timer.getTime(3);

				//total time i am using this to count down till time is up and the alarm goes off
				totalTime = timer.getTime(1) + timer.getTime(2) + timer.getTime(3);

				//Display the timer to the user
				cout << "****************************************************************\n";
				cout << "*HRS    MINS    SECS*\n";
				cout << "*" << timer.getTime(1) << "   :   " << timer.getTime(2) << "   :   " << timer.getTime(3) << "*" << endl;
				cout << "****************************************************************\n";
				Sleep(1000); //Makes the program wait a second
				system("cls");
				//counts the seconds down to zero
				timer.setTime(3, (updateTimeSecs - 1));
				//when seconds is at zero subtract from minutes and set seconds to 59
				if (timer.getTime(3) == 0 && timer.getTime(2) != 0)
				{
					timer.setTime(2, updateTimeMins - 1);
					timer.setTime(3, updateTimeSecs + 59);
				}
				//when minutes reach zero subtract from hours and set minutes to 59
				if (timer.getTime(2) == 0 && timer.getTime(1) != 0)
				{
					timer.setTime(1, updateTimeHrs - 1);
					timer.setTime(2, updateTimeMins + 59);
				}
			} while (totalTime != 0);

			//picks a random message from the message array
			cout << name << "\n" << Messages[rand() % 2];
			cout << "\n\nWould you like to restart?: ";
			cin >> Restart;
		}

		//this runs if they want their own time used
		else if (chosenTime == 'c')
		{
			//Asks when the user wants the alarm to go off
			cout << "How many hours do you want?: ";
			cin >> customHours;
			timer.setTime(1, customHours);

			cout << "How many minutes do you want?: ";
			cin >> customMinutes;
			timer.setTime(2, customMinutes);

			cout << "How many second do you want?: ";
			cin >> customSeconds;
			timer.setTime(3, customSeconds);
			system("cls");

			//variable for count down timer
			unsigned int totalTime;

			//This will loop until time is up
			do
			{
				//These variables set the default in the class Timer so i can use them later on
				unsigned int TimeHrs = timer.getTime(1);
				unsigned int TimeMins = timer.getTime(2);
				unsigned int TimeSecs = timer.getTime(3);

				//total time i am using this to count down till time is up and the alarm goes off
				totalTime = timer.getTime(1) + timer.getTime(2) + timer.getTime(3);

				//Displays to the user the time they have left until alarm goes off
				cout << "*******************\n";
				cout << "*HRS    MIN    SEC*\n";
				cout << "*" << timer.getTime(1) << "   :   " << timer.getTime(2) << "   :   " << timer.getTime(3) << "*" << endl;
				cout << "*******************\n";
				Sleep(1000); //Makes the program wait a second
				system("cls");
				//takes way every time a second goes by
				timer.setTime(3, (TimeSecs - 1));
				//takes away a minute everytime a minute goes by
				if (timer.getTime(3) == 0 && timer.getTime(2) != 0)
				{
					timer.setTime(2, TimeMins - 1);
					timer.setTime(3, TimeSecs + 59);
				}
				// Takes away an hour every hour that goes by
				if (timer.getTime(2) == 0 && timer.getTime(1) != 0)
				{
					timer.setTime(1, TimeHrs - 1);
					timer.setTime(2, TimeMins + 59);
				}

			} while (totalTime != 0);

			//picks a random messages from the message array
			cout << name << "\n" << Messages[rand() % 2];
			//asks the user if they want to restart
			cout << "\n\nWould you like to restart?: (y) yes or (n) no:  ";
			cin >> Restart;
		}
	} while (Restart == 'y');
	
	cout << "Goodbye " << name << endl;
	system("pause");

	return 0;
}


