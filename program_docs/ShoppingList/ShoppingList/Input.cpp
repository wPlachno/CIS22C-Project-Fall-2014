/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "Input.h"
#include "Output.h"
#include <iostream>
#include <iomanip>

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
const std::string Input::StringPrompt(const std::string prompt, const bool allowBlanks)
{
	bool answerIsEmpty;
	std::string answer;
	do {
		// Give the prompt
		std::cout << prompt << std::endl;

		// Get the answer
		std::getline(std::cin, answer);

		// Add spacing for looks
		std::cout << std::endl;

		// Check for empty string
		answerIsEmpty = answer.find_first_not_of(' ') == std::string::npos;

		// If we dont allow blanks, but we got them, 
		// send a message and reprompt
		if (!allowBlanks && answerIsEmpty)
		{
			std::cout << "You must answer the question to continue." << std::endl << std::endl;
		}
	} while (!allowBlanks && answerIsEmpty);

	// If we allow blanks, return it
	if (answerIsEmpty) return " ";

	// Trim whitespace
	int trimStringStart = answer.find_first_not_of(' ');
	int trimStringLength = answer.find_last_not_of(' ') + 1 - trimStringStart;
	answer = answer.substr(trimStringStart, trimStringLength);

	// Return the answer
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
	std::cout << std::endl;
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
	std::cout << std::endl;
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
		if (ans > 10 || ans < 1)
			Output::PrintError("Invalid choice (Input:GetMainMenuChoice:1)");
	} while (ans > 10 || ans < 1);
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
		name = Input::StringPrompt("Enter the name of the new item: ");
		
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
	std::string itemDateStr = Input::StringPrompt("When will you need this item by? ('_' to leave blank)", true);
	std::string itemStoreStr = Input::StringPrompt("Where do you buy this item? ('_' to leave blank)", true);
	int itemQty = Input::IntPrompt("How many do you need? ('_' to leave blank)");
	double itemCost = Input::DoublePrompt("What is the approximate cost of this item? ('_' to leave blank)");

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
		Output::PrintError("Item could not be added (Input:AddItem:1)");
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

			else // Unsuccessful deletion
				Output::PrintError("Item could not be removed (Input:DeleteItem:1)");
		}
		// Cancel the delete
		else {
			std::cout << name << " was not deleted." << std::endl;
		}
	}
	// Nothing to delete
	else {
		Output::PrintError("Item does not exist (Input:DeleteItem:2)");
	}
}

/* static void EditItem(ShoppingList&) */
/* A large function that contains the menu interface for the user
to edit a listItem in an existing shopping list.
*/
void Input::EditItem(ShoppingList& items)
{
	// Get the item name
	std::string name = Input::StringPrompt("Please enter the name of the item to edit:");

	// Check for existence
	ListItem* target = new ListItem();
	if (items.findRecord(name, *target))
	{
		int ans = 7;
		do {
			// Print item and menu
			Output::PrintItem(*target);
			std::cout << std::endl;
			std::cout << "What would you like to edit?" << std::endl;
			std::cout << "1. Name" << std::endl;
			std::cout << "2. Cost" << std::endl;
			std::cout << "3. Store" << std::endl;
			std::cout << "4. Quantity" << std::endl;
			std::cout << "5. Date" << std::endl;
			std::cout << "6. Return to Main Menu" << std::endl;

			// Get the users choice
			ans = Input::IntPrompt("Your Menu Choice: ");
			ListItem bufferItem;
			std::string newToken, currentToken;
			double newCost, currentCost;
			int newQty, currentQty;
			switch (ans) {

			case 1: // User intends to edit the name of the ListItem
				
				// Print current
				std::cout << "Current Name: " << target->getName() << std::endl;
				
				// Get new
				newToken = Input::StringPrompt("New Name: ");
				
				if (items.findRecord(newToken, bufferItem))
				{
					// If that name is already taken
					Output::PrintItem(bufferItem);
					Output::PrintError("This name is already taken (Input:EditItem:1)");
				}
				else {
					// Save changes to target
					bufferItem = *target;
					target = new ListItem(newToken, bufferItem.getCost(), bufferItem.getStore(), bufferItem.getQuantity(), bufferItem.getDate());
				}
				break;

			case 2: // User intends to edit the cost of the ListItem

				// Print current
				currentCost = target->getCost();
				std::cout << "Current Cost: ";
				if (currentCost > 0) { std::cout << '$' << currentCost << std::endl; }
				else { std::cout << "N/A" << std::endl; }

				// Get new
				newCost = Input::DoublePrompt("New Cost: ('_' for blank) ");

				// Save changes to target
				target->setCost(newCost);
				break;

			case 3: // User intends to edit the store of the ListItem

				// Print current
				currentToken = target->getStore();
				std::cout << "Current Store: ";
				if (currentToken != "EMPTY STORE") { std::cout << currentToken << std::endl; }
				else { std::cout << "N/A" << std::endl; }

				// Get new
				newToken = Input::StringPrompt("New Store: ('_' for blank) ", true);

				// Save changes to target
				target->setStore(newToken);
				break;

			case 4: // User intends to edit the quantity of the ListItem

				// Print current
				currentQty = target->getQuantity();
				std::cout << "Current Quantity: ";
				if (currentQty > 0) { std::cout << currentQty << std::endl; }
				else { std::cout << "1" << std::endl; }

				// Get new
				newQty = Input::IntPrompt("New Quantity: ('_' for blank) ");

				// Save changes to target
				target->setQuantity(newQty);
				break;

			case 5: // User intends to edit the date of the ListItem

				// Print current
				currentToken = target->getDate();
				std::cout << "Current Date: ";
				if (currentToken != "EMPTY DATE") { std::cout << currentToken << std::endl; }
				else { std::cout << "N/A" << std::endl; }

				// Get new
				newToken = Input::StringPrompt("New Date: ('_' for blank) ", true);

				// Save changes to target
				target->setDate(newToken);
				break;

			case 6: // User intends to exit the edit menu
				break;

			default: // Could not decipher the users intentions
				Output::PrintError("Invalid menu choice (Input:EditItem:2)");
				break;
			}
		} while (ans != 6);
		if (items.deleteRecord(name))
		{
			// After successful removal of previous version of item,
			// We must add the edited version.
			if (items.addRecord(*target))
			{
				// Successful save
				std::cout << std::endl << target->getName() << " was edited successfully." << std::endl;
			}
			else {
				Output::PrintError("Error saving the edits (Input:EditItem:3)");
			}
		}
		else {
			// There was an error removing the item to edit before reading it
			Output::PrintError("Error saving the edits (Input:EditItem:4)");
		}
	}
	else {
		// If the name does not exist.
		Output::PrintError("There is no item by that name (Input:EditItem:5)");
		return;
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