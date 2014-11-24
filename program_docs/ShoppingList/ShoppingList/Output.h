#pragma once
// Created by Will Plachno

#ifndef USRPUSH_H
#define USRPUSH_H
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

		/* static void Item(ListItem* item) */
		/* Prints the details of the item
		*/
		static void PrintItem(ListItem& item);
	};

#endif