/*********************************************************************
** Program Filename: main.cpp
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the main file.
** Input: limited to user input at the end
** Output: print to screen
*********************************************************************/


#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
#include "Jungle.h"
#include "Front.h"
#include "Back.h"
#include "Sacrifice.h"
#include "Statue.h"
#include "Secret.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



int main()
{
	Space* location;
	Player* player = NULL;
	Jungle* jungle = NULL;
	Front* front = NULL;
	Back* back = NULL;
	Sacrifice* sacrifice = NULL;
	Statue* statue = NULL;
	Secret* secret = NULL;
	
	player = new Player;
	jungle = new Jungle;
	front = new Front;
	back = new Back;
	sacrifice = new Sacrifice;
	statue = new Statue;
	int mainChoice;

	location = jungle;
	jungle->setPointer1(front);
	jungle->setPointer2(back);
	jungle->setPointer3(sacrifice);
	jungle->setPointer4(statue);

	front->setPointer1(jungle);
	front->setPointer2(back);
	front->setPointer3(sacrifice);
	front->setPointer4(statue);

	back->setPointer1(jungle);
	back->setPointer2(front);
	back->setPointer3(sacrifice);
	back->setPointer4(statue);

	sacrifice->setPointer1(jungle);
	sacrifice->setPointer2(front);
	sacrifice->setPointer3(back);
	sacrifice->setPointer4(statue);

	statue->setPointer1(jungle);
	statue->setPointer2(front);
	statue->setPointer3(back);
	statue->setPointer4(sacrifice);


	cout << "Welcome to Indiana Jones and the Jade Statue!" << endl;
	cout << endl;
	cout << "Press 1 to start the game" << endl;
	cout << "Press 2 to display tips and then start the game" << endl;
	cout << "Press 3 to display a detailed walthrough and then start the game" << endl;
	cout << "Selection: ";
	cin >> mainChoice;
	while (!cin || mainChoice < 1 || mainChoice >3)
	{
		cout << "Invalid selection" << endl;
		cout << "Please enter the number corresponding to your choice: ";
		cin.clear();
		cin.ignore();
		cin >> mainChoice;
	}

	if (mainChoice == 2)
	{
		cout << endl;
		cout << "This is an adventure game, thus you will need to gather items and combine items to use." << endl;
		cout << "Use some simple logic in combining items, for example fill a container with something" << endl;
		cout << "You only use the inventory to combine items or drop items, and only two items combine together." << endl;
	}
	if (mainChoice == 3)
	{
		cout << endl;
		cout << "Walkthrough:" << endl;
		cout << "In jungle, Gather dirt." << endl;
		cout << "Move to Back Entrance Room.  Gather torch." << endl;
		cout << "Move to Ritual Sacrifice Room. Examine sacrificial altar. Gather flint ritual knife." << endl;
		cout << "Open bag and use inventory.  Use torch with flint ritual knife." << endl;
		cout << "Move to Front Entrance Room. Examine Explorer.  Gather leather pouch." << endl;
		cout << "Open bag and use inventory.  Use dirt with leather pouch." << endl;
		cout << "Move to Jade Statue Room.  Scare snakes" << endl;
		cout << "Examine statue." << endl;
		cout << "Move to secret tunnel" << endl;
		cout << "Use whip to swing across." << endl;
		cout << "Win!" << endl;
			

	}
	cout << endl;
	cout << "You are Indiana Jones, you have recently discovered an ancient Mayan temple in Guatemala." << endl;
	cout << "You believe the temple contains a jade statue of the serpent god Kulkukan, and that statue belongs in a museum!" << endl;
	cout << "Your rival Belloq, wants to take the statue for himself and sell it." << endl;
	cout << "After narrowly escaping capture by Belloq, you sabotage his transportation and head off to the temple" << endl;
	cout << "You only have a small head start on Belloq, maybe 40 minutes (or 40 turns)" << endl;
	cout << "You only have your trusty bullwhip and an empty satchel for supplies" << endl;
	cout << "You arrive just outside the temple." << endl;
	
		do
		{
			location = location->menu(location, player);
			player->incrementTimer();
			if (player->getTimer() > 30 && player->getTimer() != 40)
			{
				cout << endl;
				cout << "WARNING YOU ONLY HAVE " << 40 - player->getTimer() << " TURNS LEFT!";

			}
		} while (player->getStatue() == 0 && player->getTimer() < 40);
		
		if (player->getStatue() == 1 && player->getTimer() < 40)
		{
			cout << endl;
			cout << "Your success is short lived.  The pouch was too light, the trap is triggered" << endl;
			cout << "The room shakes and you hear the ceiling start to collapse." << endl;
			cout << "You frantically run from the room and almost lose your fedora." << endl;
			cout << "You dive out of the room into the Ritual Sacrifice Room" << endl;
			cout << "Every entrance to the Jade Statue Room are blocked by rubble" << endl << endl;
			cout << "You look around and see a secret tunnel that was previously blocked by rubble, which was dislodged by the trap." <<endl;
			cout << "You also hear Belloq's men arriving outside the temple, you don't think you can use any of the other exits." << endl;

			delete statue;
			statue = NULL;
			secret = new Secret;

			jungle->setPointer4(secret);
			front->setPointer4(secret);
			back->setPointer4(secret);
			sacrifice->setPointer4(secret);
			secret->setPointer1(jungle);
			secret->setPointer2(front);
			secret->setPointer3(back);
			secret->setPointer4(sacrifice);

			location = sacrifice;
			player->clearInventory();

			while (location != secret)
			{

				location = location->move(location);
				if (location == sacrifice)
				{
					cout << endl;
					cout << "You must move or Belloq's men will catch you!";
					location = location->move(location);
				}
				if (location != secret)
				{
					cout << endl;
					cout << "As soon as you exit the Ritual sacrific room Belloq's men open fire! So you run back to the Ritual Sacrifice room." << endl;
					location = sacrifice;
				}
				if (location == secret)
					{
						while (!player->getWin())
						{
							location = location->menu(location, player);
						}

					}
			}

		}
		if (player->getTimer() > 39)
		{
			cout << endl;
			cout << "Belloq has arrived, he surrounds the temple, you have no chance of escaping."<< endl;
			cout << "GAME OVER!";
		}
		if (player->getWin())
		{
			cout << "The tunnel leads you right to Belloq's jeeps, which are completely undefended." << endl;
			cout << "You drive away into the sunset on your way to donating the Jade Statue of Kulkukan to a museum!" << endl;
		}


delete player;
delete jungle;
delete front;
delete back;
delete sacrifice;
delete secret;

player = NULL;
jungle = NULL;
front = NULL;
back = NULL;
sacrifice = NULL;
secret = NULL;

cin.get();
cin.get();

	return 0;
}
