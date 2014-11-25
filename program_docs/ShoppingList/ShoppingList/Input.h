#pragma once
// Created by Will Plachno

#ifndef USRPULL_H
#define USRPULL_H
#include <string>

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

		/* static const string StringPrompt(string prompt) */
		/* Prints prompt, then gets the user input
		*/
		static const std::string StringPrompt(const std::string prompt);

		/* static const double DoublePrompt(string prompt) */
		/* Prints prompt, then gets the user input
		*/
		static const double DoublePrompt(const std::string prompt);

		/* static int MenuPrompt(char* prompt) */
		/* Prints prompt, then gets the user input and converts to int
		*/
		static const int IntPrompt(std::string prompt);

		/* static int MainMenu() */
		/* Prompts for the users main menu choice, then returns the option
		*/
		static MainMenuOption GetMainMenuChoice();

	private:

		/* static int str2Int(char* charStr) */
		/* Takes the argument and converts it into an int. If error, return -1;
		*/
		static const int str2Int(const std::string charStr);

		/* static double str2Dbl(string charStr) */
		/* Takes the argument and converts it into a double. If error, return -1;
		*/
		static const double str2Dbl(const std::string charStr);

	};

#endif