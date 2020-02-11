/*********************************************************************
** Program Filename: Secret.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Secret class.
** Input: user input of menu choices.
** Output:print and return location to main.
*********************************************************************/

#ifndef SECRET_NOLAN
#define SECRET_NOLAN
#include <iostream>
#include <string>
#include "Space.h"
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Secret : public Space
{
protected:


public:
	Secret();
	virtual Space* menu(Space* loc, Player* p);
	//virtual void special();







};


#endif