/*********************************************************************
** Program Filename: Player.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Player class.
** Input:
** Output:
*********************************************************************/

#ifndef PLAYER_NOLAN
#define PLAYER_NOLAN
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Player
{
public:
	Player();
	enum item { EMPTY, UNLIT_TORCH, RITUAL_KNIFE, FLAMING_TORCH, LEATHER_POUCH, DIRT, FILLED_POUCH, JADE_STATUE };
	bool getSnakes();
	void setSnakes(bool sn);
	int getStatue();
	void setStatue(int st);
	void useInventory();
	void gather(item a);
	void displayInventory();
	void printItem(item p);
	item getInventory(int);
	void incrementTimer();
	int getTimer();
	bool getWin();
	void setWin(bool w);
	void clearInventory();
private:

	int timer;
	item inventory[3];
	bool snakes;
	int statue;
	bool win;
	


};

#endif