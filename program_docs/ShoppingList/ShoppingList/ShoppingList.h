
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include "ListItem.h"
#include "BSTree.h"
#include "HashTable.h"

enum
{
	SL_SUCCESS,
	SL_ERROR_FILE_NOOPEN,
	SL_ERROR_WRITE
};

class ShoppingList
{

private:
	int itemCount;
	BSTree<ListItem, std::string> bstree;
	HTable htable;


	//std::string fileName; //in a gui app this would be a better configuration


	ListItem* findRecordPtr(const std::string& name) const;
public:
	ShoppingList();
	~ShoppingList();

	int loadFromFile(const std::string& fileName);
	int writeToFile(const std::string& fileName) const;


	bool addRecord(const ListItem& toAdd); //copy the data into a new allocated item
	bool deleteRecord(const std::string& name); 
	bool findRecord(const std::string& name, ListItem& found) const; 
	bool exists(const std::string& name) const;

	int getItemCount() const;
	

	//print methods... separate?
	void displayItem(const std::string& item) const;
	void printTree() const;
	void printListHashSeq() const;
	void printListByName() const;
	void printHashTableEfficiency() const;

	//group defiined
	void printByStore(const std::string& storeName) const;



};




#endif
