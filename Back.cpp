/*********************************************************************
** Program Filename: Back.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Back class.
** Input:
** Output:
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Back.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Back::Back()
{
	name = "Back Entrance Room";


}

Space* Back::menu(Space* loc, Player* p)
{
	int choice;
	cout << endl;
	cout << "You're in the Back Entrance.  There are many unlit torches left in the corner of the room" << endl;
	cout << "Please enter an integer corresponding to the actions below:" << endl;
	cout << "1. Move to another location" << endl;
	cout << "2. Open bag and use inventory" << endl;
	cout << "3. Retrieve torch" << endl;
	cout << "Action selection: ";
	cin >> choice;
	while (!cin || choice < 1 || choice > 3)
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
		cout << "You walk over and attempt to pick up one of the many unlit torches in the room" << endl;
		cout << "Now you just need an ignition source" << endl;
		p->gather(Player::UNLIT_TORCH);
		return loc;
	}



}
//virtual void special();







