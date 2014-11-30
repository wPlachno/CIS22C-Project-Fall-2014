/******************************************************************************
 Implemenation of ShoppingList class.

 todo: if list is empty, then say that it is when printing full list.

 Author: Robert Hoyer
 ******************************************************************************/

#include "ShoppingList.h"
#include <fstream>
#include <iostream>
#include <functional>
#include <cassert>
#include <iomanip>
#include "FileIO.h"
#include "Output.h"
#include "util.h"



//todo: which has faster times for various actions: tree or hash table?  the one with faster time will be used for retrieval

/** Wrapper function for FileIO::writeToFile
*/

void fileWrite(ListItem& item, std::ofstream* outFile)
{
	int result = FileIO::writeToFile(item, outFile);
	//todo - throw exception
	assert(result != FILE_ERROR_OPENING);

	assert(result != ERROR_OUTFILE_NULL);


	//std::cout << "Write: " << item.getName() << " to file." << std::endl;
}



/** Prints a ListItem's name to stdout.  Intended for use with tree traversals.
@param item The ListItem to be printed.
 */

void printItemName(ListItem& item)
{
	std::cout << item.getName() << std::endl;
}


/** Prints a ListItem to stdout if it has a specific store assigned to it.  Intended for use with tree traversals.
@param item The ListItem to be tested and possibly printed.
@param storeName The name of the store the ListItem must be assigned to to be printed.
 */

void printIfStore(ListItem& item, const std::string& storeName)
{
	if(string_to_lower(item.getStore()) == storeName)
	{
		//std::cout << item.getName() << ", " << std::fixed << std::setprecision(2) << item.getCost() << ", " << item.getQuantity() << ", " << item.getDate() << std::endl;
		std::cout << item.getName() << std::endl;
	}
}


ShoppingList::ShoppingList():
itemCount(itemCount),
htable(), //todo: double check if this is right for initializer lists
bstree()
{}


ShoppingList::~ShoppingList()
{}


/** Find a record in the list and return it by pointer.
@param name The name of the record to be retrieved.
@return A pointer to the found record.  Returns nullptr if the record is not found.
 */

ListItem* ShoppingList::findRecordPtr(const std::string& name) const
{
	return bstree.get(name);
	//return htable.search(name); 
}

//todo: finish
/** Load the shopping list from a file.
 @param fileName The name of the file to load.
 @return SL_SUCCESS if success. SL_ERROR_FILE_NOOPEN if the file cannot be opended.
 */


int ShoppingList::loadFromFile(const std::string& fileName)
{
	int result = FileIO::loadFile(*this, fileName);
	if (FILE_ERROR_OPENING == result)
		return SL_ERROR_FILE_NOOPEN;
	else
		return SL_SUCCESS;
}


/** Write the contents of the list to a file.
@param fileName The name of the file to write to.
@return SL_SUCCESS on success.  SL_ERROR_FILE_NOOPEN if file cannot be opened.
*/

int ShoppingList::writeToFile(const std::string& fileName) const
{
	std::ofstream outFile;

	outFile.open(fileName);

	if (!outFile.is_open())
		return SL_ERROR_FILE_NOOPEN; //todo - meaningful return values

	auto visitFunc = std::bind(fileWrite, std::placeholders::_1, &outFile);


	bstree.breadthFirstTraversal(visitFunc);

	outFile.close();

	return SL_SUCCESS;
}


/** Add a record to the list.
@param toAdd ListItem to add to the list.
@return true if the item could be added, false an item with a matching key already exists in the list.
 */

bool ShoppingList::addRecord(const ListItem& toAdd)
{
	ListItem* newItem = new ListItem(toAdd);


	//before we add to the hash table make sure that the item is unique in the bstree
	if(!bstree.insert(newItem))
		return false;
	//htable.addItem(newItem);

	itemCount++;
	return true;
}


/** Remove a record from the list.
@param The name of the record to be removed.
@return true if the record was removed, false if the record could not be found.
*/


bool ShoppingList::deleteRecord(const std::string& name)
{
	ListItem* toDeleteTable, *toDeleteTree;

	//todo interface for this needs to be fixed
/*    toDeleteTable =*/ //htable.removeItem(name);
	toDeleteTree  = bstree.remove(name);

	if (toDeleteTree /*&& toDeleteTable*/)
	{
		delete toDeleteTree;
		itemCount--;
		return true;
	}
	else if(!toDeleteTree /*&& !toDeleteTable*/)
		return false;
	else
	{
		// we should never get here... this means that the table and the tree are out of sync.
		assert(0); 
		//if we do get here in production, handle this as gracefully as possible.
		if(toDeleteTree)
			delete toDeleteTree;
//        else
//            delete toDeleteTable;

		itemCount--;
		return true; //todo: should this be true or false?  or should we throw an out of sync error
					  
	}

}


/** Finds and retrieves a record from the list.
 @param name The name of the record to be found.
 @param found Will contain the data of the found record if it is found.
 @return true if the record was found, false otherwise.
 */

bool ShoppingList::findRecord(const std::string& name, ListItem& found) const
{
   ListItem* pFound = findRecordPtr(name);

	if(pFound)
	{
		found = *pFound;
		return true; 
	}
	else
		return false;

}


/** Check to see if an item exists in the list.
@param name The name of the item to search for
@return true if found, false otherwise.
*/

//todo: add this to presentation
bool ShoppingList::exists(const std::string& name) const
{
	return findRecordPtr(name);
}

/** Get the number of items in the list.
@return The number of items in the list.
 */
int ShoppingList::getItemCount() const
{
	return itemCount;
}



/** Find a record and print it to the screen.
@param item The name of the item to display.
 */
void ShoppingList::displayItem(const std::string& name) const
{
	ListItem* found = findRecordPtr(name);
 
	if (found)
	{
		Output::PrintItem(*found);
	}
	else
	{
		std::cout << "Item not found." << std::endl;
	}
}


/** Print the list as an indented tree.
 */

void ShoppingList::printTree() const
{
	bstree.printTree();
}


/** Print the list in hash key sequence to stdout.
 */

void ShoppingList::printListHashSeq() const
{
    htable.display();	//display key sequence was broken, did not perform as expected
}



/** Print the list in alphabetical order.
 */

void ShoppingList::printListByName() const
{
	bstree.inorderTraversal(printItemName);
}


/** Print each record in the list that has a given store assigned to it.
@param storeName The name of the store to be searched for.
 */

void ShoppingList::printByStore(const std::string& storeName) const
{
	auto visitFunc = std::bind(printIfStore, std::placeholders::_1, string_to_lower(storeName));

	bstree.inorderTraversal(visitFunc);
	//tree.breadthFirstTraversal(visitFunc);

}


/** Print efficiency statistics of the hash table.
*/

void ShoppingList::printHashTableEfficiency() const
{
	htable.PrintEff();
}




