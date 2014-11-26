/* Olivia Zhang
CIS 22C Fall 2014 Goel
Team 5 Project*/

#include "fileio.h"

bool FileIO::readFromFile(std::ifstream& infile)
{
	if (infile.eof() || !(getline(infile, f.groceryName)))
	{
		return false; //if nothing in file or can't read file into item, returns false
	}

	std::size_t lastChar; //for size of string

	//reads in info into temporary variable
	std::getline(infile, f.price);
	f.douPrice = std::stod(f.price, &lastChar); //converts price to a double
	std::getline(infile, f.storeName);
	std::getline(infile, f.quantity);
	f.intQuantity = std::stoi(f.quantity, &lastChar); //converts quantity to a int
	std::getline(infile, f.date);

	return true;
}


bool FileIO::loadFile(ShoppingList& list, const std::string& fileName)
{
	std::ifstream infile;

	infile.open(fileName);

	//checks if file opened
	if (!infile.is_open())
	{
		return false;
	}

	//adds new record to list while there is still data to be read
	while (readFromFile(infile))
	{
		ListItem data(f.groceryName);
		data.setCost(f.douPrice);
		data.setStore(f.storeName);
		data.setQuantity(f.intQuantity);
		data.setDate(f.date);

		list.addRecord(data);
	}

	infile.close();

	return true;
}

//from what does this file even read from??
bool FileIO::writeToFile(ListItem& item, const std::string& fileName)
{
	bool status;
	std::ofstream outfile;

	outfile.open(fileName, std::ofstream::out | std::ofstream::app);

	if (!(outfile.is_open()))
	{
		status = false;
	}
	else
	{
		outfile << item.getName() << "\n"
			<< item.getCost() << "\n"
			<< item.getStore() << "\n"
			<< item.getQuantity() << "\n"
			<< item.getDate() << "\n";

		status = true;
	} //end if

	outfile.close();

	return status;
}