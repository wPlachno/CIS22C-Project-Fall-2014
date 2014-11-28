/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "Output.h"
#include <iostream>
#include <iomanip>

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
   Replaces empty members with "N/A"
*/
void Output::PrintItem(ListItem& item)
{
	// Get strings 
	std::string name = item.getName();
	std::string date = item.getDate();
	std::string store = item.getStore();

	// Convert ints to strings
	int qty = item.getQuantity();
	double cost = item.getCost();
	std::string qtyStr = std::to_string(qty);

	// Check for empty
	if (date == "EMPTY DATE") { date = "N/A"; }
	if (store == "EMPTY STORE") { store = "N/A"; }
	if (qty == -1) { qtyStr = "N/A"; }

	// Output
	std::cout << "Name: " << name << std::endl;
	std::cout << "Date: " << date << std::endl;
	std::cout << "Quantity: " << qtyStr << std::endl;
	std::cout << "Cost: ";
	if (cost == -1) { std::cout << "N/A"; }
	else { std::cout << std::setprecision(2) << std::fixed << "$" << cost; }
	std::cout << std::endl << "Preferred Store: " << store << std::endl;
}