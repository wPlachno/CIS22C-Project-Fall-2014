/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List

#ifndef USRPULL_H
#define USRPULL_H
#include <string>
#include "ShoppingList.h"

/* enum MainMenuOptions */
/* Contains the choices for the main menu
*/
enum MainMenuOption {
	OPTION_ADD = 1,
	OPTION_DELETE = 2,
	OPTION_PRIMARYKEY = 3,
	OPTION_EDIT = 4,
	OPTION_HASHSEQ = 5,
	OPTION_KEYSEQ = 6,
	OPTION_BST = 7,
	OPTION_EFFICIENCY = 8,
	OPTION_BYSTORE = 9,
	OPTION_QUIT = 10
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
		In invalid case, returns -1
	*/
	static const double DoublePrompt(const std::string prompt);

	/* static int MenuPrompt(char* prompt) */
	/* Prints prompt, then gets the user input and converts to int
		In invalid case, returns -1
	*/
	static const int IntPrompt(std::string prompt);

	/* static int MainMenu() */
	/* Prompts for the users main menu choice, then returns the option
	*/
	static MainMenuOption GetMainMenuChoice();

	/* static void AddItem(ShoppingList&) */
	/* Goes through the process of adding a new item.
	   Requires the ShoppingList in order to check for redundancy and add the item
	*/
	static void AddItem(ShoppingList& items);

	/* static void DeleteItem(ShoppingList&) */
	/* Prompts the user for a ListItem delete, then removes
	   it from the shopping list.
	*/
	static void DeleteItem(ShoppingList& items);

	/* static void EditItem(ShoppingList&) */
	/* A large function that contains the menu interface for the user 
	   to edit a listItem in an existing shopping list.
	*/
	static void EditItem(ShoppingList& items);

	/* static bool Validate(string) */
	// Basically checks whether the argument is equivalent to 
	// a positive statement, either "y", "Y", "yes", "Yes", "true", "True"
	static bool Validate(std::string input);

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