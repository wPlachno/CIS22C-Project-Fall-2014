// Created by Will Plachno

#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "DividedScreen.h"

/* class MenuScreen
	Divided screen specifically for displaying menus
   Variables:
	int maxChoice
   Functions:
	int Display()
*/

class MenuScreen :
	public DividedScreen
{
public:

	/*
	MenuScreen()
	Generic Constructor
	*/
	MenuScreen() : DividedScreen(), maxChoice(0) {}

	/*
	MenuScreen(char* header, int maxChoice)
	Constructor + header and maxchoice
	*/
	MenuScreen(char* newHeader, int newChoiceMax) : DividedScreen(newHeader), maxChoice(newChoiceMax) {}

	/*
	~MenuScreen()
	Generic Destructor
	*/
	~MenuScreen() { maxChoice = 0; }

	/*
	int Display()
	The display function
	prints the screen, then asks the user for input
	returns their choice
	*/
	virtual int Display();

private:

	/*
	bool isValidChoice(int usrInput, int numChoices)
	checks the user input to make sure its valid
	*/
	bool isValidChoice(int usrInput, int numChoices);

	/*
	int str2Int(char* input)
	Uses ascii codes to convert char* to int
	*/
	int str2Int(char* input);

	/*
	int maxChoice
	The max choice of the user.
	*/
	int maxChoice;
};

#endif