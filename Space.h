/*********************************************************************
** Program Filename: Space.h
** Author: Brent Nolan
** Date: 8/3/2016
** Description: This is the class specification file for the Space abstract class.
** Input: move function will get a pointer to space class, all setters will get a pointer to space class
** Output: move function will return the location of the move, getters will return the pointer.
*********************************************************************/

#ifndef SPACE_NOLAN
#define SPACE_NOLAN
#include <iostream>
#include <string>
#include "Player.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Space
{
protected:
	string name;
	Space* pointer1;
	Space* pointer2;
	Space* pointer3;
	Space* pointer4;



public:
	Space();
	Space* move(Space* loc);
	string displayName();
	void setPointer1(Space* one);
	Space* getPointer1();
	void setPointer2(Space* two);
	Space* getPointer2();
	void setPointer3(Space* three);
	Space* getPointer3();
	void setPointer4(Space* four);
	Space* getPointer4();
	virtual Space* menu(Space* loc, Player* p) = 0;
	






};


#endif

