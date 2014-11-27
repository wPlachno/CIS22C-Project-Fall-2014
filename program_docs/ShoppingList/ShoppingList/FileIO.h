/* Olivia Zhang
CIS 22C Fall 2014 Goel
Team 5 Project*/

#ifndef FILEIO_H
#define FILEIO_H
#include <iostream>
#include <fstream>
#include <string>
#include "ListItem.h"
#include "ShoppingList.h"


struct FileIO_TempFileData
{
	std::string groceryName, price, storeName = "blank";
	std::string quantity, date = "0";
	int intQuantity;
	double douPrice;
};

class FileIO
{
private:



	//struct as temporary variable
	static FileIO_TempFileData f;
public:
	//**************************************************
	// readFromFile function
	// Given ifstream object
	// Reads each set of data from file.
	// Returns true if item read from file, false if not
	//**************************************************
	static bool readFromFile(std::ifstream& infile);

	//**************************************************
	// loadFile function
	// Given a file name and ShoppingList item
	// Gives error message if file not opened
	// Creates a ListItem object & adds it to the list
	// Returns true if successfully added, false if not
	//**************************************************
	static bool loadFile(ShoppingList& list, const std::string& fileName);

	//**************************************************
	// writeToFile function
	// Writes a set of data to file
	// Returns true if successful, false if not
	//**************************************************
	static bool writeToFile(ListItem& item, const std::string& fileName);

};



#endif FILEIO_H