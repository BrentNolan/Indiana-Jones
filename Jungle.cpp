/*********************************************************************
** Program Filename: Jungle.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Jungle class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Jungle.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


Jungle::Jungle()
{
	name = "Jungle";


}

Space* Jungle::menu(Space* loc, Player* p)
{
	
	int choice;
	cout << endl;
	cout << "You're in the jungle, welcome to the jungle!" << endl;
	cout << "Just outside the temple, the temple has many cracks in the walls that allow you to enter any room." << endl;
	cout << "There is not much around except dirt and foliage" << endl;
	cout << "Please enter an integer corresponding to the actions below:" << endl;
	cout << "1. Move to another location" << endl;
	cout << "2. Open bag and use inventory" << endl;
	cout << "3. Gather dirt" << endl;
	cout << "Action selection: ";
	cin >> choice;
	while(!cin || choice < 1 || choice >3)
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
		p->gather(Player::DIRT);
		return loc;
	}





}
//virtual void special();







