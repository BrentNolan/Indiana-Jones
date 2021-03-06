/*********************************************************************
** Program Filename: Front.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Front class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Front.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Front::Front()
{
	name = "Front Entrance Room";


}
Space* Front::menu(Space* loc, Player* p)
{
	int choice;
	cout << endl;
	cout << "You're in the Front Entrance." << endl;
	cout << "The only thing of note is the skeletal remains of an explorer" << endl;
	cout << "Please enter an integer corresponding to the actions below:" << endl;
	cout << "1. Move to another location" << endl;
	cout << "2. Open bag and use inventory" << endl;
	cout << "3. Examine remains of explorer" << endl;
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
		cout << "You examine the skeletal remains of an explorer who died some time ago from a dart trap." << endl;
		cout << "Luck for you he triggered the trap first!" << endl;
		
		if (p->getInventory(0) == Player::LEATHER_POUCH || p->getInventory(1) == Player::LEATHER_POUCH || p->getInventory(2) == Player::LEATHER_POUCH)
		{
			cout << "There is nothing left to take from the explorer" << endl;
		}
		else
		{
			cout << "You find a small leather pouch that is still intact and pick it up" << endl;
			p->gather(Player::LEATHER_POUCH);
		}
		return loc;
	}



}
//virtual void special();







