/*********************************************************************
** Program Filename: Statue.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Statue class.
** Input:
** Output:
*********************************************************************/

#ifndef STATUE_NOLAN
#define STATUE_NOLAN
#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Statue : public Space
{
protected:


public:
	Statue();
	virtual Space* menu(Space* loc, Player* p);
	//virtual void special();







};


#endif

