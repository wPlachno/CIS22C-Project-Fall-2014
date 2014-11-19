#pragma once
// Created by Will Plachno

#ifndef USRPUSH_H
#define USRPUSH_H
#include "ListItem.h"

// Use the UserIO Namespace
namespace UserIO
{

	/* class Push
		This class will hold all the code, in static functions,
		for printing to the terminal. 
	*/
	class Push
	{
	public:

		/* static void Landing() */
		/* Prints the landing page for the application.
		*/
		static void Landing();

		/* static void MainMenu() */
		/* Prints the Main Menu of the application
		*/
		static void MainMenu();

		/* static void Add() */
		/* Prints a prompt for adding a new item 
		*/
		static void Add();

		/* static void Delete() */
		/* Prints a prompt for deleting a new item
		*/
		static void Delete();

		/* static void Item(ListItem* item) */
		/* Prints the details of the item
		*/
		static void Item(ListItem* item);
	};
}

#endif