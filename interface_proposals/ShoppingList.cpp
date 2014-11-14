
#include <string>
#include <fstream>

//temporary
class BSTree;
class HTable;
class ListItem;



ShoppingList::ShoppingList():
itemCount(itemCount)
{

}


ShoppingList::~ShoppingList()
{}

ListItem* ShoppingList::findItemPtr(const std::string& name)
{
	return htable.search(name); //or bst
}


int ShoppingList::loadFromFile(const std::string& fileName)
{
	std::ifstream inFile;

	inFile.open(fileName);

	if(!inFile.is_open())
		return 0;

	return 1;
}



int ShoppingList::writeToFile(const std::string& fileName)
{
	std::ofstream outFile;

	outFile.open(fileName);

	if(!inFile.open(fileName))
		return 0;

	return 1;
}


int ShoppingList::addRecord(const ListItem& listItem)
{
	ListItem* newItem = new ListItem(listItem);


	//before we add to the hash table make sure that the item is unique in the bstree
	htable.addItem(newItem);


	return 0;
}

int ShoppingList::removeRecord(const std::string& name)
{
	ListItem* toDelete;

	toDelete = htable.removeItem(name);
	if(toDelete != nullptr)
		delete toDelete;
	else
		return 0;

	return 1;
}


ListItem ShoppingList::findRecord(const std::string& name) 
{
	ListItem* found = findItemPtr(name);


	/*
	if(!found)
		throw error
	*/

	return *found;
}



//print methods... separate?
// bool displayItem(const std::string& item);	
// void printTree(); 

void ShoppingList::printListHashSeq() const 
{
	htable.displayKeySeq();
}
// void printListByName();


// void printByStore(const std::string& storeName);


