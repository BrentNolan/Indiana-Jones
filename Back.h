/*********************************************************************
** Program Filename: Back.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Back class.
** Input:
** Output:
*********************************************************************/

#ifndef BACK_NOLAN
#define BACK_NOLAN
#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Back : public Space
{
protected:


public:
	Back();
	virtual Space* menu(Space* loc, Player* p);
	//virtual void special();







};


#endif



