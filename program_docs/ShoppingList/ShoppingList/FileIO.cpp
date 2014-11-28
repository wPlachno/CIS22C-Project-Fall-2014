/* Olivia Zhang
CIS 22C Fall 2014
Goel
Team 5 Project
*/

#include "fileio.h"
#include <iomanip>

//initialize static member - must be in cpp file to avoid multiple definitions
FileIO_TempFileData FileIO::f;

int FileIO::readFromFile(std::ifstream& infile)
{
	if (infile.eof() || !(getline(infile, f.groceryName)))
	{
		return FILE_ERROR_ADDING; //if nothing in file or can't read file into item, returns -1
	}

	std::size_t lastChar; //for size of string

	//reads in info into temporary variable
	std::getline(infile, f.price);
    if (f.price != "")
        f.douPrice = std::stod(f.price, &lastChar); //converts price to a double
    else
        f.douPrice = -1;
	
	std::getline(infile, f.storeName);
	
	std::getline(infile, f.quantity);
    if (f.quantity != "")
        f.intQuantity = std::stoi(f.quantity, &lastChar); //converts quantity to a int
    else
        f.intQuantity = 1; // default to 1
	
	std::getline(infile, f.date);

	return FILE_NO_ERROR; //returns 1 if no errors
}


int FileIO::loadFile(ShoppingList& list, const std::string& fileName)
{
	std::ifstream infile;

	infile.open(fileName);

	//checks if file opened
	if (!infile.is_open())
	{
		return FILE_ERROR_OPENING;  //returns 0 if file didn't open
	}

	//adds new record to list while there is still data to be read
	while (FILE_ERROR_ADDING != readFromFile(infile))
	{
		ListItem data(f.groceryName);
		data.setCost(f.douPrice);
		data.setStore(f.storeName);
		data.setQuantity(f.intQuantity);
		data.setDate(f.date);

		list.addRecord(data);
	}

	infile.close();

	return FILE_NO_ERROR;
}


int FileIO::writeToFile(ListItem& item, std::ofstream* outfile)
{
	if (!outfile)
		return ERROR_OUTFILE_NULL; //returns -1 if outfile points to null

	if (!(outfile->is_open()))
		return FILE_ERROR_OPENING; //returns 0 if file not opened
	else
	{
		*outfile << item.getName() << "\n"
			<< std::fixed << std::setprecision(2) << item.getCost() << "\n"
			<< item.getStore() << "\n"
			<< item.getQuantity() << "\n"
			<< item.getDate() << "\n";
			
		return FILE_NO_ERROR;  //returns 1 if no errors
	} //end if

}