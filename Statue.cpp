/*********************************************************************
** Program Filename: Statue.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Statue class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Statue.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Statue::Statue()
{
	name = "Jade Statue Room";


}

Space* Statue::menu(Space* loc, Player* p)
{
	int choice;
	

	if (p->getSnakes())
	{
		cout << endl;
		cout << "You're in the Jade Statue Room!  The floor is covered in snakes, you hate snakes!" << endl;
		cout << "You must find a way to scare the snakes away" << endl;
		cout << "Please enter an integer corresponding to the actions below:" << endl;
		cout << "1. Move to another location" << endl;
		cout << "2. Open bag and use inventory" << endl;
		cout << "3. Scare snakes away" << endl;
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
			if (p->getInventory(0) == Player::FLAMING_TORCH || p->getInventory(1) == Player::FLAMING_TORCH || p->getInventory(2) == Player::FLAMING_TORCH)
			{
				cout << "You wave the flaming torch around near the snakes, the snakes primal fear of fire kicks in and they slither away" << endl;
				p->setSnakes(false);

			}
			else
			{
				cout << "You wave your arms and yell to try to scare the snakes." << endl;
				cout << "But the snakes know you are more afraid of them, than they are of you." << endl;
				cout << "You must find another way to scare them, maybe something every animal fears?" << endl;
			}
			return loc;

		}
	}
	else if (!(p->getSnakes()))
	{
		cout << endl;
		cout << "You're in the Jade Statue Room.  You have cleared the snakes and can now approach the statue" << endl;
		cout << "Please enter an integer corresponding to the actions below:" << endl;
		cout << "1. Move to another location" << endl;
		cout << "2. Open bag and use inventory" << endl;
		cout << "3. Retrieve Jade Statue" << endl;
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
			if (p->getInventory(0) == Player::FILLED_POUCH || p->getInventory(1) == Player::FILLED_POUCH || p->getInventory(2) == Player::FILLED_POUCH)
			{
				cout << "You are a genius to think of swapping the statue with equal weight of a leather pouch and dirt." << endl;
				cout << "You judge the weight of the statue with pouch and remove a small handful of dirt" << endl;
				cout << "Never having done this before in your life, you nonetheless deflty swap the statue and the pouch." << endl;
				cout << "You place the Jade Statue into your satchel." << endl;
				p->setStatue(1);
				
			}
			else
			{
				cout << "The statue is on a pedestal that has a weight trap that will trigger if you remove the statue." << endl;
				cout << "You will need to find something to swap the statue with." << endl;
			}
			return loc;

		}

	}
}
//virtual void special();







