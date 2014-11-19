#pragma once
// Created by Will Plachno

#ifndef USRPULL_H
#define USRPULL_H

// Use the UserIO Namespace
namespace UserIO
{
	/* enum MainMenuOptions */
	/* Contains the choices for the main menu
	*/
	enum MainMenuOption {
		OPTION_ADD			= 1,
		OPTION_DELETE		= 2,
		OPTION_PRIMARYKEY	= 3,
		OPTION_HASHSEQ		= 4,
		OPTION_KEYSEQ		= 5,
		OPTION_BST			= 6,
		OPTION_EFFICIENCY	= 7,
		OPTION_BYSTORE		= 8,
		OPTION_QUIT			= 9
	};

	/* class Pull
	This class will hold all the code, in static functions,
	for collecting information from the terminal.
	*/
	class Pull
	{
	public:

		/* static char* PromptForInput(char* prompt) */
		/* Prints prompt, then gets the user input
		*/
		static char* Prompt(char* prompt);

		/* static int MainMenu() */
		/* Prompts for the users main menu choice, then returns the option
		*/
		static MainMenuOption MainMenu();
	};
}

#endif