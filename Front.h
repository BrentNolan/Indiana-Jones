/*********************************************************************
** Program Filename: Front.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Front class.
** Input:Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/

#ifndef FRONT_NOLAN
#define FRONT_NOLAN
#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Front : public Space
{
protected:


public:
	Front();
	virtual Space* menu(Space* loc, Player* p);
	//virtual void special();







};


#endif


