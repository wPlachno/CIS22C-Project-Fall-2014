// Created by Will Plachno
/* Implementation file for class DividedScreen

implements:
- int Display()
- void printDividedScreen()
*/

#include "DividedScreen.h"
#include <iostream>

/*
int Display()
calls PrintDividedScreen, then system(pause)
*/
int DividedScreen::Display()
{
	printDividedScreen();
	system("pause");
	return 0;
}

/*
void printDividedScreen()
prints the content of the screen
Note: this does not do the system(pause)
*/
void DividedScreen::printDividedScreen()
{
	// Print top Border
	print();

	// Print header until division row
	print(header, divRow - 1, 0);

	// Print divRow
	print();

	// Print prompt until bottom border
	print(prompt, SCREENHEIGHT - divRow - 3, 0);

	// Print bottom border
	print();
}