/*********************************************************************
** Program Filename: Sacrifice.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Sacrifice class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Sacrifice.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Sacrifice::Sacrifice()
{
	name = "Ritual Sacrifice Room";


}
Space* Sacrifice::menu(Space* loc, Player* p)
{
	int choice;
	cout << endl;
	cout << "You're in the Ritual Sacrific Room." << endl;
	cout << "There is a sacrificial altar in the middle of the room, and not much else of note." << endl;
	cout << "Please enter an integer corresponding to the actions below:" << endl;
	cout << "1. Move to another location" << endl;
	cout << "2. Open bag and use inventory" << endl;
	cout << "3. Examine sacrificial altar" << endl;
	cout << "Action selection: ";
	cin >> choice;
	while (!cin || choice < 1 || choice >3)
	{
		cout << "Invalid selection" << endl;
		cout << "Please enter the number corresponding to your choice: ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}

	if (choice == 1)
		return loc->move(loc);
	else if (choice == 2)
	{
		p->useInventory();
		return loc;
	}
	else if (choice == 3)
	{
		cout << endl;
		cout << "The altar is stained red with blood, there are several flint ritual knives on the altar" << endl;
		cout << "The flint knife could be used to make a spark, with the buckle on your satchel" << endl;
		cout << "You would just need something to use the flint on to make fire. You attempt to pick-up the knife" << endl;
		p->gather(Player::RITUAL_KNIFE);
		return loc;
	}



}
//virtual void special();







