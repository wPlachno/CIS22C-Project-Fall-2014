// Created by Will Plachno

#ifndef DIVIDEDSCREEN_H
#define DIVIDEDSCREEN_H
#include "Screen.h"

/* class DividedScreen
	A special screen with a horizontal division
   Variables:
   - int   divRow - the row at which to print the divider
   - char* header - the string to print in the top section
   Functions:
   - int   Display()
   - void  Header(char* newHeader)
   - char* Header()
   - void  Division(int divisionRow)
   - int   Division()
   - void  printDividedScreen
*/

class DividedScreen :
	public Screen
{
public:
	/*
	DividedScreen()
	Generic Constructor
	*/
	DividedScreen() : Screen(), header("No header entered."), divRow(SCREENHEIGHT / 2 - 1) {}
	
	/*
	DividedScreen( char* header )
	Generic Constructor + header
	*/
	DividedScreen(char* header) : Screen(), header(header), divRow(SCREENHEIGHT / 2 - 1) {}

	/*
	~DividedScreen()
	Generic Destructor
	*/
	~DividedScreen() { header = nullptr; divRow = 0; }

	/*
	int Display()
	calls PrintDividedScreen, then system(pause)
	*/
	virtual int Display();

	/*
	void Header(char* newHeader)
	Setter for the header member variable
	*/
	void Header(char* newHeader) { header = newHeader; }

	/*
	char* Header()
	Accessor for the header member variable
	*/
	char* Header() { return header; }

	/*
	void Division(int divisionRow)
	Setter for divRow member variable
	*/
	void Division(int divisionRow) { divRow = divisionRow; }

	/*
	Accessor for divRow member variable
	*/
	int Division() { return divRow; }

protected:

	/*
	void printDividedScreen()
	prints the content of the screen
	Note: this does not do the system(pause)
	*/
	void printDividedScreen();

	/*
	int divRow
	the row index in which to display the division
	Access/set: Division()
	*/
	int divRow;

	/*
	char* header
	the string to print in the header space
	Access/set: Header()
	*/
	char* header;
};

#endif