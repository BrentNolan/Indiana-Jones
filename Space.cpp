/*********************************************************************
** Program Filename: Space.cpp
** Author: Brent Nolan
** Date: 8/3/16
** Description: This is the class implementation file for the Space abstract class.
** Input: 
** Output: 
*********************************************************************/

#include "Space.h"
#include "Player.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;



Space::Space()
{
	pointer1 = NULL;
	pointer2 = NULL;
	pointer3 = NULL;
	pointer4 = NULL;


}
		
Space* Space::move(Space* loc)
{
	int selection;
	cout << endl;
	cout << "1.Move to " << pointer1->displayName() << endl;
	cout << "2.Move to " << pointer2->displayName() << endl;
	cout << "3.Move to " << pointer3->displayName() << endl;
	cout << "4.Move to " << pointer4->displayName() << endl;
	cout << "5.Don't move" << endl;
	cout << "Please enter the number corresponding to your choice: ";
	
	cin >> selection;
	while (!cin || selection <1 || selection > 5)
		{
		cout << "Invalid selection" << endl;
		cout << "Please enter the number corresponding to your choice: ";
		cin.clear();
		cin.ignore();
		cin >> selection;
		}


	if (selection == 1)
		return pointer1;
	else if (selection == 2)
		return pointer2;
	else if (selection == 3)
		return pointer3;
	else if (selection == 4)
		return pointer4;
	else if (selection == 5)
		return loc;



}
string Space::displayName()
{
	return name;
}
void Space::setPointer1(Space* one)
{
	pointer1 = one;
}
Space* Space::getPointer1()
{
	return pointer1;
}
void Space::setPointer2(Space* two)
{
	pointer2 = two;
}
Space* Space::getPointer2()
{
	return pointer2;
}
void Space::setPointer3(Space* three)
{
	pointer3 = three;
}
Space* Space::getPointer3()
{
	return pointer3;
}
void Space::setPointer4(Space* four)
{
	pointer4 = four;
}
Space* Space::getPointer4()
{
	return pointer4;
}








