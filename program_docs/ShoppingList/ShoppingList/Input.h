#pragma once
// Created by Will Plachno

#ifndef USRPULL_H
#define USRPULL_H

	/* enum MainMenuOptions */
	/* Contains the choices for the main menu
	*/
	enum MainMenuOption {
		OPTION_ADD = 1,
		OPTION_DELETE = 2,
		OPTION_PRIMARYKEY = 3,
		OPTION_HASHSEQ = 4,
		OPTION_KEYSEQ = 5,
		OPTION_BST = 6,
		OPTION_EFFICIENCY = 7,
		OPTION_BYSTORE = 8,
		OPTION_QUIT = 9
	};

	/* class Pull
	This class will hold all the code, in static functions,
	for collecting information from the terminal.
	*/
	class Input
	{
	public:

		/* static char* StringPrompt(char* prompt) */
		/* Prints prompt, then gets the user input
		*/
		static char* StringPrompt(char* prompt);

		/* static int MenuPrompt(char* prompt) */
		/* Prints prompt, then gets the user input and converts to int
		*/
		static int MenuPrompt(char* prompt);

		/* static int MainMenu() */
		/* Prompts for the users main menu choice, then returns the option
		*/
		static MainMenuOption GetMainMenuChoice();

	private:

		/* static int str2Int(char* charStr) */
		/* Takes the argument and converts it into an int. If error, return -1;
		*/
		static int str2Int(char* charStr);

		/* const int MAX_INPUT_CHARS_MENU */
		/* The maximum number of chars to read in during user input
		*/
		static const int MAX_INPUT_CHARS_MENU = 3;

		/* const int MAX_INPUT_CHARS_STRING */
		/* The maximum number of chars to read in during user input
		*/
		static const int MAX_INPUT_CHARS_STRING = 30;
	};

#endif