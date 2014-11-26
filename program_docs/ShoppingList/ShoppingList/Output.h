#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "ListItem.h"

/* class Push
This class will hold all the code, in static functions,
for printing to the terminal.
*/
class Output
{
public:

	/* static void Landing() */
	/* Prints the landing page for the application.
	*/
	static void PrintLanding();

	/* static void MainMenu() */
	/* Prints the Main Menu of the application
	*/
	static void PrintMainMenu();

	/* static void PrintError(string errMsg) */
	/* Prints an error line with the errMsg
	*/
	static void PrintError(const std::string errMsg);

	/* static void Item(ListItem* item) */
	/* Prints the details of the item
		Replaces empty members with "N/A"
	*/
	static void PrintItem(ListItem& item);
};

#endif