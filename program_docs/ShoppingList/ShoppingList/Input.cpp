/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "Input.h"
#include "Output.h"
#include <iostream>

/* Implementation file for Input class
Functions:
 - string StringPrompt(string prompt);
 - double DoublePrompt(string prompt);
 - int IntPrompt(string prompt);
 - MainMenuOption GetMainMenuChoice();
 - bool Validate(string);
 - int str2Int(string);
 - double str2Dbl(string);
*/


/* static const string StringPrompt(string prompt) */
/* Prints prompt, then gets the user input
*/
const std::string Input::StringPrompt(const std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
	std::getline(std::cin, answer);
	int trimStringStart = answer.find_first_not_of(' ');
	int trimStringLength = answer.find_last_not_of(' ') + 1 - trimStringStart;
	answer = answer.substr(trimStringStart, trimStringLength);
	return answer;

}

/* static const double DoublePrompt(string prompt) */
/* Prints prompt, then gets the user input
*/
const double Input::DoublePrompt(const std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
	std::cin >> answer;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	return str2Dbl(answer);
}

/* static int MenuPrompt(char* prompt) */
/* Prints prompt, then gets the user input and converts to int
*/
const int Input::IntPrompt(std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
	std::cin >> answer;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	return str2Int(answer);
}

/* static int MainMenu() */
/* Prompts for the users main menu choice, then returns the option
*/
MainMenuOption Input::GetMainMenuChoice()
{
	int ans = -1;
	do
	{
		ans = Input::IntPrompt("Your menu choice: ");
		if (ans > 9 || ans < 1)
			std::cout << "Invalid choice. (Valid: 1-9)" << std::endl;
	} while (ans > 9 || ans < 1);
	return (MainMenuOption)ans;
}

/* static void AddItem(ShoppingList&) */
/* Goes through the process of adding a new item.
Requires the ShoppingList in order to check for redundancy and add the item
*/
void Input::AddItem(ShoppingList& items)
{
	std::string name;
	bool nameExists = true;
	
	do { // Do loop for checking the name against existing items
		
		// Prompt the user for the name
		name = Input::StringPrompt("Enter the name of the new item");
		
		// Attempt to find the item in the shoppinglist
		ListItem subjectItem;
		nameExists = items.findRecord(name, subjectItem);

		if (nameExists)
		{
			// If we found an item with the same name, tell the user and print the item
			std::cout << name << " already exists." << std::endl;
			Output::PrintItem(subjectItem);

			// Ask the user if they still want to add a new item
			std::string contStr = Input::StringPrompt("Would you still like to add a new item? (Y/N)");
			if (!(Input::Validate(contStr)))
				return;
		}
	} while (nameExists);

	// Get the other fields for the item. '_' entries will be left blank
	// Note: int/dbl conversion from string auto fixes '_' to -1
	std::string itemDateStr = Input::StringPrompt("When did you last purchase this item? ('_' to leave blank)");
	std::string itemStoreStr = Input::StringPrompt("Where do you buy this item? ('_' to leave blank)");
	int itemQty = Input::IntPrompt("How many do you use? ('_' to leave blank)");
	double itemCost = Input::DoublePrompt("What is the average price of this item? ('_' to leave blank)");

	// Fix date and store if '_'
	if (itemDateStr == "_") { itemDateStr = "EMPTY DATE"; }
	if (itemStoreStr == "_") { itemStoreStr = "EMPTY STORE"; }

	// Generate the new item
	ListItem newItem(name, itemCost, itemStoreStr, itemQty, itemDateStr);

	if (items.addRecord(newItem))
	{
		// If the item was successfully added, tell the user and print the final item
		std::cout << name << " was successfully added to the shopping list." << std::endl;
		Output::PrintItem(newItem);
	}
	else {
		// If the item was not added successfully, tell the user 
		std::cout << name << " was not added to the list. Apparently there exists a similar item. Our apologies." << std::endl;
	}
}

/* static void DeleteItem(ShoppingList&) */
/* Prompts the user for a ListItem delete, then removes
it from the shopping list.
*/
void Input::DeleteItem(ShoppingList& items)
{
	// Prompt the user for the name
	std::string name = Input::StringPrompt("Please enter the name of the item to remove from the list:");

	// Check for existence
	ListItem thisItem;
	if (items.findRecord(name, thisItem))
	{
		// If it exists, Print it out
		std::cout << name << " was found: " << std::endl;
		Output::PrintItem(thisItem);

		// Confirm deletion
		std::string confirm = Input::StringPrompt("Are you sure you wish to delete this item?");
		if (Input::Validate(confirm))
		{
			// Confirmed Deletion
			if (items.deleteRecord(name))
				std::cout << name << " was successfully removed." << std::endl;
			// Unsuccessful deletion
			else
				std::cout << name << " could not be removed. It could not be found in the shopping list." << std::endl;
		}
		// Cancel the delete
		else {
			std::cout << name << " was not deleted." << std::endl;
		}
	}
	// Nothing to delete
	else {
		std::cout << name << " does not exist in the list." << std::endl;
	}
}

/* bool Validate(string) */
// Basically checks whether the argument is equivalent to 
// a positive statement, either "y", "Y", "yes", "Yes", "true", "True"
bool Input::Validate(std::string input)
{
	if (input == "y" || input == "Y")
		return true;
	else if (input == "yes" || input == "Yes")
		return true;
	else if (input == "true" || input == "True")
		return true;
	return false;
}

/* static int str2Int(char* charStr) */
/* Takes the argument and converts it into an int. If error, return -1;
*/
const int Input::str2Int(const std::string charStr)
{
	try {
		return std::stoi(charStr, nullptr);
	}
	catch (...) { return -1; }
}

/* static double str2Dbl(string charStr) */
/* Takes the argument and converts it into a double. If error, return -1;
*/
const double Input::str2Dbl(const std::string charStr)
{
	try {
		return std::stod(charStr, nullptr);
	}
	catch (...) { return -1; }
}