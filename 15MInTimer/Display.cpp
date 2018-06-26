//This will get and display information all the information for timer bot

#include "Timer.h"

//Gets the users name and greets the user
void Greet(string& name)
{
	cout << "Welcome, I am Time-Bot! Your humble defender.\n Every 15 minutes that pass I will remind you to get up out of your seat and take a break to stretch and move around Because I am sworn to protect your health.\n\n";
	name = usersName("What is your first name good sir?");
	cout << "\n\nHello " << name << "!";
}

//gets the users name for the greet function
string usersName(string question)
{
	string userName;
	cout << question << ": ";
	cin >> userName;
	for (unsigned int i = 0; i < userName.size(); ++i)
	{
		userName[i] = tolower(userName[i]);
	}
	return userName;
}
