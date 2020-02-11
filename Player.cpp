/*********************************************************************
** Program Filename: Player.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class implementation file for the Player class.
** Input:
** Output:
*********************************************************************/

#include <iostream>
#include <string>
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

Player::Player()
{
	timer = 0;
	inventory[0] = EMPTY;
	inventory[1] = EMPTY;
	inventory[2] = EMPTY;
	snakes = true;
	statue = 0;
	win = false;
	
}

bool Player::getSnakes()
{
	return snakes;
}
void Player::setSnakes(bool sn)
{
	snakes = sn;
}
int Player::getStatue()
{
	return statue;
}
void Player::setStatue(int st)
{
	statue = st;
}
bool Player::getWin()
{
	return win;

}
void Player::setWin(bool w)
{
	win = w;

}
void Player::useInventory() 
{
	int choice;
	int use;
	int drop;
	int with;
	
	do
	{
		cout << endl;
		cout << "Your satchel contains:" << endl;
		displayInventory();
		cout << "Please enter an integer corresponding to the actions below : " << endl;
		cout << "1. Use item with" << endl;
		cout << "2. Drop item" << endl;
		cout << "3. Exit inventory" << endl;
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
		{
			cout << "Please select the item you wish to use below : " << endl;
			displayInventory();
			cout << "Item to use:";
			cin >> use;
			while (!cin || use < 1 || use >3)
			{
				cout << "Invalid selection" << endl;
				cout << "Please enter the number corresponding to your choice: ";
				cin.clear();
				cin.ignore();
				cin >> choice;
			}

			cout << "Please select the item you wish to use with ";
			printItem(inventory[use - 1]);
			cout << "." << endl;
			displayInventory();
			cout << "Item to use with ";
			printItem(inventory[use - 1]);
			cout << ":";
			cin >> with;
			while (!cin || with < 1 || with >3)
			{
				cout << "Invalid selection" << endl;
				cout << "Please enter the number corresponding to your choice: ";
				cin.clear();
				cin.ignore();
				cin >> choice;
			}

			if (inventory[use - 1] == UNLIT_TORCH && inventory[with - 1] == RITUAL_KNIFE || inventory[use - 1] == RITUAL_KNIFE && inventory[with - 1] == UNLIT_TORCH)
			{
				cout << "You light the torch by striking the Flint Ritual Knife with the steel buckle of your satchel." << endl;
				cout << "The flint ritual knife breaks in the process, and you discard it." << endl;
				cout << "You can now scare the snakes away!" << endl;
				inventory[use - 1] = FLAMING_TORCH;
				inventory[with - 1] = EMPTY;





			}

			else if (inventory[use - 1] == DIRT && inventory[with - 1] == LEATHER_POUCH || inventory[use - 1] == LEATHER_POUCH && inventory[with - 1] == DIRT)
			{
				cout << "You fill the pouch with the dirt." << endl;
				cout << "You can now retrieve the statue!" << endl;
				inventory[use - 1] = FILLED_POUCH;
				inventory[with - 1] = EMPTY;


			}

			else
				cout << "Nothing happens." << endl;
		}

		if (choice == 2)
		{
			cout << "Please select the item you wish to drop below or enter 4 to return to inventory: " << endl;
			displayInventory();
			cout << "Item to drop:";
			cin >> drop;
			while (!cin || drop < 1 || drop > 4)
			{
				cout << "Invalid selection" << endl;
				cout << "Please enter the number corresponding to your choice: ";
				cin.clear();
				cin.ignore();
				cin >> choice;
			}

			if (drop > 0 && drop < 4)
			{
				if (inventory[drop - 1] == EMPTY)
					cout << "Nothing to drop" << endl;
				else
				{
					cout << "You place ";
					printItem(inventory[drop - 1]);
					cout << " back where it was found" << endl;
					inventory[drop - 1] = EMPTY;
				}
			}
			
		}

	}while (choice != 3);

}
void Player::gather(item a)
{
	bool gather = false;
	int choice;
	
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		
		if(!gather)
		{
			if (inventory[i] == EMPTY)
			{
				inventory[i] = a;
				gather = true;
				cout << "You gathered ";
				printItem(a);
				cout << endl;
			}
		}
	

	}

	if (!gather)
	{
		cout << "Inventory Full" << endl;
		displayInventory();
		cout << "Please select an item to replace (by entering the number of the space) or enter 4 to leave the item: ";
		cin >> choice;
		while (!cin || choice < 1 || choice > 4)
		{
			cout << "Invalid selection" << endl;
			cout << "Please select an item to replace:";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
		if (choice > 0 && choice < 4)
		{
			cout << "You place ";
			printItem(inventory[choice-1]);
			cout << " back where it was found and pick up ";
			printItem(a);
			inventory[choice-1] = a;
		}
		
	}
	


}
void Player::displayInventory()
{
	

	for (int i = 0; i < 3; i++)
	{
		cout << "Space " << i + 1 << ": ";
		if (inventory[i] == EMPTY)
			cout << "Empty" << endl;
		if (inventory[i] == UNLIT_TORCH)
			cout << "Unlit torch" << endl;
		if (inventory[i] == RITUAL_KNIFE)
			cout << "Flint ritual knife" << endl;
		if (inventory[i] == FLAMING_TORCH)
			cout << "Flaming torch" << endl;
		if (inventory[i] == LEATHER_POUCH)
			cout << "Leather Pouch" << endl;
		if (inventory[i] == DIRT)
			cout << "Dirt" << endl;
		if (inventory[i] == FILLED_POUCH)
			cout << "Dirt filled pouch" << endl;
		if (inventory[i] == JADE_STATUE)
			cout << "Jade Statue" << endl;
	}


}
void Player::printItem(item p)
{
	if (p == EMPTY)
		cout << "Empty";
	if (p == UNLIT_TORCH)
		cout << "Unlit torch";
	if (p == RITUAL_KNIFE)
		cout << "Flint ritual knife";
	if (p == FLAMING_TORCH)
		cout << "Flaming torch";
	if (p == LEATHER_POUCH)
		cout << "Leather Pouch";
	if (p == DIRT)
		cout << "Dirt";
	if (p == FILLED_POUCH)
		cout << "Dirt filled pouch";
	if (p == JADE_STATUE)
		cout << "Jade Statue";

}

Player::item Player::getInventory(int i)
{
	return inventory[i];


}

void Player::incrementTimer()
{
	timer++;


}
int Player::getTimer()
{

	return timer;

}
void Player::clearInventory()
{

	inventory[0] = JADE_STATUE;
	inventory[1] = EMPTY;
	inventory[2] = EMPTY;

}