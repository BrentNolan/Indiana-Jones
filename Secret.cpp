/*********************************************************************
** Program Filename: Secret.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Secret class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Secret.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Secret::Secret()
{
	name = "Secret tunnel";


}

Space* Secret::menu(Space* loc, Player* p)
{

	int choice;
	cout << endl;
	cout << "You're in the Secret tunnel!" << endl;
	cout << "You run down the tunnel for several hundred yards." << endl;
	cout << "You encounter a chasm, but can see light of the exit just passed the chasm." << endl;
	cout << "There is a large tree root that you think you can reach with your bullwhip" << endl;
	cout << "Please enter an integer corresponding to the actions below:" << endl;
	cout << "1. Move to another location" << endl;
	cout << "2. Swing across the chasm" << endl;
	cout << "Action selection: ";
	cin >> choice;
	while (!cin || choice < 1 || choice >2)
	{
		cout << "Invalid selection" << endl;
		cout << "Please enter the number corresponding to your choice: ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}

	if (choice == 1)
	{
		cout << "You have a bad feeling about this, and won't go back to the temple." << endl;
		return loc;
	}
	else if (choice == 2)
	{
		cout << endl;
		cout << "You pull out your bull whip and swing it with a crack, and it wraps around the tree root." << endl;
		cout << "You swing across the chasm and run to the exit." << endl;
		p->setWin(true);
		return loc;
	}
}