/*********************************************************************
** Program Filename: Jungle.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Jungle class.
** Input:Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/

#ifndef JUNGLE_NOLAN
#define JUNGLE_NOLAN
#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Jungle : public Space
{
protected:
	

public:
	Jungle();
	virtual Space* menu(Space* loc, Player* p);
	//virtual void special();







};


#endif


