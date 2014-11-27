/* Olivia Zhang
CIS 22C Fall 2014 
Goel
Team 5 Project
*/

#ifndef FILEIO_H
#define FILEIO_H
#include <iostream>
#include <fstream>
#include <string>
#include "ListItem.h"
#include "ShoppingList.h"


//enum for possible errors
enum FileIOErrors {FILE_ERROR_OPENING, FILE_NO_ERROR, FILE_ERROR_ADDING = -1, ERROR_OUTFILE_NULL = -1};

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
	// Returns 1 if item read from file, -1 if not
	//**************************************************
	static int readFromFile(std::ifstream& infile);

	//**************************************************
	// loadFile function
	// Given a file name and ShoppingList item
	// Gives error message if file not opened
	// Creates a ListItem object & adds it to the list
	// Returns 1 if successfully added, 0 if not
	//**************************************************
	static int loadFile(ShoppingList& list, const std::string& fileName);

	//**************************************************
	// writeToFile function
	// Writes a set of data to file
	// Returns 1 if successful, 0 or -1 if not
	//**************************************************
	static int writeToFile(ListItem& item, std::ofstream outfile);

};



#endif FILEIO_H