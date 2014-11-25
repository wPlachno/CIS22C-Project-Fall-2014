// Created by Will Plachno

#include "Output.h"
#include <iostream>

/* Implementation file for Output class
Functions:
 - void PrintLanding()
 - void PrintMainMenu()
 - void PrintItem(ListItem& item)
*/

/* static void Landing() */
/* Prints the landing page for the application.
*/
void Output::PrintLanding()
{
	std::cout << "Hello and welcome to the Shopping List!" << std::endl;
	std::cout << "This program, written by Rob Hoyer, Andrew Light, Nicci Hart, Olivia Zhang, and Will Plachno, "
		<< "was designed to aid in the maintenance of the supply of common household items." << std::endl;
	std::cout << "Try it out!" << std::endl;
	system("pause");
}

/* static void MainMenu() */
/* Prints the Main Menu of the application
*/
void Output::PrintMainMenu()
{
	std::cout << "Main Menu choices: " << std::endl;
	std::cout << "1. Add an item to your shopping database." << std::endl;
	std::cout << "2. Delete an item from your shopping database." << std::endl;
	std::cout << "3. Find an item by item name (PRIMARY KEY)." << std::endl;
	std::cout << "4. List the database in hash sequence." << std::endl;
	std::cout << "5. List the database in alphabetical order." << std::endl;
	std::cout << "6. Print the indented list of items as they are stored (BST)." << std::endl;
	std::cout << "7. View details about the efficiency of the database." << std::endl;
	std::cout << "8. Print items by store." << std::endl;
	std::cout << "9. Quit the Shopping List." << std::endl;
}

/* static void PrintError(string errMsg) */
/* Prints an error line with the errMsg
*/
void Output::PrintError(const std::string errMsg)
{
	std::cout << "ERROR: " << errMsg << std::endl;
}

/* static void Item(ListItem* item) */
/* Prints the details of the item
*/
void Output::PrintItem(ListItem& item)
{
	std::cout << "Name: " << item.getName() << std::endl;
	std::cout << "Date: " << item.getDate() << std::endl;
	std::cout << "Quantity: " << item.getQuantity() << std::endl;
	std::cout << "Cost: $" << item.getCost() << std::endl;
	std::cout << "Preferred Store: " << item.getStore() << std::endl;
}